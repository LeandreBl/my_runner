/*
** my_put_png.c for put_png in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 13:56:53 2017 Léandre Blanchard
** Last update Mon Jul 17 15:24:40 2017 Léandre Blanchard
*/

#include "csfml.h"

/*
** Put an the image contained in the "name" file on the screen,
** this fonction does not need to be free or create a pointer
** to a sprite_t, but the call is slower than a pusprite_t
** because the image need to be re-loaded whenether the fonction
** is called
** this fonction does not return
*/
void            put_png(window_t *window, sfVector2f pos,
			const char *name)
{
  sfSprite      *sprite;
  sfTexture     *texture;

  texture = sfTexture_createFromFile(name, NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setPosition(sprite, pos);
  sfRenderWindow_drawSprite(window->window, sprite, NULL);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
}
/*
** Does the exact same job as above, but resize the image
*/
void            put_png_resize(window_t *window, sfVector2f pos,
			       const char *name, sfVector2f resize)
{
  sfSprite      *sprite;
  sfTexture     *texture;

  texture = sfTexture_createFromFile(name, NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setScale(sprite, resize);
  sfSprite_setPosition(sprite, pos);
  sfRenderWindow_drawSprite(window->window, sprite, NULL);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
}
