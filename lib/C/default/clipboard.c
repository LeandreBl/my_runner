/*
** clipboard.c for clipboard in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Jul 16 21:59:28 2017 Léandre Blanchard
** Last update Thu Oct 12 16:47:53 2017 Leandre Blanchard
*/

#include <stdlib.h>

#include "my.h"

int		add_to_clipboard(const char *str)
{
  char		*new;

  if ((new = catalloc("echo %s | xclip -selection clipboard", str)) == NULL)
    return (-1);
  system(new);
  sfree(&new);
  if ((new = catalloc("echo %s | xclip", str)) == NULL)
    return (-1);
  system(new);
  sfree(&new);
  return (0);
}
