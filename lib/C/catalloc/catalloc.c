/*
** EPITECH PROJECT, 2017
** catalloc
** File description:
** catalloc function
*/

#include "my.h"
#include "catalloc.h"

char		*catalloc(const char *format, ...)
{
  char		*str;
  va_list	va;

  if (format == NULL)
    return (NULL);
  va_start(va, format);
  str = va_catalloc(format, &va);
  va_end(va);
  return (str);
}
