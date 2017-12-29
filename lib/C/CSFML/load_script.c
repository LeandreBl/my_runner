/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** load script from a file
*/

#include "csfml.h"

#include "defines.h"
#include "my.h"
#include "colors.h"

#define CSFML_ERR       "[CSFML] "
#define SCRIPT_TAG      "name : "
#define LOAD_TAG        "load > "

static int      reach_script(char **file, const char *script)
{
  int           i;
  char          *line;

  i = 0;
  line = catalloc("%s%s", SCRIPT_TAG, script);
  while (file[i] != NULL)
  {
    epur_str(file[i]);
    if (my_strcmp(file[i], line) == 0)
    {
      sfree(&line);
      return (i);
    }
    ++i;
  }
  sfree(&line);
  return (-1);
}

static int      number_of_sprites(char **file, const char *script)
{
  int           i;

  i = 1;
  while (file[i] != NULL &&
	 my_strncmp(file[i], SCRIPT_TAG, my_strlen(SCRIPT_TAG)))
  {
    epur_str(file[i]);
    if (my_strncmp(file[i], LOAD_TAG, my_strlen(LOAD_TAG)) != 0
	&& my_strlen(file[i]))
    {
      mdprintf(2, CSFML_ERR "[%sWarning%s] Unknown tag <%s> in <%s> script\n",
	       GREEN, RESET, file[i], script);
    }
    ++i;
  }
  return (i);
}

static void get_frame_size(const char *format, sfIntRect *frame)
{
  int           i;

  i = 0;
  while (format[i] == ' ')
    ++i;
  frame->left = my_getnbr(format + i);
  i += my_kstrlen(format + i, ',') + 1;
  while (format[i] == ' ')
    ++i;
  frame->top = my_getnbr(format + i);
  i += my_intlen(frame->top);
  while (format[i] == ' ')
    ++i;
  frame->width = my_getnbr(format + i);
  i += my_kstrlen(format + i, ',') + 1;
  while (format[i] == ' ')
    ++i;
  frame->height = my_getnbr(format + i);
}

static int      add_load(const char *format, sprite_t **sprites)
{
  char          *filename;
  sfIntRect     frame;
  int           len;
  int           size;

  size = tablen(sprites);
  len = my_kstrlen(format, ' ');
  filename = my_strndup(format, len);
  if (my_strlen(format + len) < 8)
  {
    if (my_strlen(format + len) != 0)
    {
      mdprintf(2, CSFML_ERR "[%sError%s] bad format \"%s\"\n",
	       RED, RESET, format - my_strlen(LOAD_TAG));
      return (-1);
    }
    sprites[size] = create_sprite(filename);
  }
  else
  {
    get_frame_size(format + len, &frame);
    sprites[size] = create_sprite_rect(filename, frame);
  }
  sfree(&filename);
  if (sprites[size] == NULL)
    return (-1);
  return (0);
}

static int      use_script(char **file, int nb, sprite_t **sprites)
{
  int           i;

  i = 0;
  while (i < nb)
  {
    if (my_strncmp(file[i], LOAD_TAG, my_strlen(LOAD_TAG)) == 0)
    {
      if (add_load(file[i] + my_strlen(LOAD_TAG), sprites) == -1)
	return (-1);
    }
    ++i;
  }
  return (0);
}


/* Load the sprites from the script in "pathname" with the name "script" */
int             load_script(const char *pathname, const char *script, sprite_t ***ptr)
{
  char **file;
  int   line;
  int   nb;

  file = load_file(pathname);
  mprintf("[%sInfo%s] Loading script %s\"%s\"%s\n",
	  YELLOW, RESET, GREEN, script, RESET);
  if (file == NULL)
  {
    mdprintf(2, CSFML_ERR "[%sError%s] cannot open <%s> script\n",
	     RED, RESET, pathname);
    return (-1);
  }
  line = reach_script(file, script);
  if (line == -1)
  {
    mdprintf(2, CSFML_ERR "[%sError%s] Script <%s> not found in <%s> file\n",
	     RED, RESET, script, pathname);
    return (-1);
  }
  nb = number_of_sprites(file + line, script);
  *ptr = my_calloc(sizeof(sprite_t *) * (nb + 1));
  if (ptr == NULL)
    return (-1);
  if (use_script(file + line, nb, *ptr) == -1)
    return (-1);
  free_tab(&file);
  mprintf("[%sInfo%s] script %s\"%s\"%s successfully loaded\n",
	  YELLOW, RESET, GREEN, script, RESET);
  return (0);
}
