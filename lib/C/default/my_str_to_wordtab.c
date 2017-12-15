/*
** my_str_to_wordtab.c for str_wordtab in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr 26 19:18:18 2017 Léandre Blanchard
** Last update Fri Oct 13 12:26:32 2017 Leandre Blanchard
*/

#include <stdlib.h>

#include "my.h"

typedef struct	s_tab
{
  char          **tab;
  int           str_size;
  int           i;
  int           col;
  int           line;
}		t_tab;

static int      count_lines(const char *str, int separator)
{
  int		i;
  int		nb;

  i = 0;
  nb = 1;
  while (str[i] != 0)
    {
      if (str[i] == separator)
	++nb;
      ++i;
    }
  return (nb + 1);
}

static int	init_struct(t_tab *tab, const char *str, int s)
{
  int		i;
  int		size;

  i = 0;
  if (str == NULL)
    return (-1);
  tab->i = 0;
  tab->col = 0;
  tab->line = 0;
  tab->str_size = 0;
  size = count_lines(str, s);
  tab->tab = my_calloc(sizeof(char *) * size);
  if (tab->tab == NULL)
    return (-1);
  while (i < size)
  {
    tab->tab[i] = NULL;
    ++i;
  }
  return (0);
}

char		**my_str_to_wordtab(const char *str, int s)
{
  t_tab		tab;

  if (init_struct(&tab, str, s))
    return (NULL);
  while (str[tab.i] != 0)
    {
      tab.str_size = tab.i;
      while (str[tab.str_size] != 0 && str[tab.str_size] != s)
	tab.str_size++;
      if ((tab.tab[tab.line] = my_calloc(sizeof(char) *
					 (tab.str_size - tab.i) + 1)) == NULL)
	return (NULL);
      tab.col = 0;
      while (str[tab.i] != 0 && str[tab.i] != s)
      {
	tab.tab[tab.line][tab.col] = str[tab.i];
	++tab.col;
	++tab.i;
      }
      if (str[tab.i] == 0)
	return (tab.tab);
      tab.tab[tab.line++][tab.col] = '\0';
      ++tab.i;
    }
  return (tab.tab);
}
