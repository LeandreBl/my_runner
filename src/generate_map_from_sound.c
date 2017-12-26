/*
** EPITECH PROJECT, 2017
** runner
** File description:
** generate a map from a sound buffer
*/

#include "runner.h"

static void	empty(char **map, int len)
{
  int		i;
  int		j;

  i = 0;
  while (map[i] != NULL)
  {
    j = 0;
    while (j < len)
    {
      map[i][j] = ' ';
      ++j;
    }
    ++i;
  }
  my_memset(map[i - 1], cube1, len);
}

static void	build_jump(char **map, int pos, int height)
{
  int		i;
  int		size;

  i = 0;
  size = tablen(map);
  while (i < height)
  {
    map[size - 2 - i][pos] = cube1;
    ++i;
  }
}

static void	fill_map(char **map, int len,
			 const sfInt16 *samples, unsigned int offset)
{
  int		i;

  i = 0;
  empty(map, len);
  while (i < len)
  {
    if (ABS(samples[i * offset]) > 5000)
      build_jump(map, i, 3);
    else if (ABS(samples[i * offset]) > 3000)
      build_jump(map, i, 2);
    else if (ABS(samples[i * offset]) > 500)
      build_jump(map, i, 1);
    ++i;
  }
}

char		**generate_from_soundbuffer(sfSoundBuffer *buffer)
{
  char		**map;
  const sfInt16 *samples;
  unsigned int	offset;
  sfUint64	count;
  int		len;

  samples = sfSoundBuffer_getSamples(buffer);
  count = sfSoundBuffer_getSampleCount(buffer);
  offset = sfSoundBuffer_getSampleRate(buffer);
  len = count / offset;
  map = my_alloc_tab(10, len);
  if (map == NULL)
    return (NULL);
  fill_map(map, len, samples, offset);
  return (map);
}
