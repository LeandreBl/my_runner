/*
** free_tab.c for free_tab in /home/leandre/libmy/
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Feb 28 14:14:05 2017 Léandre Blanchard
** Last update Thu Oct 12 17:21:19 2017 Leandre Blanchard
*/

#include <stdlib.h>

#include "my.h"

void	        free_tab(void *ptr)
{
  int		i;
  char		***tabptr;
  char		**tab;

  i = 0;
  tabptr = ptr;
  tab = *tabptr;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
      {
	sfree(&tab[i]);
	++i;
      }
      sfree(ptr);
      *tabptr = NULL;
    }
}
