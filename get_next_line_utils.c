#include "get_next_line.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if(!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if(*lst)

	new->next = *lst;
	*lst = new;
}
int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while(lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while((*lst)->next != NULL)
		*lst = (*lst)->next;  //étoile dans la parenthèse pour pas déréferencer lst->ext 
	(*lst)->next = new;
}


void	main(void)
{
	t_list *lst;
	t_list *new;
	
	lst = ft_lstnew("bobie");
	new = ft_lstnew("bob");
	ft_lstadd_back(&lst, new);
	while(lst != NULL)
	{
		printf("%s", (char*)lst->content);
		lst = lst->next; 
	}
}

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc((len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

