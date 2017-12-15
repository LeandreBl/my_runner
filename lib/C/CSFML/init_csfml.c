/*
** init_csfml.c for init_csfml_structs in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 14:24:11 2017 Léandre Blanchard
** Last update Mon Nov 13 22:27:43 2017 Léandre Blanchard
*/

#include "csfml.h"

#include "colors.h"
#include "defines.h"

/*
** Create the sfRenderWindow object, with it's size and name
** return NULL on error
*/
sfRenderWindow          *create_window(char *name, int width,
				       int height, int bar)
{
  sfRenderWindow        *window;
  sfVideoMode           mode;

  if (bar == -1)
    bar = sfClose | sfResize | sfTitlebar;
  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, bar, NULL);
  return (window);
}
/*
** Create a sfUint8 array of pixels, of size width * heiht
** multiplied by 4, for R G B A.
** return NULL on error
*/
sfUint8                 *pixels_buffer(int width, int height)
{
  int			*pixels;
  int			i;

  i = 0;
  pixels = malloc(width * height * sizeof(int));
  while (i < width * height)
  {
    pixels[i] = 0;
    ++i;
  }
  return ((sfUint8 *)pixels);
}
/*
** Create a window_t object, all malloc and initialized with NULL
** for a Window names "CSFML" of size 1280 * 720
** you'll have to call iniwindow_t(720, 16 / 9, "CSFML)
** dim is the ratio of the screen, such as 16/9, 4/3 ...
** bar can be set so the window has no button on top of it, so you can create
** your owns ! by entering 0, other possibility are sfClose | sfResize | sfTitlebar
** return NULL on error
*/
window_t		*init_window(int height, float dim, char *name, int bar)
{
  window_t		*window;

  window = malloc(sizeof(window_t));
  if (window == NULL)
    return (NULL);
  window->height = height;
  window->width = window->height * dim;
  window->pixels = pixels_buffer(window->width, window->height);
  window->window = create_window(name,
				 window->width, window->height, bar);
  window->frame = my_calloc(sizeof(sprite_t));
  if (!window->pixels || !window->window || !window->pixels)
  {
    mdprintf(2, "[%sError%s] : Failed to create %s CSFML window\n",
	     BOLDRED, RESET, name);
    return (NULL);
  }
  window->frame->sprite = sfSprite_create();
  window->frame->texture = sfTexture_create(window->width, window->height);
  sfSprite_setTexture(window->frame->sprite, window->frame->texture, sfTrue);
  window->font = NULL;
  window->musics = NULL;
  return (window);
}

