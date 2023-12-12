#include "get_next_line.h"

char *get_next_line(int fd)
{
	size_t	buff_size;
	ssize_t	read_size;
	size_t	i;
	char	*buff;
	char	*tmp;
	char	*str;

	buff_size = 1;
	read_size = NULL;
	tmp = malloc(buff_size * sizeof(char));
	str = malloc(buff_size * sizeof(char));
	i = 0;
	while(read_size > 0)
	{
		read_size = read(fd, buff, buff_size);
			while(buff[i] && buff[i] != "\n")
			{
				tmp[i] = buff[i];
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
