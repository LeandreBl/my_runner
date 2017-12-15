/*
** EPITECH PROJECT, 2017
** catalloc
** File description:
** catalloc gesture
*/

#include "my.h"
#include "catalloc.h"

static int	loop(va_list *va, ptr_fction_t fctions[],
		     char **cur, char *str)
{
  int		i;

  i = 0;
  while (i < NB_FCTION)
  {
    if (fctions[i].action == *(*cur + 1))
    {
      fctions[i].fction(str, va);
      *cur += 2;
      return (i);
    }
    ++i;
  }
  return (i);
}

static void	len_add_str(char *str, char **cur)
{
  int		size;

  size = lenframe(*cur);
  my_strncpy(str + my_strlen(str), *cur, size);
  *cur += size;
}

int		lenframe(const char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
  {
    if (str[i] == '%' && str[i + 1] != '%')
      return (i);
    ++i;
  }
  return (i);
}

void		catalloc_gesture(const char *format, va_list *va,
				  ptr_fction_t fctions[], char *str)
{
  char		*cur;
  int		len;

  len = my_strlen(format);
  cur = (char *)format;
  while (cur < format + len)
  {
    len_add_str(str, &cur);
    if (*cur == '%')
    {
      if (loop(va, fctions, &cur, str) >= NB_FCTION)
      {
	my_strncat(str, cur, 2);
	cur += 2;
      }
    }
  }
}
