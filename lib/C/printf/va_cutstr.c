/*
** va_cutstr.c for mprintf in /home/leandre/TEST_FOLDER
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Sep  8 09:09:31 2017 Léandre Blanchard
** Last update Sun Nov 12 19:10:06 2017 Léandre Blanchard
*/

#include <unistd.h>

#include "new_printf.h"
#include "my.h"

int			va_cutstr(int fd, va_list *va)
{
  const char		*str;
  const char		*ptr;
  int			jmp;
  int			len;

  str = va_arg(*va, char *);
  jmp = va_arg(*va, int);
  len = my_strlen(str);
  ptr = str;
  while (ptr + jmp < str + len)
    {
      if (write(fd, ptr, jmp) == -1 ||
	  write(fd, " ", 1) == -1)
	return (-1);
      ptr += jmp;
    }
  if (ptr < str + len)
    return (fd_putstr(fd, ptr));
  return (0);
}
