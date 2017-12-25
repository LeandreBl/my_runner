/*
** csfml.h for csfml_h_lib in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 13:58:23 2017 Léandre Blanchard
** Last update Mon Dec 25 19:29:36 2017 Léandre Blanchard
*/

#ifndef MY_CSFML_H_
# define MY_CSFML_H_

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __horriblethingwithemacs
}
#endif

# include <SFML/Audio.h>
# include <SFML/Network.h>
# include <SFML/Graphics.h>
# include <SFML/System.h>
# include <SFML/Window.h>

# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# include "my.h"

# define KP(key)	(sfKeyboard_isKeyPressed(key))
# define MP		(sfMouse_isButtonPressed(sfMouseLeft))
# define ORIGIN		(xy_vectorf(0, 0))

/*
** Simple sprite structure, saving the texture and the sprite,
** can be easely used with pusprite_t, and create via a call
** of create_sprite(<pathname>)
*/
struct			sprite_s
{
  char			*name;
  sfSprite              *sprite;
  sfTexture             *texture;
};

/*
** A window structure, containing it's size,
** the position of the mouse using pos_mouse
** a char * containing the name of the font for
** put_text fcontions
** an array of pixels, of the size of the window
** an array of sfMusics *ptr
** a texture linked to the array of pixels, same for the sprite
*/
struct			window_s
{
  int			width;
  int			height;
  sfVector2i		mouse;
  sfRenderWindow	*window;
  sfUint8		*pixels;
  char			*font;
  sfMusic		**musics;
  struct sprite_s      	*frame;
};

typedef int (* evt_t)(struct window_s *window,
		      sfEvent *event, void *data);

struct			evtptr_s
{
  sfEventType		type;
  evt_t			fction;
};

struct			sfbutton_s
{
  struct sprite_s	*sprite;
  char			*name;
  sfVector2f		pos;
  sfVector2f		size;
  int			(*fction)(void *data, struct sfbutton_s *this);
};

typedef struct window_s window_t;
typedef struct sprite_s sprite_t;
typedef struct sfbutton_s sfbutton_t;
typedef struct evtptr_s evtptr_t;

int		load_script(const char *pathname, const char *script,
			    sprite_t ***ptr);

sfIntRect	simple_int_rect(int x, int y, int width, int height);

void		my_draw_line(window_t *window, sfVector2f from,
			     sfVector2f to, sfColor color);

void		free_sprite(sprite_t *sprite);

void		free_sprites_only(sprite_t **sprites);

sfUint8		*pixels_buffer(int width, int height);

void		free_thread(sfThread *thread);

void		free_window(window_t *window);

void		free_sprites(sprite_t **sprites);

sprite_t	**create_sprites(int nb);

void		fill_rect(sfVector2f pos, int width,
			  int height, sfIntRect *rect);

int		in_rect(sfVector2i pos, const sfIntRect *rect);

int		is_in_rect(window_t *window, const sfIntRect *rect);

void		window_clear(window_t *window);

int		key_released(int key);

void		window_update(window_t *window);

void		window_refresh(window_t *window);

void		put_sprite(window_t *window,
			   sprite_t *sprite, sfVector2f pos);

void		put_sprite_resize(window_t *window, sprite_t *sprite,
				  sfVector2f pos, sfVector2f resize);

void		close_win(window_t *window);

sfVector2i	xy_vectori(int x, int y);

sfVector2f	xy_vectorf(float x, float y);

sfVector3f	xyz_vector(float x, float y, float z);

sfVector2i	pos_mouse(window_t *window);

void		put_square(sfVector2i pos, sfColor color,
			   window_t *window, int size);

void		draw_circle(window_t *window, sfVector2f pos,
			    int size, sfColor color);

void		put_png_resize(window_t *window, sfVector2f pos,
			       const char *name, sfVector2f resize);

void		put_png(window_t *window, sfVector2f pos, const char *name);

int		my_put_pixel(window_t *window, int x, int y, sfColor color);

void		clear_color(window_t *window, sfColor color);

void		clear_white(window_t *window);

void		put_word(const char *word, sfVector2f pos,
			 window_t *window, sfColor color);

void		put_number(int nb, sfVector2f pos,
			   window_t *window, sfColor color);

window_t	*init_window(int height, float dim, char *name, int bar);

sprite_t	*create_sprite(const char *pathname);
sprite_t	*create_sprite_rect(const char *pathname,
				    const sfIntRect area);

double		distance(sfVector2f a, sfVector2f b);

sfbutton_t	*sfbutton_create(const char *name, sprite_t *sprite,
				 sfVector2f pos,
				 int (*fction)(void *data, sfbutton_t *this));
int		sfbutton_ispressed(sfbutton_t *button, sfVector2i pos);

void		sfbutton_draw(window_t *window, sfbutton_t *button, sfVector2f pos);

void            sfbutton_draw_name(window_t *window, sfbutton_t *button,
				   sfVector2f pos, sfColor color);
int		sfbutton_exec(sfbutton_t *button, sfVector2i pos, void *data);

void		free_sfbutton(sfbutton_t *button);

void		free_sfbuttons(sfbutton_t **buttons);

int		ptr_pollevent(window_t *window, evtptr_t tab[],
			      int size, void *data);

void		add_evt(evtptr_t *index, int type, evt_t fction_ptr);

int		button_poll_event(window_t *window, sfEvent *event,
				  sfbutton_t **buttons, void *data);

void		sfbutton_draw_name_all(window_t *window, sfbutton_t **buttons,
			   sfColor color);

void		sfbutton_draw_all(window_t *window, sfbutton_t **buttons);

sfbutton_t	*button_by_name(sfbutton_t **buttons, const char *name);
sprite_t	*sprite_by_name(sprite_t **sprites, const char *name);

#ifdef __cplusplus
}
#endif

#endif /* !MY_CSFML_H_ */
