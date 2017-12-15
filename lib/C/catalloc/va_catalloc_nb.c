/*
** EPITECH PROJECT, 2017
** catalloc
** File description:
** number handlers
*/

#include <stdarg.h>

#include "my.h"

static void			sadd_int(char *src, int nb)
{
  int				size;
  int				len;
  int				i;

  i = 0;
  size = my_intlen(nb);
  len = my_strlen(src);
  if (nb == 0)
    src[len] = '0';
  if (nb < 0)
  {
    src[len] = '-';
    nb = -nb;
  }
  while (nb > 0)
  {
    src[len + size - i - 1] = 48 + nb % 10;
    nb /= 10;
    ++i;
  }
}

char				*add_number(char *src, va_list *va)
{
  int				nb;

  nb = va_arg(*va, int);
  if (src == NULL)
    return (NULL);
  if (nb == 0)
    my_strcat(src, "0");
  else
    sadd_int(src, nb);
  return (src);
}

char				*add_float(char *src, va_list *va)
{
  int				ent;
  int				dec;
  double			nb;

  nb = va_arg(*va, double);
  ent = (int)nb;
  dec = (int)((nb - ent) * 1000000000);
  while (dec % 10 == 0 && dec != 0)
    dec /= 10;
  if (src == NULL)
    return (NULL);
  sadd_int(src, ent);
  src[my_strlen(src)] = '.';
  sadd_int(src, dec);
  return (src);
}
