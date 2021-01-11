/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function
*/

#include "game_variables.h"
#include "images.h"
#include "runner.h"
#include "libmy.h"

void destroy_components(game_variables_t g, images_t i)
{
    sfClock_destroy(g.clock);
    sfRenderWindow_destroy(g.window);
    sfSprite_destroy(i.sprites.bear_s);
    sfSprite_destroy(i.sprites.cb_s);
    sfSprite_destroy(i.sprites.stump);
    sfSprite_destroy(i.sprites.bg_one_s);
    sfSprite_destroy(i.sprites.bg_two_s);
    sfSprite_destroy(i.sprites.bg_three_s);
    sfSprite_destroy(i.sprites.bg_four_s);
    sfSprite_destroy(i.sprites.bg_two_two_s);
    sfSprite_destroy(i.sprites.bg_tredos_s);
    sfSprite_destroy(i.sprites.bg_fordos_s);
    sfTexture_destroy(i.textures.bear_t);
    sfTexture_destroy(i.textures.cb_t);
    sfTexture_destroy(i.textures.stump);
    sfTexture_destroy(i.textures.bg_one_t);
    sfTexture_destroy(i.textures.bg_two_t);
    sfTexture_destroy(i.textures.bg_tre_t);
    sfTexture_destroy(i.textures.bg_for_t);
    sfMusic_destroy(g.music);
}

void manage_clock(game_variables_t *game_var, images_t *images)
{
    images->rects.rect_bear.left += 56;
    if (images->rects.rect_bear.left == 168)
    images->rects.rect_bear.left = 0;
    images->rects.rect_cb.left += 140;
    if (images->rects.rect_cb.left >= 900)
    images->rects.rect_cb.left = 355;
    sfClock_restart(game_var->clock);
}

int main_loop(game_variables_t game_var, images_t images)
{
    while (sfRenderWindow_isOpen(game_var.window)) {
        game_var.time = sfClock_getElapsedTime(game_var.clock);
        game_var.seconds = game_var.time.microseconds / 1000000.0;
        if (game_var.seconds > 0.08)
            manage_clock(&game_var, &images);
        display_sprite(&game_var, &images);
        while (sfRenderWindow_pollEvent(game_var.window, &game_var.event)) {
            analyse_events(&game_var, &images);
            if (game_var.event.type == sfEvtClosed ||
            game_var.event.key.code == sfKeyEscape)
                sfRenderWindow_close(game_var.window);
            if (game_var.event.key.code == sfKeySpace &&
            game_var.finished_jump == 1)
                game_var.finished_jump = 0;
        }
        if (game_var.score == 20)
            return (69);
        manage_jump(&game_var, &images);
    }
}

int read_map(int ac, char **av, game_variables_t *g)
{
    int error = 0;
    int i = 0;

    if (ac != 2)
        return (84);
    else
        error = read_file(av[1], g);
    if (error != 0)
        return (error);
    while (i < 20) {
        if (g->buff[i] != '1' && g->buff[i] != '0') {
            my_putstr("\ninvalid map\n");
            return (84);
        }
        i++;
    }
    return (0);
}

int main (int ac, char **av)
{
    game_variables_t game_var = init_game_var(game_var);
    images_t images = init_images(images);
    if (read_map(ac, av, &game_var) != 0)
        return (84);
    game_setup(game_var, images);
    sfRenderWindow_setFramerateLimit(game_var.window, 30);
    if (main_loop(game_var, images) == 69)
        my_putstr("YOU ESCAPED THE BEAR\n");
    destroy_components(game_var, images);
    return (0);
}