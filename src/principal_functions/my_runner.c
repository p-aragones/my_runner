/*
** EPITECH PROJECT, 2020
** create_window
** File description:
** create and display a window
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "runner.h"
#include "game_variables.h"
#include "images.h"
#include "libmy.h"

void manage_jump(game_variables_t *g, images_t *i)
{
    sfVector2f position = sfSprite_getPosition(i->sprites.cb_s);

    if (g->finished_jump == 0 && position.y > 700 && g->max == 0) {
        position.y = position.y - 20;
        sfSprite_setPosition(i->sprites.cb_s, position);
    }
    if (position.y == 720)
        g->max = 1;
    if (g->max == 1) {
        position.y = position.y + 15;
        sfSprite_setPosition(i->sprites.cb_s, position);
    }
    if (position.y == 960 && g->finished_jump == 0) {
        g->finished_jump = 1;
        g->max = 0;
    }
}

void set_textures_sprites(game_variables_t *g, images_t *i)
{
    sfSprite_setTextureRect(i->sprites.bear_s, i->rects.rect_bear);
    sfSprite_setTextureRect(i->sprites.cb_s, i->rects.rect_cb);
    sfSprite_setTexture(i->sprites.bear_s, i->textures.bear_t, sfFalse);
    sfSprite_setTexture(i->sprites.bg_one_s, i->textures.bg_one_t, sfFalse);
    sfSprite_setTexture(i->sprites.bg_two_s, i->textures.bg_two_t, sfFalse);
    sfSprite_setTexture(i->sprites.bg_three_s, i->textures.bg_tre_t, sfFalse);
    sfSprite_setTexture(i->sprites.bg_four_s, i->textures.bg_for_t, sfFalse);
    sfSprite_setTexture(i->sprites.bg_two_two_s, i->textures.bg_two_t, sfFalse);
    sfSprite_setTexture(i->sprites.bg_tredos_s, i->textures.bg_tre_t, sfFalse);
    sfSprite_setTexture(i->sprites.bg_fordos_s, i->textures.bg_for_t, sfFalse);
    sfSprite_setTexture(i->sprites.cb_s, i->textures.cb_t, sfFalse);
}

void draw_sprites(game_variables_t *g, images_t *i)
{
    sfRenderWindow_drawSprite(g->window, i->sprites.bg_one_s, NULL);
    sfRenderWindow_drawSprite(g->window, i->sprites.bg_two_s, NULL);
    sfRenderWindow_drawSprite(g->window, i->sprites.bg_two_two_s, NULL);
    sfRenderWindow_drawSprite(g->window, i->sprites.bg_three_s, NULL);
    sfRenderWindow_drawSprite(g->window, i->sprites.bg_tredos_s, NULL);
    sfRenderWindow_drawSprite(g->window, i->sprites.bg_four_s, NULL);
    sfRenderWindow_drawSprite(g->window, i->sprites.bg_fordos_s, NULL);
    sfRenderWindow_drawSprite(g->window, i->sprites.bear_s, NULL);
    sfRenderWindow_drawSprite(g->window, i->sprites.cb_s, NULL);
    sfRenderWindow_drawSprite(g->window, i->sprites.stump, NULL);
}

void manage_mouse_click(sfMouseButtonEvent event)
{
    int x = event.x;
    int y = event.y;
}

void analyse_events(game_variables_t *g, images_t *i)
{
    if (g->event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(g->event.mouseButton);
}