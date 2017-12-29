/*
** my.h for my.h in /home/lblanchard/CPool_Day09/include
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Thu Oct 13 09:19:01 2016 Leandre Blanchard
** Last update Mon Dec 25 02:04:47 2017 Léandre Blanchard
*/

#ifndef MY_H_
# define MY_H_

# ifdef __cplusplus
extern "C" {
#endif
/* only here to remove the automatic fcking emacs indentation, Best regards */
# ifdef __horriblethingwithemacs
}
#endif
# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

/*
** Return a server socket on port <port>
** Returns -1 on error
*/
int	create_server(uint16_t port);

/*
** Return a socket when a new client is connected, <sockfd> is the server fd
** <backlog> argument defines the length of the kernel pending queue
** Returns -1 on error
*/
int	accept_client(int sockfd, int backlog);

/*
** Try to connect to the server <ip> on <port> and return a client socket
** Return -1 on error
*/
int	connect_to(const char *ip, uint16_t port);

/* swap the inside of both values swap(&i, &j) */
void	swap(void *a, void *b);

/* man 3 memset */
void	my_memset(void *ptr, int value, size_t size);

/*
** Isacmd returns 1 if the cmd exist in $PATH
** return 0 otherwise
*/
int	isacmd(const char *str);

/*
** Sets the correct ioctl config for get_cmd command
** Return -1 o error
*/
int	routine_ioctl(void);

/*
** Runs a get_next_line shell like handle arrows
** cmds in a tab of char * of previous cmds, it can be NULL
** and so arrows up and down will navigate in it
** return NULL if quit or on ERROR
*/
char	*get_cmd(char **cmds, const char *prompt);

/*
** Returns the ip of the interface, if interface is NULL,
** returns the first valid ip it finds
** Return NULL on error
*/
char	*get_ip(const char *interface);

/* Safefree free the *ptr pointer and set the value to NULL, take the adress of a ptr*/
void	sfree(void *ptr);

/*
** Saves the given tab line per line with a \n in the <pathname> file
** Return -1 on error
*/
int	save_file(char **file, const char *pathname);

/*
** Replace all occurences of <str> in <src> by <repl>
** This function allocate memory in most cases
** Return NULL on error
*/
char	*replace(char *src, const char *str, const char *repl);

/* 
** Load an entire file and allocate the memory to store it
** Returns NULL on error
*/
void	*file_data(const char *pathname);

/* Returns the byte corresponding to the ASCII binary representation given in parameter */
char	bin_to_char(const char *binary);

/* 
** Returns an allocated pointer that contain the ASCII representation of the given byte
** Returns NULL on error
*/
char	*char_to_bin(char n);

/*
** More special printf with flags :
** %s %d %c %p %f printf original flags
** %F: frees the given parameter
** %S: does same as %s and frees the pointer after
** %k: does a formated %s, 2 parameters must be given, a char * and an int
** %T: does a put_tab on the given <char **>
** %D: change the fd of the output, can be used anywhere in the format string
** new_printf("%Dfoo%Dbar\n", 2, 1); will write foo into stderr and bar\n into stdout
** This function call my_dprintf(1, char *format, ...);
** Returns -1 on error, thins functions handles NULL pointers;
*/
int	new_printf(const char *format, ...);

/* 
** Writes the given [size] bytes from [data] into the given
** [pathname] file
** Returns -1 on error
*/
int	save_as(const char *pathname, const void *data, int size);

/* 
** Removes all <str> occurences inside of <src>
** remove_str("test", "t") will change the bytes stored into [src]
** giving "es\0\0\0", this function foes not allocate memory
** returns -1 on error
*/
int	remove_str(char *src, const char *del);

/*
** Works as new_printf with the same arguments, well, typically
** it's the same as using the %D flag of new_printf
** Returns -1 on error
*/
int	my_dprintf(int fd, const char *format, ...);

/* 
** This function works as sprintf but instead of filling the given pointer
** as sprintf does, it allocates the needed memory and returns a pointer filled
** with the result, the possible flags are :
** %s: to add a string
** %d: to add a number (ASCII represetation)
** %F: to free the given parameter
** %c: to add a character
** Returns NULL on error
*/
char	*catalloc(const char *format, ...);

/* 
** Sort the given [tab] in ascending order using strcmp
** Returns 0
*/
int	sort_tab(char **tabptr);

/* 
** Load all filenames that are into the [dirname] directory
** into an allocated NULL terminated tab
** Returns NULL on error
*/
char	**dir_filenames(const char *dirname, bool sort);

/*
** Allocate strlen(str) + size bytes,
** set all of the unused bytes to 0 and 
** frees the given [str] the new allocated one
** Returns NULL on error
*/
char	*my_frealloc(char *str, int size);

/*
** Insert str into src, moving the content so no byte is lose.
** If pos > strlen(src) it will allocate enough memory to store str
** at str + pos, each non initialized character between those 2 ptr is set to 0
** This function free the given char *src
** if str == NULL, returns src, if src == NULL returns NULL
** Returns NULL on error
*/
char	*insert(char *src, const char *str, int pos);

/*
** Same as memcpy, this function does not allow you to write datas in
** the same buffer that you are retrieving them from
** Returns -1 on error
*/
int	memcopy(void *to, const void *from, int size);

/*
** Uses Xclip and system call to add the given [str] ptr into your clipboard
** using the X environnement
** Returns -1 on error
*/
int	add_to_clipboard(const char *str);

/*
** Returns the amount of times the [cmp] characters is present in the
** \0 terminated [s] string
** Returns -1 on error (NULL ptr for example)
*/
int	nb_of(const char *s, char cmp);

/* my malloc and my free, using only sbrk */
void	*my_malloc(size_t size);
int	my_free(void *ptr);
/* free all my_malloc allocated pointers */
int	my_frees(void);
/* my_stack gives you the opportunity to see what's inside your my_malloc stack */
void	my_stack(void);

/* 
** Displays the inside of the pointed [buf] memory first [size] bytes
** format can be either "%c" or "%d"
** "%c" displays the character instead of the value of the byte
** if this one is displayable (not negative values for example)
** "%d" will displays the values that are inside each bytes
** The display format is [<byte1>][<byte2>][<byte3>] ...
** Returns -1 on error
*/
int	display_inside(const void *buf, const char *format, size_t size);

/* Returns the largest strlen(tab[i]) found into the NULL terminated tab */
int	max_len(char **tabptr);

/* 
** Same as strdup but for a tab, it is NULL terminated
** Returns NULL on error
*/
char	**tabdup(char **tabptr);

/*
** Returns an allocated tab containing the [pathname] file
** tab[0] will contain the first [pathname] file line
** the original '\n' is replaced with a 0
** Returns NULL on error
*/
char	**load_file(const char *pathname);

/*
** Returns the given [pathname] file size using read to avoid STAT(2)
** Returns -1 on error
*/
int	file_size(const char *pathname);

/*
** Revert all positions of the strings inside of the given tab
** tab[0] became tab[LAST] ...
** Returns -1 on error
*/
int	revtab(char **tabptr);

/*
** Frees the given tab ptr and store the previous values inside a new
** allocated tab, that will contain 1 more place to store the given [add]
** string, this function does not strdup the [add] string
** if [tab] is NULL, it returns an allocated tab that contains
** [add] in index 0
** The tab is NULL terminated
** Returns NULL on error
*/
void	*tab_append(void *tabptr, void *add);

/*
** This function remove the char * at tab[index] and frees it
** without letting a blank by moving the other indexes
** This function does not allocate memory
** return -1 on Error
**
*/
int	tab_remove(void *tabptr, int index);

/*
** Returns 1 if the end of the [s] string match the
** [end] string like end_with("foo.mp3", ".mp3);
** Returns 0 if not :)
*/
bool	end_with(const char *s, const char *end);

/*
** Kinda same as my_realloc but with a tab, so you can add
** more space to store more pointers,
** Return NULL on error
*/
char	**tab_realloc(char **tabptr, int add);

/*
** Same as file_data but with a fd
** This function uses lseek
** Returns -1 on error
*/
char    *complete_read_lseek(int fd);

char	**my_str_to_wordtab(const char *s, int no);

/*
** Removes all non-ASCII characters
*/
int	rm_ascii(char *);

/*
** shift_left("foo", 1) gives "oo\0\0"
** Returns -1 on error
*/
void	shift_left(char *, int);

/*
** shift_right("foo", 1) gives "fo\0\0"
** Returns -1 on error
*/
void	shift_right(char *, int);

char	*get_next_line(int);

void	my_clear(void);

/*
** Same as frealloc but does not free the given string
** Returns NULL on error
*/
char	*my_realloc(const char *, int);

/* Calloc using 0 by default */
void	*my_calloc(size_t size);

/* 
** Returns an allocated string containing the ASCII representation
** of the given int, same as catalloc("%d", ..);
** Returns NULL on error
**/
char	*int_char(int);

/*
** Returns the additionned strlen of all strings of the tab
** Returns -1 on error
*/
int	my_total_len(char **);

/*
** Puts all strings of the given tab into a single one,
** one after the other.
** Returns NULL on error
*/
char	*my_tab_to_str(char **);

/*
** Returns the size that the int would take in the memory if it was
** stored in his ASCII representation,
** my_int_len(-42) returns 3, for the '-', the '4' and the '2'
*/
int	my_intlen(int);

/*
** Free each pointers of the tab, and then free
** the tab ptr
*/
void	free_tab(void *tabaddr);

/*
** Allocate a tab with [nlines] lines of [nlength] size each one
** They are all allocated and each byte is set to 0
** The tab is NULL terminated
** Returns NULL on error
*/
char	**my_alloc_tab(int nlines, int nlength);

/*
** man 3 atof
*/
float	my_get_float(const char *);

char	*convert_endian_str(int);

int	convert_endian(int);

/*
** Removes all useless spaces and \t of a string
** Does not allocate
** Uses shift_left/right
** Returns -1 on error
*/
int	epur_str(char *);

int	total_name(const char *);

/*
** Man 3 bzero
*/
int	zeros(void *ptr, size_t size);

void	my_putchar(char);

void	my_put_nbr(int);

int	my_putstr(const char *);

/* NULL proof strlen, returns 0 if argument is NULL */
size_t	my_strlen(const char *str);
size_t	my_kstrlen(const char *str, char k);

/* man atoi */
int	my_getnbr(const char *);

/* NULL proof strcpy */
int	my_strcpy(char *, const char *);

/* NULL proff strncpy */
char	*my_strncpy(char *, const char *, int);

/* man 3 strstr */
char	*my_strstr(const char *str, const char *to_find);

/* NULL proof strcmp */
int	my_strcmp(const char *, const char *);

/* NULL proof strncmp */
int	my_strncmp(const char *, const char *, int);

/* NULL proof strcat */
int	my_strcat(char *dest, const char *src);

/* NULL proof strncat */
int	my_strncat(char *dest, const char *src, int n);

/* man 3 strdup */
char	*my_strdup(const char *src);
char	*my_strndup(const char *src, int size);

/* Reverse the order of the characters in str */
char	*revstr(char *str);

/* Returns the size of a NULL terminated tab */
size_t	tablen(void *tabptr);

/* Put a tab using \n for each lines */
void	put_tab(char **tabptr);

/* Puts each line of tab till NULL preceded by <start> and followed by <end> */
void	put_tabw(const char *start,
		      char **tabptr,
		      const char *end);

#ifdef __cplusplus
}
#endif

#endif /* !MY_H_ */
