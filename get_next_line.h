#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1

#endif

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // malloc 
#include <string.h>


char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_n(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen_n(const	char *s);

#endif
