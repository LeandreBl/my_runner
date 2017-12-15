/*
** my_put_nbr.c for my_put_nbr in /home/lblanchard/CPool_Day03
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Oct  5 20:59:45 2016 Leandre Blanchard
** Last update Sun Jul  2 17:41:27 2017 Léandre Blanchard
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb / 10 != 0)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
}
