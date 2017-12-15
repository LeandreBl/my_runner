/*
** fd_put.c for va_printf in /home/leandre/Documents/new_printf
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Sep  7 14:05:47 2017 Léandre Blanchard
** Last update Sun Nov 12 19:14:56 2017 Léandre Blanchard
*/

#include "my.h"
#include "new_printf.h"

int		va_putchar(int fd, va_list *va)
{
  int		c;

  c = va_arg(*va, int);
  return (fd_putchar(fd, c));
}

int		va_putstr(int fd, va_list *va)
{
  char		*str;

  str = va_arg(*va, char *);
  return (fd_putstr(fd, str));
}

int		va_putnbr(int fd, va_list *va)
{
  int		nb;

  nb = va_arg(*va, int);
  return (fd_putnbr(fd, nb));
}

int		va_pointer(int fd, va_list *va)
{
  void		*addr;

  addr = va_arg(*va, void *);
  return (fd_pointer(fd, addr));
}

int		va_putfloat(int fd, va_list *va)
{
  double       	nbr;

  nbr = va_arg(*va, double);
  return (fd_putfloat(fd, nbr));
}
