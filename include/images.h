/*
** EPITECH PROJECT, 2021
** IMAGES
** File description:
** images
*/

#ifndef IMAGES_H_
#define IMAGES_H_

#include <SFML/Graphics.h>

typedef struct sprites_s {
    sfSprite *bear_s;
    sfSprite *cb_s;
    sfSprite *stump;
    sfSprite *bg_one_s;
    sfSprite *bg_two_s;
    sfSprite *bg_three_s;
    sfSprite *bg_four_s;
    sfSprite *bg_two_two_s;
    sfSprite *bg_tredos_s;
    sfSprite *bg_fordos_s;
} sprites_t;

typedef struct textures_s {
    sfTexture *bear_t;
    sfTexture *cb_t;
    sfTexture *stump;
    sfTexture *bg_one_t;
    sfTexture *bg_two_t;
    sfTexture *bg_tre_t;
    sfTexture *bg_for_t;
} textures_t;

typedef struct rects_s {
    sfIntRect rect_bg;
    sfIntRect rect_bear;
    sfIntRect rect_cb;
} rects_t;

typedef struct images_s {
    sprites_t sprites;
    textures_t textures;
    rects_t rects;
} images_t;

#endif /* !IMAGES_H_ */
