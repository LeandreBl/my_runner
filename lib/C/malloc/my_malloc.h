/*
** EPITECH PROJECT, 2017
** my_malloc
** File description:
** header
*/

#ifndef MY_MALLOC_H_
# define MY_MALLOC_H_

# include <stddef.h>

typedef struct		alloc_header_s
{
  struct alloc_header_s	*prev;
  struct alloc_header_s	*next;
  size_t		size;
  void			*data;
}			alloc_header_t;

extern alloc_header_t *last;

extern const unsigned int SIZE;

#endif /* !MY_MALLOC_H_ */
