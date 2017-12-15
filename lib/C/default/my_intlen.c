/*
** my_int_len.c for int_len in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Feb 24 21:06:27 2017 Léandre Blanchard
** Last update Sat Nov  4 04:12:28 2017 Léandre Blanchard
*/

int		my_intlen(int nb)
{
  int		i;

  i = 0;
  if (nb == 0)
    return (1);
  if (nb < 0)
    ++i;
  while (nb != 0)
    {
      nb = nb / 10;
      i++;
    }
  return (i);
}
