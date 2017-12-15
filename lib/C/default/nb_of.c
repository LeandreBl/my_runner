/*
** nb_of.c for nb_of in /home/leandre/lbl-libc/nb_of.c
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Jun  3 13:27:57 2017 Léandre Blanchard
** Last update Sat Oct 14 21:30:07 2017 Léandre Blanchard
*/

int		nb_of(const char *s, char cmp)
{
  int		i;
  int		nb;

  nb = 0;
  i = 0;
  while (s[i] != 0)
    {
      if (s[i] == cmp)
	nb++;
      ++i;
    }
  return (nb);
}
