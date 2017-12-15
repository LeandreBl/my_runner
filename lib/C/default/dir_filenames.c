/*
** dir_filenames.c for dir_filenames in /home/leandre/TEST_FOLDER
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Sep 16 15:39:05 2017 Léandre Blanchard
** Last update Tue Nov  7 23:47:52 2017 Léandre Blanchard
*/

#include <sys/types.h>
#include <dirent.h>

#include "my.h"
#include "defines.h"

char		**dir_filenames(const char *dirname, int sort)
{
  char		**filenames;
  DIR		*directory;
  struct dirent	*dirent;

  filenames = NULL;
  directory = opendir(dirname);
  if (directory == NULL)
    return (NULL);
  while ((dirent = readdir(directory)) != NULL)
  {
    if (dirent->d_type == DT_REG)
    {
      filenames = tab_append(filenames, my_strdup(dirent->d_name));
      if (filenames == NULL)
	return (NULL);
    }
  }
  closedir(directory);
  if (sort)
    sort_tab(filenames);
  return (filenames);
}
