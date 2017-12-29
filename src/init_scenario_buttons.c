/*
** EPITECH PROJECT, 2017
** runner
** File description:
** create button for scenario
*/

#include "runner.h"

static int	map_selected(void *data, sfbutton_t *this)
{
  start_game(data, this->name);
  return (0);
}

static void	select_files(char **filenames)
{
  int		i;

  i = 0;
  while (filenames[i] != NULL)
  {
    if (end_with(filenames[i], ".ogg") == false
	&& end_with(filenames[i], ".wav") == false
	&& end_with(filenames[i], ".flac") == false
	&& end_with(filenames[i], ".aiff") == false)
    {
      tab_remove(filenames, i);
      --i;
    }
    ++i;
  }
}

int		load_scenario_buttons(sfbutton_t ***buttons, sprite_t **sprites)
{
  char		**filenames;
  int		i;

  filenames = dir_filenames(".", true);
  if (filenames == NULL)
    return (-1);
  select_files(filenames);
  *buttons = my_calloc(sizeof(sfbutton_t *) * (tablen(filenames) + 1));
  if (*buttons == NULL)
    return (-1);
  i = 0;
  while (filenames[i] != NULL)
  {
    (*buttons)[i] = sfbutton_create(filenames[i], sprites[button2],
				    ORIGIN, map_selected);
    ++i;
  }
  free_tab(&filenames);
  return (0);
}
