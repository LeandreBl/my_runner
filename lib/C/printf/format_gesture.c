/*
** format_gesture.c for va_printf in /home/leandre/Documents/new_printf
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Sep  7 14:30:58 2017 Léandre Blanchard
** Last update Sun Nov 12 19:17:49 2017 Léandre Blanchard
*/

#include <unistd.h>

#include "my.h"
#include "new_printf.h"

static int		loop(int *fd, va_list *va,
			     t_fctptr *fctions, const char **cur)
{
  int			i;

  i = 0;
  while (i < NB_FCT)
    {
      if (fctions[i].action == *(*cur + 1))
	{
	  if (fctions[i].fction(*fd, va) == -1)
	    return (-1);
	  *cur += 2;
	  return (fctions[i].action);
	}
      ++i;
    }
  return (fctions[i].action);
}

void			format_gesture(int fd, va_list *va,
				       t_fctptr *fctions, const char *format)
{
  int			len;
  const char	       	*cur;

  cur = format;
  len = my_strlen(format);
  while (cur < format + len)
    {
      cur += fd_len_putstr(fd, cur);
      if (*cur == '%')
	{
	  if (loop(&fd, va, fctions, &cur) == 0
	      && my_strncmp(cur, "%D", 2))
	    {
	      write(fd, cur, 2);
	      cur += 2;
	    }
	  va_fd_changer(&fd, &cur, va);
	}
    }
}
