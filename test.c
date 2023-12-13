#include "get_next_line.h"
#include <string.h>


void    print_list(t_list *lst)
{
    
    /*if(lst = NULL)
        printf("Liste vide");*/
    while(lst != NULL)
    {
        printf("%s", (char *)lst->content);
        lst = lst->next;
    }
}


int	main(void)
{
	char	buff[7] = "Coucou"
	char	*lst;

	i = 0;
	t_list new = ft_lstnew(buff[i]);	
	ft_lstadd_front(&ptr_lst, new);
	print_list(new);

}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = ft_lstlast(*(alst));
			tmp->next = new;
		}
	}
}