/*
** EPITECH PROJECT, 2017
** isacmd
** File description:
** if str is a binary
*/

#include <stdlib.h>
#include <unistd.h>

#include "my.h"

int			isacmd(const char *str)
{
  char			*env;
  char			**paths;
  int			i;

  i = 0;
  env = getenv("PATH");
  paths = my_str_to_wordtab(env, ':');
  str = my_strndup(str, my_kstrlen(str, ' '));
  if (env == NULL || paths == NULL || str == NULL)
    return (0);
  while (paths[i] != NULL)
  {
    paths[i] = catalloc("%S/%s", paths[i], str);
    if (paths != NULL && access(paths[i], F_OK) == 0)
    {
      free_tab(&paths);
      sfree(&str);
      return (1);
    }
    ++i;
  }
  free_tab(&paths);
  sfree(&str);
  return (0);
}
