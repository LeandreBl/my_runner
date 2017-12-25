/*
** fd_put.c for printf in /home/leandre/Documents/new_printf
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Sep  7 14:58:28 2017 Léandre Blanchard
** Last update Sun Nov 12 19:06:37 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include <unistd.h>

#include "my.h"
#include "new_printf.h"

int		fd_putchar(int fd, int c)
{
  return (write(fd, &c, 1));
}

int		fd_putstr(int fd, const char *str)
{
  if (str == NULL)
    return (write(fd, "NULL", 4));
  else
    return (write(fd, str, my_strlen(str)));
}

int		fd_putnbr(int fd, int nbr)
{
  if (nbr == 0)
    return (fd_putchar(fd, '0'));
  if (nbr < 0)
    {
      if (fd_putchar(fd, '-') == -1)
	return (-1);
      nbr = -nbr;
    }
  if (nbr / 10 != 0)
    if (fd_putnbr(fd, nbr / 10) == -1)
      return (-1);
  return (fd_putchar(fd, nbr % 10 + 48));
}

int			fd_pointer(int fd, void *ptr)
{
  fd_putstr(fd, "0x");
  fd_put_unsigned_int(fd, (long)ptr);
  return (0);
}

int			fd_putfloat(int fd, double nbr)
{
  unsigned long long	integer;
  unsigned long long	floating;
  int			retur;

  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  integer = (unsigned long long)nbr;
  nbr = (nbr - integer) * 100000000;
  floating = (unsigned long long)nbr;
  while (floating % 10 == 0 && floating != 0)
    floating /= 10;
  retur = fd_putnbr(fd, integer);
  retur += fd_putchar(fd, '.');
  retur += fd_putnbr(fd, floating);
  return (retur);
}
