/*
** free.c for my_csfml in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr  5 14:48:58 2017 Léandre Blanchard
** Last update Mon Nov 13 21:53:54 2017 Léandre Blanchard
*/

#include "csfml.h"

/*
** When you are loading 5 sprites but with 1 image, such as
** different movement of a player, but cut into pieces,
** so you just loaded 1 texture for the wholes sprites
** which you cut into pieces after, well this fonction
** only frees the texture, and then all the sprites
** replace the freed pointers by NULL
*/
void		free_sprites_only(sprite_t **sprites)
{
  int		i;

  i = 0;
  if (sprites != NULL)
    {
      sfTexture_destroy(sprites[0]->texture);
      while (sprites[i] != NULL)
	{
	  if (sprites[i]->sprite != NULL)
	    sfSprite_destroy(sprites[i]->sprite);
	  sfree(&sprites[i++]);
	}
      sfree(&sprites);
    }
}
/*
** Entirely free a sprite_t ** using a call to free_sprite
** and replace the ptr freed, by NULL
*/
void		free_sprites(sprite_t **sprites)
{
  int		i;

  i = 0;
  if (sprites != NULL)
    {
      while (sprites[i] != NULL)
	{
	  free_sprite(sprites[i]);
	  i++;
	}
      sfree(&sprites);
    }
}
/*
** Frees all sfMusics contained in a sfMusics **
** replaces freed pointers by NULL
*/
void		free_musics(sfMusic **musics)
{
  int		i;

  i = 0;
  if (musics != NULL)
    {
      while (musics[i] != NULL)
	{
	  sfMusic_destroy(musics[i]);
	  i++;
	}
      sfree(&musics);
    }
}
/*
** Free a single sprite_t, then replace it by NULL
*/
void            free_sprite(sprite_t *sprite)
{
  if (sprite != NULL)
    {
      if (sprite->sprite != NULL)
	sfSprite_destroy(sprite->sprite);
      if (sprite->texture != NULL)
	sfTexture_destroy(sprite->texture);
      sfree(&sprite->name);
      sfree(&sprite);
    }
}
/*
** Using a lot of calls to above fonctions,
** frees the whole window_t structure
*/
void            free_window(window_t *window)
{
  if (window != NULL)
    {
      if (window->window != NULL)
	sfRenderWindow_destroy(window->window);
      sfree(&window->pixels);
      sfree(&window->font);
      free_musics(window->musics);
      if (window->frame != NULL)
      {
	sfTexture_destroy(window->frame->texture);
	sfSprite_destroy(window->frame->sprite);
      }
      sfree(&window->frame);
      sfree(&window);
    }
}
