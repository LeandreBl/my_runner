/*
** thread.c for thread in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat May 27 19:03:37 2017 Léandre Blanchard
** Last update Sat Jun  3 17:01:12 2017 Léandre Blanchard
*/

#include "csfml.h"
/*
** Just a tiny function that stop a thread, and frees it,
** disabling all kind of non-terminated thread that has been freed
** Does not return
*/
void            free_thread(sfThread *thread)
{
  usleep(2000);
  sfThread_terminate(thread);
  sfThread_destroy(thread);
}
