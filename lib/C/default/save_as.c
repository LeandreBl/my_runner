/*
** save_as.c for save_as in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Sep  8 12:35:54 2017 Léandre Blanchard
** Last update Fri Oct 13 10:40:55 2017 Leandre Blanchard
*/

#include <fcntl.h>
#include <unistd.h>

int		save_as(const char *pathname, const void *data, int size)
{
  int		fd;

  if ((fd = open(pathname, O_WRONLY | O_CREAT | O_APPEND, 0666)) == -1)
    return (-1);
  if (write(fd, data, size) == -1)
    return (-1);
  close(fd);
  return (0);
}
