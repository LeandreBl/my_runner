/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** distance
*/

#include "csfml.h"

static double	_cube_(double a)
{
  return (a * a);
}

/* Calculate the distance between 2 points */
double		distance(sfVector2f a, sfVector2f b)
{
  return (sqrt(_cube_(a.x - b.x) + _cube_(a.y - b.y)));
}
