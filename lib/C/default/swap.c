/*
** EPITECH PROJECT, 2017
** libc
** File description:
** swap
*/

void		swap(void *a, void *b)
{
  long		swp;

  swp = *(long *)a;
  *(long *)a = *(long *)b;
  *(long *)b = swp;
}
