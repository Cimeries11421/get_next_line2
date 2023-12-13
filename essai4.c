#include "get_next_line.h"

char	*clear_buffer(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			ft_strcpy(buff, (buff + i + 1));
		i++;
	}
	return (buff);
}

char *get_next_line(int fd)
{
	ssize_t	read_size;
	size_t	i;
	static char	buff[BUFFER_SIZE];
	char	*str;
	char	*tmp;

	read_size = 1;
	str = malloc(BUFFER_SIZE * sizeof(char));
	i = 0;
	while(read_size > 0)
	{ 
		read_size = read(fd, buff, BUFFER_SIZE);
		//printf("read_size = %ld\n",read_size);
		buff[BUFFER_SIZE + 1] = '\0'; 
		//printf("buff = %s\n\n", buff);
		if (ft_strchr(buff, '\n'))
			break;
		str = ft_strjoin(str, buff);
	}
	clear_buffer(buff);
	printf("%s\n", buff);
	return (str);
}
int	main(void)
{
	
	//static char	buff[4] =  "ns\nU";
	int		fd = open("text.txt", O_RDONLY);
	char	*str = get_next_line(fd);
	printf("%s", str);
	//printf("%s", clear_buffer(buff));

	return 0;
}

/*while(buff[i] && read_size != 1)
			{	
				str = ft_strjoin(str, buff);
				//printf("%s\n", tmp);
				i++;
			}
			//i = 0;
			if(buff[i] == '\n')
				break;

*/