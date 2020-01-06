/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for structure sim_info
*/

#ifndef INFO_H_
    #define INFO_H_

    #include <SFML/Graphics.h>

    typedef unsigned int uint;

    typedef struct sim_info {
        uint nb_planes;
        uint nb_planes_flying;
        uint nb_towers;
    } sim_info_t;
    typedef sim_info_t info_t;

    sim_info_t *sim_info_create(void);
    void sim_info_destroy(sim_info_t *);
#endif