/*
** EPITECH PROJECT, 2017
** catalloc
** File description:
** getlens
*/

#include "catalloc.h"

#include "my.h"

int		get_char_len(va_list *va)
{
  va_arg(*va, int);
  return (1);
}

int		get_float_len(va_list *va)
{
  double	nb;
  int		size;

  nb = va_arg(*va, double);
  size = my_intlen((int)nb) + 1;
  size += my_intlen((int)((nb - (int)nb) * 1000000000));
  return (size);
}

int		get_str_len(va_list *va)
{
  return (my_strlen(va_arg(*va, char *)));
}

int		get_intlen(va_list *va)
{
  return (my_intlen(va_arg(*va, int)));
}
