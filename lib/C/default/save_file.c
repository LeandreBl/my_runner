/*
** save_file.c for save_file in /home/lblanchard/lbl-libc/C
** 
** Made by Leandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Oct 13 11:06:20 2017 Leandre Blanchard
** Last update Fri Oct 13 13:24:52 2017 Leandre Blanchard
*/

#include <fcntl.h>
#include <unistd.h>

#include "my.h"

int		save_file(char **tab, const char *pathname)
{
  int		fd;
  int		i;

  i = 0;
  if ((fd = open(pathname, O_WRONLY | O_CREAT | O_APPEND, 0666)) == -1)
    return (-1);
  while (tab[i] != NULL)
    {
      my_dprintf(fd, "%s\n", tab[i]);
      ++i;
    }
  close(fd);
  return (0);
}
