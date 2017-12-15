/*
** create_sprite.c for create_sprite in /home/leandre/Rushs/scroller
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Apr  2 12:20:16 2017 Léandre Blanchard
** Last update Mon Nov 13 21:04:08 2017 Léandre Blanchard
*/

#include "csfml.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

/*
** Create a sprite from <pathname> with the texture at <rect>
** Return NULL on Error
*/
sprite_t		*create_sprite_rect(const char *pathname,
					    const sfIntRect area)
{
  sprite_t              *sprite;

  mprintf("[%sInfo%s] Opening %s%s%s\n",
	  YELLOW, RESET, CYAN, pathname, RESET);
  sprite = my_calloc(sizeof(sprite_t));
  if (sprite == NULL)
    return (NULL);
  if (area.top == -1 && area.left == -1 &&
      area.width == -1 && area.height == -1)
    sprite->texture = sfTexture_createFromFile(pathname, NULL);
  else
    sprite->texture = sfTexture_createFromFile(pathname, &area);
  sprite->sprite = sfSprite_create();
  if (sprite->texture == NULL || sprite->sprite == NULL)
  {
    sfTexture_destroy(sprite->texture);
    sfree(&sprite);
    return (NULL);
  }
  sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
  sprite->name = my_strdup(pathname);
  while (nb_of(sprite->name, '/') != 0)
    shift_left(sprite->name, 1);
  return (sprite);
}

/*
** add the sprite_t "sprite" on the window_t "window" at the pos.x, pos.y
** will need a call to window_refresh(window) to display it
*/
void			put_sprite(window_t *window, sprite_t *sprite,
				   sfVector2f pos)
{
  if (sprite == NULL || sprite->sprite == NULL || sprite->texture == NULL)
  {
    mdprintf(2, "[%sWarning%s] PutSprite : NULL sprite\n", GREEN, RESET);
    return;
  }
  sfSprite_setPosition(sprite->sprite, pos);
  sfSprite_setScale(sprite->sprite, xy_vectorf(1, 1));
  sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
}
/*
** same as above, but can be resized, for example, resize = { 2, 2 }
** will display the sprite as 2 as large as normal
** does not have any conflict with fonction above
*/
void			put_sprite_resize(window_t *window,
					  sprite_t *sprite,
					  sfVector2f pos,
					  sfVector2f resize)
{
  if (sprite == NULL)
  {
    mdprintf(2, "[%sWarning%s] PutSprite : NULL sprite\n", GREEN, RESET);
    return;
  }
  sfSprite_setScale(sprite->sprite, resize);
  sfSprite_setPosition(sprite->sprite, pos);
  sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
}
/* 
** primary sprite_t fonction, create a sprite_t from a file
** getting texture in sprite_t->texture and sprite in sprite_t->sprite
** return NULL on ERROR, and sprite_t malloced on SUCCESS
*/
sprite_t		*create_sprite(const char *pathname)
{
  return (create_sprite_rect(pathname, simple_int_rect(-1, -1, -1, -1)));
}
/*
** create an array of sprite_t, ended by a NULL ptr
** then a call to cerate_sprite must be usefull to fill it
*/
sprite_t        **create_sprites(int nb)
{
  int           i;
  sprite_t      **sprites;

  i = 0;
  sprites = my_calloc(sizeof(sprite_t *) * (nb + 1));
  if (sprites == NULL)
    return (NULL);
  while (i < nb)
  {
    sprites[i] = my_calloc(sizeof(sprite_t));
    if (sprites[i] == NULL)
      return (NULL);
    ++i;
  }
  return (sprites);
}
