/*
** end_with.c for end_with in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 13:21:06 2017 Léandre Blanchard
** Last update Mon Dec 25 02:26:32 2017 Léandre Blanchard
*/

#include "my.h"

bool		end_with(const char *s, const char *end)
{
  size_t	size;

  size = my_strlen(end);
  if (size > my_strlen(s))
    return (false);
  if (my_strcmp(s + my_strlen(s) - size, end) == 0)
    return (true);
  return (false);
}
