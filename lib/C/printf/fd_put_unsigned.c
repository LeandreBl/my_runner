/*
** EPITECH PROJECT, 2017
** printf
** File description:
** fd_put unsigned
*/

#include "new_printf.h"

int		fd_put_unsigned_int(int fd, unsigned int nb)
{
  if (nb == 0)
    return (fd_putchar(fd, '0'));
  if (nb / 10 != 0)
    if (fd_put_unsigned_int(fd, nb / 10) == -1)
      return (-1);
  return (fd_putchar(fd, nb % 10 + 48));
}
