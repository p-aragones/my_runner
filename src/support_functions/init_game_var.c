/*
** EPITECH PROJECT, 2021
** init_game_var
** File description:
** initialize game variables
*/

#include "game_variables.h"

void init_pos(game_variables_t *var)
{
    var->bear_pos.x = 20;
    var->bear_pos.y = 765;
    var->cb_pos.x = 400;
    var->cb_pos.y = 960;
    var->second_bg_pos.x = 1920;
    var->second_bg_pos.y = 0;
    var->first_bg_pos.x = 0;
    var->first_bg_pos.y = 0;
    var->stump_pos.x = 1920;
    var->stump_pos.y = 1012;
    var->font_pos.x = 935;
    var->font_pos.y = 540;
}

bg_pos_t init_bg_pos(bg_pos_t bg_pos)
{
    bg_pos.one.x = 0;
    bg_pos.one_two.x = 1920;
    bg_pos.two.x = 0;
    bg_pos.two_two.x = 1920;
    bg_pos.three.x = 0;
    bg_pos.three_two.x = 1920;
    bg_pos.four.x = 0;
    bg_pos.four_two.x = 1920;
    return (bg_pos);
}

scales_t init_scales(scales_t scales)
{
    scales.scale_bear.x = 6;
    scales.scale_bear.y = 6;
    scales.scale_cb.x = 2;
    scales.scale_cb.y = 2;
    scales.scale_sun.x = 7.058;
    scales.scale_sun.y = 6.75;
    scales.scale_m_one.x = 7.058;
    scales.scale_m_one.y = 6.75;
    scales.scale_m_two.x = 3.529;
    scales.scale_m_two.y = 6.65;
    scales.scale_trees.x = 3.529;
    scales.scale_trees.y = 6.75;
    scales.scale_stump_0.x = 0.05;
    scales.scale_stump_0.y = 0.05;
    scales.scale_stump_1.x = 0.05;
    scales.scale_stump_1.y = 0.12;
    return (scales);
}

game_variables_t init_game_var(game_variables_t var)
{
    var.seconds = 0;
    var.jump = 0;
    var.max = 0;
    var.finished_jump = 1;
    var.clock = sfClock_create();
    var.video_mode.width = 1920;
    var.video_mode.height = 1080;
    var.video_mode.bitsPerPixel = 32;
    var.score = 0;
    init_pos(&var);
    var.bg_pos = init_bg_pos(var.bg_pos);
    var.scales = init_scales(var.scales);
    var.window = sfRenderWindow_create(var.video_mode, "", sfFullscreen, NULL);
    var.buff_position = 0;
    var.text = sfText_create();
    var.font = sfFont_createFromFile("src/images/Pixeled.ttf");
    var.music = sfMusic_createFromFile("src/sound/ambient.ogg");
    return (var);
}