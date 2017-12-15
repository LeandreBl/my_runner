/*
** EPITECH PROJECT, 2017
** getline_shell
** File description:
** ioctl routines
*/

#ifndef GETLINE_SHELL_H_
# define GETLINE_SHELL_H_

# include <sys/ioctl.h>
# include <termios.h>
# include <stdlib.h>
# include <string.h>
# include <glob.h>
# include <unistd.h>

# define NB_PTR 11

typedef struct	s_curset
{
  const char	*prompt;
  int		cur;
  int		hist;
  char		*s;
  char		**cmds;
  char		ch;
  int		i;
}		t_curset;

typedef struct	s_comp
{
  char		*start;
  char		*new;
  char		*end;
}		t_comp;

void		move_and_ret(char *s, int cur);
void		print_cur(int cur, char *s, const char *prompt);
void		move_and_add(char *s, int cur, char ch);
void		new_hist(t_curset *curset, int dir);
void		disp_prompt(const char *prompt);
void		backspace(int size);
int		ret_back(t_curset *curset);
int		left_key(t_curset *curset);
int		right_key(t_curset *curset);
int		up_key(t_curset *curset);
int		down_key(t_curset *curset);
int		cur_end(t_curset *curset);
int		cur_home(t_curset *curset);
int		ctrl_d(t_curset *curset);
int		ctrl_l(t_curset *curset);
int		alt_l(t_curset *curset);
int		ctrl_c(t_curset *curset);
int		ctrl_k(t_curset *curset);

#endif /* !ROUTINE_H_ */
