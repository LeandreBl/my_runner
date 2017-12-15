/*
** EPITECH PROJECT, 2017
** getline_shell
** File description:
** prompt
*/

#include <unistd.h>

#include "my.h"
#include "defines.h"

void		disp_prompt(const char *str)
{
  if (isatty(0))
    {
      mprintf(str);
    }
}
