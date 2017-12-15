/*
** get_next_line.c for gnl in /home/leandre/Prog_elem/CPE_2016_getnextline/new
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Apr  3 16:40:21 2017 Léandre Blanchard
** Last update Sat Oct 14 21:56:25 2017 Léandre Blanchard
*/

#include <unistd.h>

#include "get_next_line.h"
#include "defines.h"

static t_gnl	init_struct(void)
{
  t_gnl		tuple;

  tuple.i = 0;
  tuple.size = 2;
  tuple.s = my_calloc(tuple.size);
  return (tuple);
}

static int	loop(int fd, t_gnl *all, int *status)
{
  while ((*status = read(fd, &all->ch, 1)) > 0)
    {
      if (all->ch == '\n')
	return (1);
      all->s[all->i] = all->ch;
      all->i += 1;
      all->size += 1;
      if ((all->s = my_frealloc(all->s, all->size)) == NULL)
	return (2);
    }
  return (0);
}

char		*get_next_line(int fd)
{
  t_gnl		all;
  static int	status;
  int		ret;

  all = init_struct();
  if (all.s == NULL)
    return (NULL);
  if (status == -1 || all.s == NULL)
    return (NULL);
  ret = loop(fd, &all, &status);
  if (ret == 2)
    return (NULL);
  else if (ret != 0)
    return (all.s);
  if (status == 0)
    {
      status = -1;
      return (all.s);
    }
  return (all.s);
}
