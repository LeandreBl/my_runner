/*
** new_printf.h for new_printf in /home/leandre/Documents/new_printf
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Sep  5 13:11:44 2017 Léandre Blanchard
** Last update Sun Nov 12 19:11:58 2017 Léandre Blanchard
*/

#ifndef NEW_PRINTF_H_
# define NEW_PRINTF_H_

# include <stdarg.h>

# define NB_FCT 12

/*
**   Handled flags :
**
** - %s %d %p %f %c same as printf
** - %T for a char ** line per line with a \n
** - %k to add a space every <arg> characters
** - %D to change the fd
** - %F to free the given parameter
** - %S = %s + frees the given string
*/

typedef struct		s_fctptr
{
  char			action;
  int			(* fction)(int fd, va_list *va);
}			t_fctptr;

/* 
** Function called by every other one, by default new_printf call 
** my_dprintf with the fd 1.
*/
int			my_dprintf(int fd, const char *format, ...);

/* Main function call, used as pritnf. */
int			new_printf(const char *format, ...);

/*
** Function that takes a fd to write in by default and a format string,
** and the va_args of the given function previously called,
** the fd, ass all functions here, can be changed using %D flag.
*/
int			va_printf(int fd, const char *format, va_list *va);

/* Write a character in the given fd */
int			fd_putchar(int fd, int c);

/* Write a '\0' terminated string in the given fd */
int			fd_putstr(int fd, const char *str);

/* Write the given nb in ASCII in the given fd */
int			fd_putnbr(int fd, int nb);
int			fd_put_unsigned_int(int fd, unsigned int nb);

/*
** Write the hexadecimal value of the given pointer
** in the given fd
*/
int			fd_pointer(int fd, void *ptr);

/*
** Write the ASCII representation of the given
** double / float in the given fd
*/
int			fd_putfloat(int fd, double nb);

int			va_putchar(int fd, va_list *va);

int			va_cutstr(int fd, va_list *va);

int			va_putstr(int fd, va_list *va);

int			va_putnbr(int fd, va_list *va);

int			va_put_unsigned_int(int fd, va_list *va);

int			va_pointer(int fd, va_list *va);

int			va_putfloat(int fd, va_list *va);

int			va_fputstr(int fd, va_list *va);

int			va_put_tab(int fd, va_list *va);

int			va_put_binary(int fd, va_list *va);

int			va_put_hex(int fd, va_list *va);

/*
** Apply the given %'' in format to the given argument
** passed as parameter
*/
void			format_gesture(int fd, va_list *va,
				       t_fctptr *fctions, const char *format);

/* %F function */
int			va_free(int fd, va_list *va);

/*
** new_printf does not print each character one per one, but
** get the next length until it finds a %'' valid indicator,
** in that case, he prints the right amount of characters with
** a single write(2) call using fd_len_putstr(3).
*/
int			fd_len_putstr(int fd, const char *str);

/* The function that changes the default writing fd */
void			va_fd_changer(int *fd, const char **cur, va_list *va);

#endif /* !NEW_PRINTF_H_ */
