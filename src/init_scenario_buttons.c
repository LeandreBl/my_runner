/*
** EPITECH PROJECT, 2017
** runner
** File description:
** create button for scenario
*/

#include "runner.h"

static int	map_selected(void *data, sfbutton_t *this)
{
  char		*filename;

  filename = catalloc("%s.ogg", this->name);
  if (filename == NULL)
    return (-1);
  start_game(data, filename);
  sfree(&filename);
  return (0);
}

static void	select_files(char **filenames, const char *end)
{
  int		i;

  i = 0;
  while (filenames[i] != NULL)
  {
    if (end_with(filenames[i], end) == false)
    {
      tab_remove(filenames, i);
      --i;
    }
    else
      shift_right(filenames[i], my_strlen(end));
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
  select_files(filenames, ".ogg");
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
