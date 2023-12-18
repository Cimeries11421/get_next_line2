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
char	*recover_line(char *buff, char *tmp)
{
	size_t	len;
	size_t	i;

	free(tmp);
	len = ft_strlen_n(buff);
	tmp = malloc(len * sizeof(char));
	i = 0;
	while (buff[i])
	{
		tmp[i] = buff[i];
		i++;
	}
	return (tmp);
}
char	*get_next_line(int fd)
{
	ssize_t	read_size;
	size_t	i;
	static char	buff[BUFFER_SIZE] = {'\0'};
	char	*str;
	char	*tmp;

	read_size = 1;
	str = malloc(BUFFER_SIZE * sizeof(char));
	tmp = malloc(BUFFER_SIZE * sizeof(char));
	if (buff[0] != '\0')
		tmp = recover_line(buff, tmp);
	i = 0;
	while(read_size > 0)
	{ 
		read_size = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE + 1] = '\0'; 
		str = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = strdup(str);
	if (ft_strchr(buff, '\n'))
			break;
	}
	clear_buffer(buff);
	printf("buff = %s\n", buff);
	return (str);
}
int	main(void)
{
	
	/******* TEST RECOVER LINE *************

	char	s[] = "coucou";
	char	*s2 = '\0'; 
	s2 = recover_line(s, s2);
	printf("%s", s2);

	****************************************/	
	
	/************TEST GET NEXT LINE**********/
	
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	int		fd = open("text.txt", O_RDONLY);
	char	*line;
	size_t	i = 3;

	while (i--)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	//printf("%s", clear_buffer(buff));*/
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