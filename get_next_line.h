#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // malloc 
#include <string.h>

typedef struct s_list
{
    void            *content;
    struct  s_list  *next;
}t_list;

char	*get_next_line(int fd);
char	*ft_strcpy (char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
t_list	*ft_lstnew(void	*content);
void	ft_lstadd_front(t_list **lst, t_list new);



#endif