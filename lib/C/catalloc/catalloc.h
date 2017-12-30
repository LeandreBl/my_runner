/*
** EPITECH PROJECT, 2017
** catalloc
** File description:
** catalloc header
*/

#ifndef CATALLOC_H_
# define CATALLOC_H_

# include <stdarg.h>

struct	ptr_fction_s
{
  char	action;
  void	(* fction)(char *src, va_list *va);
  int	(* getlen)(va_list *va);
};

# define NB_FCTION (6)

typedef struct ptr_fction_s ptr_fction_t;

int	lenframe(const char *str);
void	catalloc_gesture(const char *format, va_list *va,
			 ptr_fction_t fctions[], char *str);
char	*va_catalloc(const char *format, va_list *va);
void	va_scatalloc(char *dest, const char *format, va_list *va);
int	total_alloc(const char *format, va_list *new,
		    ptr_fction_t fctions[]);
/* functions used to add into str */
void	add_char(char *src, va_list *va);
void	add_number(char *src, va_list *va);
void	add_str(char *src, va_list *va);
void	add_str_free(char *src, va_list *va);
void	add_float(char *src, va_list *va);
void	cata_free(char *src, va_list *va);
/* functions used to calc each param size */
int	get_char_len(va_list *va);
int	get_float_len(va_list *va);
int	get_str_len(va_list *va);
int	get_intlen(va_list *va);

#endif /* !CATALLOC_H_ */
