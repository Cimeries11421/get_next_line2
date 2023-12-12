#include "get_next_line.h"

char *get_next_line(int fd)
{
	ssize_t	BUFFER_SIZE = 1;
	size_t	i;
	static	char buff[1];
	char	*str;
	
	str = malloc(1);
	i = 0;

	read(fd, buff, BUFFER_SIZE);
	
	while (buff[i] && buff[i] != '\n')
	{
		read(fd, buff, BUFFER_SIZE);
		str = ft_strjoin(str, buff);
		i++;
	}
	return (str);
}

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
//str = malloc(BUFFER_SIZE * sizeof(char));
