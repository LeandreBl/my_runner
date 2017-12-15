/*
** EPITECH PROJECT, 2017
** catalloc
** File description:
** ptr_functions
*/

#include "catalloc.h"

#include "my.h"

static void		add_fction(char action, ptr_fction_t *index,
				   void (*fction)(char *src, va_list *va),
				   int (*getlen)(va_list *va))
{
  index->action = action;
  index->fction = fction;
  index->getlen = getlen;
}

static void		tab_create(ptr_fction_t *tab)
{
  add_fction('c', &tab[0], add_char, get_char_len);
  add_fction('s', &tab[1], add_str, get_str_len);
  add_fction('d', &tab[2], add_number, get_intlen);
  add_fction('f', &tab[3], add_float, get_float_len);
  add_fction('F', &tab[4], cata_free, get_str_len);
  add_fction('S', &tab[5], add_str_free, get_str_len);
}

char			*va_catalloc(const char *format, va_list *va)
{
  static ptr_fction_t	fctions[NB_FCTION];
  static int		called = 0;
  va_list		new;
  char			*str;

  if (called == 0)
    tab_create(fctions);
  called++;
  va_copy(new, *va);
  str = my_calloc(total_alloc(format, &new, fctions));
  if (str == NULL)
    return (NULL);
  catalloc_gesture(format, va, fctions, str);
  return (str);
}
