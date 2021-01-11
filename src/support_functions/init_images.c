/*
** EPITECH PROJECT, 2021
** init_images
** File description:
** initialize images
*/

#include "images.h"

sprites_t init_sprites(sprites_t sprites)
{
    sprites.bg_one_s = sfSprite_create();
    sprites.bg_two_s = sfSprite_create();
    sprites.bg_three_s = sfSprite_create();
    sprites.bg_four_s = sfSprite_create();
    sprites.bg_two_two_s = sfSprite_create();
    sprites.bg_tredos_s = sfSprite_create();
    sprites.bg_fordos_s = sfSprite_create();
    sprites.cb_s = sfSprite_create();
    sprites.bear_s = sfSprite_create();
    sprites.stump = sfSprite_create();
    return (sprites);
}

textures_t init_textures(textures_t t)
{
    t.bg_one_t = sfTexture_createFromFile("src/images/bg_one.png", NULL);
    t.bg_two_t = sfTexture_createFromFile("src/images/bg_two.png", NULL);
    t.bg_tre_t = sfTexture_createFromFile("src/images/bg_three.png", NULL);
    t.bg_for_t = sfTexture_createFromFile("src/images/bg_four.png", NULL);
    t.bear_t = sfTexture_createFromFile("src/images/bear.png", NULL);
    t.cb_t = sfTexture_createFromFile("src/images/cb.png", NULL);
    t.stump = sfTexture_createFromFile("src/images/stump.png", NULL);
    return (t);
}

rects_t init_rects(rects_t rect)
{
    rect.rect_bear.left = 0;
    rect.rect_bear.top = 336;
    rect.rect_bear.width = 56;
    rect.rect_bear.height = 56;
    rect.rect_cb.left = 345;
    rect.rect_cb.top = 300;
    rect.rect_cb.width = 78;
    rect.rect_cb.height = 78;
    return (rect);
}

images_t init_images(images_t image)
{
    image.sprites = init_sprites(image.sprites);
    image.textures = init_textures(image.textures);
    image.rects = init_rects(image.rects);
    return (image);
}