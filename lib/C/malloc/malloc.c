/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** main file
*/

#include <unistd.h>

#include "my_malloc.h"
#include "my.h"

const unsigned int	SIZE = sizeof(alloc_header_t);

alloc_header_t		*last = NULL;

static void		new_node(alloc_header_t *node, size_t size, void **ptr)
{
  alloc_header_t	left;
  void			*head;

  left.prev = node;
  left.size = node->size - size - SIZE;
  left.data = NULL;
  left.next = node->next;
  node->size = size;
  node->data = (void *)node + SIZE;
  head = node->data + size;
  memcopy(head, &left, SIZE);
  node->next = head;
  if (node->next != NULL && node->next->next != NULL)
    node->next->next->prev = node->next;
  *ptr = node->data;
}

static int		match_alloc(alloc_header_t *node, size_t size, void **ptr)
{
  if (node->size >= size && node->size <= size + SIZE)
  {
    node->data = (void *)(node + SIZE);
    *ptr = node->data;
  }
  else if (node->size > size + SIZE)
    new_node(node, size, ptr);
  else
    return (0);
  return (1);
}

static int		alloc(size_t size, void **ptr)
{
  alloc_header_t	new;
  void			*head;

  head = sbrk(size + SIZE);
  if ((long)head == -1)
    return (-1);
  new.prev = last;
  new.size = size;
  new.data = head + SIZE;
  new.next = NULL;
  if (new.prev != NULL)
    new.prev->next = head;
  *ptr = new.data;
  memcopy(head, &new, SIZE);
  last = new.data - SIZE;
  return (0);
}

static int		normal_alloc(size_t size, void **ptr)
{
  alloc_header_t	*node;

  node = last;
  while (node != NULL)
  {
    if (node->size >= size && node->data == NULL)
    {
      if (match_alloc(node, size, ptr))
	return (0);
    }
    node = node->prev;
  }
  return (alloc(size, ptr));
}

void			*my_malloc(size_t size)
{
  void			*ptr;

  if (size == 0)
    return (NULL);
  if (last == NULL)
  {
    if (alloc(size, &ptr) == -1)
      return (NULL);
  }
  else
  {
    if (normal_alloc(size, &ptr) == -1)
      return (NULL);
  }
  return (ptr);
}
