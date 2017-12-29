/*
** EPITECH PROJECT, 2017
** runner
** File description:
** ingame well
*/

#include "runner.h"

static void	fill_data(data_pkt_t *data, window_t *window, sprite_t **sprites,
			  sfbutton_t **buttons)
{
  data->window = window;
  data->sprites = sprites;
  data->buttons = buttons;
  data->offset = 0;
  data->back = false;
}

static void	player_preview(window_t *window, sprite_t **sprites)
{
  sfVector2u    size;
  sfVector2u    match;
  sfVector2f    scale;
  sfVector2f    pos;
  
  size = sfTexture_getSize(sprites[player]->texture);
  match = sfTexture_getSize(sprites[cube1]->texture);
  scale.x = (float)match.x / (float)size.x;
  scale.y = (float)match.y / (float)size.y;
  pos.x = 50;
  pos.y = window->height - match.y * 1.47;
  put_sprite_resize(window, sprites[player],
		    pos, scale);
}				 

static void	display(window_t *window, sprite_t **sprites,
			char **map, sfbutton_t *play)
{
  int		i;
  int		j;
  sfVector2u	size;
  sfVector2f	pos;

  i = 0;
  display_sky(window, sprites[sky]);
  size = sfTexture_getSize(sprites[cube1]->texture);
  while (map[i] != NULL)
  {
    j = 0;
    while (map[i][j] != 0)
    {
      if (map[i][j] != ' ')
      {
	size = sfTexture_getSize(sprites[(int)map[i][j]]->texture);
	pos.x = size.x * j;
	pos.y = i * size.y + tablen(map) - 1 - size.y * 1.2;
	if (pos.x > window->width)
	  break;
	put_sprite(window, sprites[(int)map[i][j]], pos);
      }
      j++;
    }
    ++i;
  }
  sfbutton_draw_name(window, play, xy_vectorf(window->width / 2 - 80,
					      window->height / 2 - 20),
		     sfWhite);
  player_preview(window, sprites);
}

static void	ingame(window_t *window, sprite_t **sprites,
		       sfMusic *music, sfSoundBuffer *buffer)
{
  data_pkt_t	data;
  evtptr_t	tab[3];
  sfbutton_t	*play;
  char		**map;

  init_tab_ingame(tab);
  map = generate_from_soundbuffer(buffer);
  if (map == NULL)
    return;
  play = sfbutton_create("play !", sprites[button],
			 ORIGIN, runner);
  fill_data(&data, window, sprites, &play);
  data.map = map;
  data.music = music;
  while (sfRenderWindow_isOpen(window->window) &&
	 data.back == false)
  {
    window_clear(window);
    ptr_pollevent(window, tab, sizeof(tab) / sizeof(*tab), &data);
    display(window, sprites, map, play);
    if (data.back == false)
      window_refresh(window);
  }
  sfMusic_stop(music);
  free_tab(&map);
}

void		start_game(void *data, const char *filename)
{
  data_pkt_t	*ptr;
  sfMusic	*music;
  sfSoundBuffer	*buffer;

  music = sfMusic_createFromFile(filename);
  buffer = sfSoundBuffer_createFromFile(filename);
  if (music == NULL || buffer == NULL)
  {
    mdprintf(2, "[%sError%s] Could not open %s%s%s\n",
	     RED, RESET, YELLOW, filename, RESET);
    return;
  }
  ptr = (data_pkt_t *)data;
  ingame(ptr->window, ptr->sprites, music, buffer);
  sfMusic_destroy(music);
  sfSoundBuffer_destroy(buffer);
}
