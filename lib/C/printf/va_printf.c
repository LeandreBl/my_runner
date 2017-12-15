/*
** va_printf.c for va_printf in /home/leandre/Documents/new_printf
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Sep  7 12:39:57 2017 Léandre Blanchard
** Last update Sun Nov 12 19:12:27 2017 Léandre Blanchard
*/

#include <stdlib.h>

#include "my.h"
#include "new_printf.h"

int			va_fputstr(int fd, va_list *va)
{
  char			*str;

  str = va_arg(*va, char *);
  if (fd_putstr(fd, str) == -1)
    return (-1);
  sfree(&str);
  return (0);
}

static t_fctptr		add_fction(char action,
				   int (*fction)(int fd, va_list *va))
{
  t_fctptr		tab;

  tab.action = action;
  tab.fction = fction;
  return (tab);
}

static void		tab_create(t_fctptr *tab)
{
  tab[0] = add_fction('s', va_putstr);
  tab[1] = add_fction('c', va_putchar);
  tab[2] = add_fction('d', va_putnbr);
  tab[3] = add_fction('p', va_pointer);
  tab[4] = add_fction('f', va_putfloat);
  tab[5] = add_fction('F', va_free);
  tab[6] = add_fction('S', va_fputstr);
  tab[7] = add_fction('k', va_cutstr);
  tab[8] = add_fction('T', va_put_tab);
  tab[9] = add_fction('b', va_put_binary);
  tab[10] = add_fction('x', va_put_hex);
  tab[11] = add_fction('u', va_put_unsigned_int);
}

int			va_printf(int fd, const char *format, va_list *va)
{
  static t_fctptr	fctions[NB_FCT];
  static int		called = 0;

  if (called == 0)
    tab_create(fctions);
  called++;
  format_gesture(fd, va, fctions, format);
  return (0);
}
