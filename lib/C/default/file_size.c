/*
** file_size.c for file_size in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May 25 19:26:32 2017 Léandre Blanchard
** Last update Thu May 25 19:33:00 2017 Léandre Blanchard
*/

#include <unistd.h>
#include <fcntl.h>

int             file_size(const char *pathname)
{
  int           size;
  int           buff[100];
  int           rd;
  int           fd;

  if ((fd = open(pathname, O_RDONLY)) == -1)
    return (-1);
  size = 0;
  while ((rd = read(fd, buff, 100)) > 0)
    size += rd;
  close(fd);
  return (size);
}
