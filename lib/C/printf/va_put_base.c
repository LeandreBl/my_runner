/*
** va_put_binary.c for mprintf in /home/lblanchard/lbl-libc/C
** 
** Made by Leandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Oct 12 16:49:48 2017 Leandre Blanchard
** Last update Sun Nov 12 19:14:09 2017 Léandre Blanchard
*/

#include "my.h"
#include "new_printf.h"

# define HEXA "0123456789abcdef"

static int	put_binary(int fd, int bytes)
{
  if (bytes >> 1 != 0)
    if (put_binary(fd, bytes >> 1) == -1)
      return (-1);
  return (fd_putchar(fd, 48 + (1 & bytes)));
}

int		va_put_binary(int fd, va_list *va)
{
  int		bytes;

  bytes = va_arg(*va, int);
  if (bytes < 0)
    {
      bytes = -bytes;
      if (fd_putchar(fd, '-') == -1)
	return (-1);
    }
  return (put_binary(fd, bytes));
}

static int	put_hex(int fd, int nb)
{
  int		res;
  int		rest;

  res = nb / 16;
  rest = nb % 16;
  if (res > 0)
    if (put_hex(fd, res) == -1)
      return (-1);
  return (fd_putchar(fd, HEXA[rest]));
}

int		va_put_hex(int fd, va_list *va)
{
  int		nb;

  nb = va_arg(*va, int);
  if (nb < 0)
  {
    nb = -nb;
    if (fd_putchar(fd, '-') == -1)
      return (-1);
  }
  return (put_hex(fd, nb));
}
