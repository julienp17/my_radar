/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for structure image
*/

#ifndef IMAGE_H_
    #define IMAGE_H_

    #include <SFML/Graphics.h>

    typedef struct image {
        sfVector2f pos;
        sfTexture *texture;
        sfSprite *sprite;
    } image_t;

    image_t *image_create_from_file(unsigned int pos_x, unsigned int pos_y,
                                    char const *filepath);
    void image_destroy(image_t *image);
#endif