/*
** sort_tab.c for sort_tab in /home/leandre/TEST_FOLDER
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Sep 16 15:36:40 2017 Léandre Blanchard
** Last update Wed Oct  4 21:22:45 2017 Léandre Blanchard
*/

#include "my.h"

static int	test_order(char **tab)
{
  int		i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      if (my_strcmp(tab[i], tab[i + 1]) > 0)
	return (1);
      ++i;
    }
  return (0);
}

int		sort_tab(char **tab)
{
  int		i;
  char		*swap;

  while (test_order(tab))
    {
      i = 0;
      while (tab != NULL && tab[i] != NULL)
	{
	  if (my_strcmp(tab[i], tab[i + 1]) > 0)
	    {
	      swap = tab[i];
	      tab[i] = tab[i + 1];
	      tab[i + 1] = swap;
	    }
	  ++i;
	}
    }
  return (0);
}
