/*
** EPITECH PROJECT, 2021
** move_sprites.c
** File description:
** move sprites and display them
*/

#include "runner.h"
#include "images.h"
#include "game_variables.h"
#include "libmy.h"
#include <stdio.h>

void move_positions(game_variables_t *g)
{
    g->bg_pos.two.x = g->bg_pos.two.x - 1;
    g->bg_pos.three.x = g->bg_pos.three.x - 2;
    g->bg_pos.four.x = g->bg_pos.four.x - 5;
    g->bg_pos.two_two.x = g->bg_pos.two_two.x - 1;
    g->bg_pos.three_two.x = g->bg_pos.three_two.x - 2;
    g->bg_pos.four_two.x = g->bg_pos.four_two.x - 5;
    g->stump_pos.x = g->stump_pos.x - 50;
}

void hit_player(game_variables_t *g, images_t *i)
{
    g->cb_pos = sfSprite_getPosition(i->sprites.cb_s);
    if ((400 >= g->stump_pos.x - 90 && 400 <= g->stump_pos.x + 90)
&& (g->cb_pos.y + 78 >= g->stump_pos.y)) {
        my_putstr("YOU DIED AND THE BEAR ATE YOU :(\n");
        sfRenderWindow_close(g->window);
    }
}

void change_stump(game_variables_t *g, images_t *i)
{
    hit_player(g, i);
    if (g->stump_pos.x <= 280) {
        g->stump_pos.x = 1940;
        if (g->buff[g->buff_position] == '0') {
            g->stump_pos.y = 1012;
            sfSprite_setScale(i->sprites.stump, g->scales.scale_stump_0);
        } else {
            g->stump_pos.y = 920;
            sfSprite_setScale(i->sprites.stump, g->scales.scale_stump_1);
        }
        g->buff_position++;
        g->score++;
    }
    sfSprite_setPosition(i->sprites.stump, g->stump_pos);
}

void parallax_scrolling(game_variables_t *g, images_t *i)
{
    if (g->bg_pos.two.x == 0)
        g->bg_pos.two_two.x = 1920;
    sfSprite_setPosition(i->sprites.bg_two_two_s, g->bg_pos.two_two);
    if (g->bg_pos.three.x == 0)
        g->bg_pos.three_two.x = 1920;
    sfSprite_setPosition(i->sprites.bg_tredos_s, g->bg_pos.three_two);
    if (g->bg_pos.four.x == 0)
        g->bg_pos.four_two.x = 1920;
    sfSprite_setPosition(i->sprites.bg_fordos_s, g->bg_pos.four_two);
    if (g->bg_pos.two_two.x == 0)
        g->bg_pos.two.x = 1920;
    sfSprite_setPosition(i->sprites.bg_two_s, g->bg_pos.two);
    if (g->bg_pos.three_two.x == 0)
        g->bg_pos.three.x = 1920;
    sfSprite_setPosition(i->sprites.bg_three_s, g->bg_pos.three);
    if (g->bg_pos.four_two.x == 0)
        g->bg_pos.four.x = 1920;
    sfSprite_setPosition(i->sprites.bg_four_s, g->bg_pos.four);
}

void display_sprite(game_variables_t *g, images_t *i)
{
    move_positions(g);
    change_stump(g, i);
    parallax_scrolling(g, i);
    sfRenderWindow_clear(g->window, sfBlack);
    set_textures_sprites(g, i);
    draw_sprites(g, i);
    sfText_setString(g->text, my_int_to_str(g->score));
    sfText_setPosition(g->text, g->font_pos);
    sfText_setFont(g->text, g->font);
    sfRenderWindow_drawText(g->window, g->text, NULL);
    sfRenderWindow_display(g->window);
}