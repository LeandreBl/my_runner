/*
** EPITECH PROJECT, 2017
** runner
** File description:
** header
*/

#ifndef RUNNER_H_
# define RUNNER_H_

#include "csfml.h"

#include "my.h"
#include "defines.h"
#include "colors.h"

typedef enum
{
  cloud1,
  cloud2,
  cloud3,
  cloud4,
  cloud5,
  left_angle,
  cube1,
  right_angle,
  cube2,
  tree,
  moutain,
  sky,
  logo,
  button,
}		sheet_e;

typedef struct	data_pkt_s
{
  window_t	*window;
  sfbutton_t	**buttons;
  sprite_t	**sprites;
}		data_pkt_t;

int	start_menu(window_t *window);

#endif /* !RUNNER_H_ */
