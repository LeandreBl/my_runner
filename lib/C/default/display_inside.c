/*
** display_inside.c for display_inside in /home/leandre/TEST_FOLDER
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Jul  3 18:47:09 2017 Léandre Blanchard
** Last update Fri Oct 13 11:04:15 2017 Leandre Blanchard
*/

#include "my.h"
#include "defines.h"

static int	case_digit(const char *dup, size_t size)
{
  size_t		i;

  i = 0;
  while (i < size)
    {
      mprintf("[%d]", dup[i]);
      i++;
    }
  return (0);
}

static int	case_character(const char *dup, size_t size)
{
  size_t		i;

  i = 0;
  while (i < size)
    {
      if (dup[i] >= ' ' && dup[i] <= 126)
	mprintf("['%c']", dup[i]);
      else if (dup[i] == '\n')
	mprintf("['\\n']");
      else
	mprintf("[%d]", dup[i]);
      i++;
    }
  return (0);
}

int		display_inside(const void *buf, const char *format, size_t size)
{
  const char	*dup;

  if (buf == NULL)
    return (mprintf("*NULL*"));
  dup = (char *)buf;
  if (my_strcmp(format, "%c") == 0)
    return (case_character(dup, size));
  else if (my_strcmp(format, "%d") == 0)
    return (case_digit(dup, size));
  return (0);
}
