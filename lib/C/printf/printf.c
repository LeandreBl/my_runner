/*
** printf.c for printf in /home/leandre/Documents/new_printf
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Sep  7 12:37:45 2017 Léandre Blanchard
** Last update Thu Sep  7 13:51:40 2017 Léandre Blanchard
*/

#include "new_printf.h"
#include "my.h"

int		my_dprintf(int fd, const char *format, ...)
{
  va_list	va;
  int		ret;

  va_start(va, format);
  ret = va_printf(fd, format, &va);
  va_end(va);
  return (ret);
}

int		new_printf(const char *format, ...)
{
  va_list	va;
  int		ret;

  va_start(va, format);
  ret = va_printf(1, format, &va);
  va_end(va);
  return (ret);
}
