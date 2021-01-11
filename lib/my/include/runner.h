/*
** EPITECH PROJECT, 2021
** RUNNER
** File description:
** RUNNER
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include "game_variables.h"
#include "images.h"

void game_setup(game_variables_t, images_t);
game_variables_t init_game_var(game_variables_t);
images_t init_images(images_t);
void display_sprite(game_variables_t *, images_t *);
void analyse_events(game_variables_t *, images_t *);
void manage_jump(game_variables_t *, images_t *);
int read_file(char *, game_variables_t *);
void display_sprite(game_variables_t *, images_t *);
void draw_sprites(game_variables_t *, images_t *);
void set_textures_sprites(game_variables_t *, images_t *);
char *my_int_to_str(int);

#endif /* !RUNNER_H_ */
