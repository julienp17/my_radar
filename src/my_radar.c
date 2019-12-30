/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** simulation
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "usage.h"
#include "my_radar.h"
#include "sim.h"
#include "draw.h"
#include "events.h"
#include "utils.h"
#include "collisions.h"

int my_radar(char const *script_path)
{
    sim_t *sim = sim_create_from_script(script_path);
    sfSprite *sprite = sfSprite_create();

    if (sim == NULL)
        return (MY_EXIT_FAILURE);
    sfSprite_setPosition(sprite, (sfVector2f) {0, 0});
    sfSprite_setTexture(sprite, sim->night_texture, sfTrue);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 0, sim->window->height});
    while (sfRenderWindow_isOpen(sim->window->window)) {
        poll_events(sim);
        if (!(sim->is_paused)) {
            sfRenderWindow_clear(sim->window->window, sfWhite);
            simulation_loop(sim, sprite);
            sfRenderWindow_display(sim->window->window);
        }
    }
    sim_destroy(sim);
    return (MY_EXIT_SUCCESS);
}

void simulation_loop(sim_t *sim, sfSprite *sprite)
{
    static float speed = 0.0;
    static sfBool is_day = sfTrue;
    unsigned int c_time = sfTime_asSeconds(sfClock_getElapsedTime(sim->clock));

    if (speed > 2560.0) {
        if (is_day) {
            sfSprite_setTexture(sprite, sim->window->bg_texture, sfFalse);
            sfSprite_setTexture(sim->window->bg_sprite, sim->night_texture, sfFalse);
            is_day = sfFalse;
        } else {
            sfSprite_setTexture(sim->window->bg_sprite, sim->window->bg_texture, sfFalse);
            sfSprite_setTexture(sprite, sim->night_texture, sfFalse);
            is_day = sfTrue;
        }
        speed = 0.0;
    }
    speed++;
    quadtree_clear(sim->quadtree);
    insert_planes_in_quadtree(sim->planes, sim->quadtree, c_time);
    sfRenderWindow_drawSprite(sim->window->window,sim->window->bg_sprite, NULL);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, speed, sim->window->height});
    sfRenderWindow_drawSprite(sim->window->window, sprite, NULL);
    draw_towers(sim->window->window, sim->towers);
    for (unsigned int i = 0 ; sim->planes[i] ; i++)
        plane_loop(sim->planes[i], sim, c_time);
    // draw_quadtree(sim->window->window, sim->quadtree);
}
    #include <stdio.h>
void plane_loop(plane_t *plane, sim_t *sim, unsigned int c_time)
{
    if (plane->delay > c_time)
        return;
    if (plane_collided(plane, sim->towers, sim->quadtree, c_time))
        return;
    sfRenderWindow_drawSprite(sim->window->window, plane->sprite, NULL);
    sfRenderWindow_drawRectangleShape(sim->window->window,plane->outline, NULL);
    plane_move(plane, plane->path->step);
    printf("%f\t%f\n", plane->path->pos.x, plane->path->pos.y);
    if (pos_are_near(plane->path->pos, plane->path->end, 10.0))
        plane_reset_random(plane, sim->towers, c_time);
}

void insert_planes_in_quadtree(plane_t **planes, quadtree_t *quadtree,
                            unsigned int c_time)
{
    for (unsigned int i = 0 ; planes[i] ; i++)
        if (planes[i]->delay <= c_time)
            quadtree_insert(quadtree, planes[i]);
}