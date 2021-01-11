/*
** EPITECH PROJECT, 2020
** game_setup.c
** File description:
** initial game setup
*/

#include "runner.h"

void set_textures(game_variables_t g, images_t i)
{
    sfSprite_setTextureRect(i.sprites.bear_s, i.rects.rect_bear);
    sfSprite_setTextureRect(i.sprites.cb_s, i.rects.rect_cb);
    sfSprite_setTexture(i.sprites.bear_s, i.textures.bear_t, sfFalse);
    sfSprite_setTexture(i.sprites.bg_one_s, i.textures.bg_one_t, sfFalse);
    sfSprite_setTexture(i.sprites.bg_two_s, i.textures.bg_two_t, sfFalse);
    sfSprite_setTexture(i.sprites.bg_three_s, i.textures.bg_tre_t, sfFalse);
    sfSprite_setTexture(i.sprites.bg_four_s, i.textures.bg_for_t, sfFalse);
    sfSprite_setTexture(i.sprites.bg_two_two_s, i.textures.bg_two_t, sfFalse);
    sfSprite_setTexture(i.sprites.bg_tredos_s, i.textures.bg_tre_t, sfFalse);
    sfSprite_setTexture(i.sprites.bg_fordos_s, i.textures.bg_for_t, sfFalse);
    sfSprite_setTexture(i.sprites.cb_s, i.textures.cb_t, sfFalse);
    sfSprite_setTexture(i.sprites.stump, i.textures.stump, sfFalse);
}

void set_scales(game_variables_t g, images_t i)
{
    sfSprite_setScale(i.sprites.bg_one_s, g.scales.scale_sun);
    sfSprite_setScale(i.sprites.bg_two_s, g.scales.scale_m_one);
    sfSprite_setScale(i.sprites.bg_three_s, g.scales.scale_m_two);
    sfSprite_setScale(i.sprites.bg_four_s, g.scales.scale_trees);
    sfSprite_setScale(i.sprites.bg_two_two_s, g.scales.scale_m_one);
    sfSprite_setScale(i.sprites.bg_tredos_s, g.scales.scale_m_two);
    sfSprite_setScale(i.sprites.bg_fordos_s, g.scales.scale_trees);
    sfSprite_setScale(i.sprites.bear_s, g.scales.scale_bear);
    sfSprite_setScale(i.sprites.cb_s, g.scales.scale_cb);
    sfSprite_setScale(i.sprites.stump, g.scales.scale_stump_0);
}

void set_positions(game_variables_t g, images_t i)
{
    sfSprite_setPosition(i.sprites.bear_s, g.bear_pos);
    sfSprite_setPosition(i.sprites.cb_s, g.cb_pos);
    sfSprite_setPosition(i.sprites.bg_two_s, g.first_bg_pos);
    sfSprite_setPosition(i.sprites.bg_tredos_s, g.first_bg_pos);
    sfSprite_setPosition(i.sprites.bg_fordos_s, g.first_bg_pos);
    sfSprite_setPosition(i.sprites.bg_two_two_s, g.second_bg_pos);
    sfSprite_setPosition(i.sprites.bg_tredos_s, g.second_bg_pos);
    sfSprite_setPosition(i.sprites.bg_fordos_s, g.second_bg_pos);
    sfSprite_setPosition(i.sprites.stump, g.stump_pos);
}

void game_setup(game_variables_t g, images_t i)
{
    sfMusic_play(g.music);
    sfMusic_setVolume(g.music, 100);
    sfMusic_setLoop(g.music, sfTrue);
    set_textures(g, i);
    set_scales(g, i);
    set_positions(g, i);
}