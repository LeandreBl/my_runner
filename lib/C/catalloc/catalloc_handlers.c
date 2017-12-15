/*
** EPITECH PROJECT, 2017
** catalloc
** File description:
** functions handled
*/

#include <stdarg.h>
#include <stdlib.h>

#include "my.h"

char				*add_char(char *src, va_list *va)
{
  char				c;

  c = (char)va_arg(*va, int);
  my_strncat(src, &c, 1);
  return (src);
}

char				*cata_free(char *src, va_list *va)
{
  void				*to_free;

  to_free = va_arg(*va, void *);
  sfree(&to_free);
  return (src);
}

char				*add_str(char *src, va_list *va)
{
  char				*str;

  str = va_arg(*va, char *);
  my_strcat(src, str);
  return (src);
}

char				*add_str_free(char *src, va_list *va)
{
  char				*str;

  str = va_arg(*va, char *);
  my_strcat(src, str);
  sfree(&str);
  return (src);
}
