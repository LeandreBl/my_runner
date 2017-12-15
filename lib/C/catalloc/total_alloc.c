/*
** EPITECH PROJECT, 2017
** catalloc
** File description:
** total alloc size
*/

#include "catalloc.h"

#include "my.h"

static int	forward(char **cur)
{
  int		len;

  len = lenframe(*cur);
  *cur += len;
  return (len);
}

static void	loop(va_list *new, ptr_fction_t fctions[],
		     char **cur, int *size)
{
  int		i;

  i = 0;
  while (i < NB_FCTION)
  {
    if (fctions[i].action == *(*cur + 1))
    {
      *size += fctions[i].getlen(new);
      *cur += 2;
      return;
    }
    ++i;
  }
  *size += 2;
  *cur += 2;
}

int		total_alloc(const char *format, va_list *new,
			    ptr_fction_t fctions[])
{
  int		size;
  char		*cur;
  int		len;

  size = 0;
  len = my_strlen(format);
  cur = (char *)format;
  while (cur < format + len)
  {
    size += forward(&cur);
    if (*cur == '%')
      loop(new, fctions, &cur, &size);
  }
  va_end(*new);
  return (size + 1);
}
