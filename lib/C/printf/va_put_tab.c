/*
** va_put_tab.c for mprintf in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Sep  8 09:33:16 2017 Léandre Blanchard
** Last update Sun Nov 12 19:15:49 2017 Léandre Blanchard
*/

#include "new_printf.h"
#include "my.h"

int		va_put_tab(int fd, va_list *va)
{
  int		i;
  char		**tab;

  tab = va_arg(*va, char **);
  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i] != NULL)
    {
      if (fd_putstr(fd, tab[i]) == -1)
	return (-1);
      if (fd_putchar(fd, '\n') == -1)
	return (-1);
      ++i;
    }
  return (0);
}
