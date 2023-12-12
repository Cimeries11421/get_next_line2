#include "get_next_line.h"

char *get_next_line(int fd)
{
	size_t	buff_size;
	ssize_t	read_size;
	size_t	i;
	char	*buff;
	t_list	*str;
	t_list	*lst;
	

	buff_size = 1;
	read_size = NULL;
	//str = malloc(buff_size * sizeof(char));
	i = 0;
	while(read_size > 0)
	{
		read_size = read(fd, buff, buff_size);
			while(buff[i] && buff[i] != "\n")
			{
				str = ft_lstnew(buff[i]);
				ft_lstadd_back();
				i++;
			}
	}
	

}
void	main(void)
{
	int		fd = open("text.txt", O_RDONLY);
	char	*str = get_next_line(fd);
	printf("%s", str);
}
