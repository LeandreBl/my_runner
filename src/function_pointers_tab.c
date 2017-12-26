/*
** EPITECH PROJECT, 2017
** runner
** File description:
** all fct ptr tab init
*/

#include "runner.h"

void	init_tab_menu(evtptr_t tab[])
{
  add_evt(&tab[0], sfEvtClosed, leave_menu);
  add_evt(&tab[1], sfEvtMouseButtonPressed, menu_buttons);
  add_evt(&tab[2], sfEvtKeyPressed, leave_menu);
}

void	init_tab_scenario(evtptr_t tab[])
{
  add_evt(&tab[0], sfEvtClosed, leave_scenario);
  add_evt(&tab[1], sfEvtMouseButtonPressed, scenario_buttons);
  add_evt(&tab[2], sfEvtKeyPressed, leave_scenario);
  add_evt(&tab[3], sfEvtMouseWheelScrolled, scenario_scroll);
}

void	init_tab_ingame(evtptr_t tab[])
{
  add_evt(&tab[0], sfEvtClosed, leave_ingame);
  add_evt(&tab[1], sfEvtKeyPressed, leave_ingame);
  add_evt(&tab[2], sfEvtMouseButtonPressed, play_button);
}
