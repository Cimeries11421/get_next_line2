#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 1
# endif

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // malloc 
#include <string.h>

/*typedef struct s_list
{
    void			*content;
    struct s_list	*next;
}t_list;*/

char	*get_next_line(int fd);
char	*ft_strcpy (char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen_n(const char *str);
char	*ft_strdup(const char *s);

#endif
