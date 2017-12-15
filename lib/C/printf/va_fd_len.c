/*
** va_fd_len.c for mprintf in /home/leandre/TEST_FOLDER
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Sep  8 09:00:30 2017 Léandre Blanchard
** Last update Sun Nov 12 19:12:10 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include <unistd.h>

#include "new_printf.h"
#include "my.h"

int			va_free(int fd, va_list *va)
{
  void			*ptr;

  (void)fd;
  ptr = va_arg(*va, void *);
  sfree(&ptr);
  return (0);
}

static int		lenframe(const char *str)
{
  int			i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '%' && str[i + 1] != '%')
	return (i);
      ++i;
    }
  return (i);
}

int			fd_len_putstr(int fd, const char *str)
{
  int			len;

  len = lenframe(str);
  if (str == NULL)
    write(fd, "NULL", 4);
  else
    {
      len = lenframe(str);
      write(fd, str, len);
    }
  return (len);
}

void			va_fd_changer(int *fd, const char **cur, va_list *va)
{
  if (my_strncmp(*cur, "%D", 2) == 0)
    {
      *fd = va_arg(*va, int);
      *cur += 2;
    }
}
