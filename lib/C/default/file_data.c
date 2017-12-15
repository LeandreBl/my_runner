/*
** file_data.c for file_data in /home/leandre/TEST_FOLDER
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Sep 12 20:01:55 2017 Léandre Blanchard
** Last update Thu Oct 12 16:47:10 2017 Leandre Blanchard
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "my.h"

void		*file_data(const char *pathname)
{
  void		*data;
  int		fd;
  int		size;

  if (pathname == NULL)
    return (NULL);
  size = file_size(pathname);
  if ((fd = open(pathname, O_RDONLY)) == -1)
    return (NULL);
  if ((data = my_calloc(size + 3)) == NULL)
    return (NULL);
  if ((read(fd, data, size + 1)) == -1)
    {
      sfree(&data);
      return (NULL);
    }
  close(fd);
  return (data);
}
