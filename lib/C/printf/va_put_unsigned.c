/*
** EPITECH PROJECT, 2017
** printf
** File description:
** put unsigned
*/

#include "new_printf.h"

int		va_put_unsigned_int(int fd, va_list *va)
{
  unsigned int	nb;

  nb = va_arg(*va, unsigned int);
  return (fd_put_unsigned_int(fd, nb));
}
