/*
** my_putstr.c for my_putstr in /home/lblanchard/CPool_Day04
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Thu Oct  6 11:19:22 2016 Leandre Blanchard
** Last update Sat Oct 21 19:06:12 2017 Léandre Blanchard
*/

#include <unistd.h>

#include "my.h"

int	my_putstr(const char *str)
{
  if (str == NULL)
    return (my_putstr("NULL"));
  return (write(1, str, my_strlen(str)));
}
