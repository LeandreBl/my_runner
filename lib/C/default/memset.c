/*
** EPITECH PROJECT, 2017
** libc
** File description:
** memset
*/

#include <stddef.h>
#include <stdint.h>

void		my_memset(void *ptr, int value, size_t size)
{
  uint8_t	*s;

  if (ptr == NULL)
    return;
  s = ptr;
  while (size > 0)
  {
    s[size - 1] = value;
    --size;
  }
}
