/*
** end_with.c for end_with in /home/leandre/Prog_elem/CPE_2016_n4s/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed May  3 13:21:06 2017 Léandre Blanchard
** Last update Wed May  3 13:22:11 2017 Léandre Blanchard
*/

#include "my.h"

int		end_with(const char *s, const char *end)
{
  while (*s != 0)
    {
      if (my_strcmp(s, end) != 0)
	s++;
      else
	return (0);
    }
  return (1);
}
