/*
** EPITECH PROJECT, 2017
** safe free
** File description:
** safer free
*/

#include <stdlib.h>

void		sfree(void **ptr)
{
  free(*ptr);
  *ptr = NULL;
}
