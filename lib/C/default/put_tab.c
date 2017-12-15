/*
** my_put_tab.c for put_tab in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Feb 24 16:25:21 2017 Léandre Blanchard
** Last update Wed Oct 25 21:11:21 2017 Léandre Blanchard
*/

#include <unistd.h>

#include "my.h"
#include "defines.h"

void		put_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	mprintf("%s\n", tab[i++]);
    }
}

void		put_tabw(const char *start, char **tab, const char *end)
{
  int		i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	mprintf("%s%s%s", start, tab[i++], end);
    }
}
