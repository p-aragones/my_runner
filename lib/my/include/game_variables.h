/*
** EPITECH PROJECT, 2020
** hunter.h
** File description:
** hunter header file
*/

#ifndef GAME_VARIABLES_H_
#define GAME_VARIABLES_H_

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct bg_pos_t {
    sfVector2f one;
    sfVector2f two;
    sfVector2f three;
    sfVector2f four;
    sfVector2f one_two;
    sfVector2f two_two;
    sfVector2f three_two;
    sfVector2f four_two;
} bg_pos_t;

typedef struct scales_s {
    sfVector2f scale_sun;
    sfVector2f scale_m_one;
    sfVector2f scale_m_two;
    sfVector2f scale_trees;
    sfVector2f scale_bear;
    sfVector2f scale_cb;
    sfVector2f scale_stump_0;
    sfVector2f scale_stump_1;
} scales_t;

typedef struct game_variables_s {
    bg_pos_t bg_pos;
    scales_t scales;
    sfVector2f cb_pos;
    sfVector2f bear_pos;
    sfVector2f first_bg_pos;
    sfVector2f second_bg_pos;
    sfVector2f font_pos;
    sfVector2f stump_pos;
    sfMusic *music;
    sfTime time;
    sfFont *font;
    sfClock *clock;
    sfEvent event;
    sfVideoMode video_mode;
    sfRenderWindow *window;
    float seconds;
    int jump;
    int finished_jump;
    int max;
    int score;
    char *buff;
    int buff_position;
    sfText *text;
} game_variables_t;

#endif /* !HUNTER_H_ */
