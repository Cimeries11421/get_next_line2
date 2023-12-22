#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

char	*clear_buffer(char *buff)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			len = ft_strlen_n(buff + i + 1);
			ft_memmove(buff, buff + i + 1, len);
		}
		i++;
	}
	while (len < BUFFER_SIZE)
	{
		buff[len] = '\0';
		len++;
	}
	return (buff);
}

char	*new_line(int fd, char *buff, ssize_t *read_size)
{
	char	*tmp;
	char	*line;

	line = NULL;
	tmp = malloc(1 * sizeof(char));
	tmp[0] = '\0';
	while((*read_size = read(fd, buff, BUFFER_SIZE)) && *read_size >= 1)
	{
		buff[*read_size] = '\0';
		printf("tmp = %s", tmp);
		line = ft_strjoin_n(tmp, buff);
		free(tmp);
		tmp = ft_strdup(line);
		if (ft_strchr(buff, '\n'))
		{
			free(tmp);
			break;
		}
	}
	return (line);
}

char	*recover_line(char *buff)
{
	char	*line;
	size_t	i;

	i = 0;
	line = malloc(ft_strlen_n(buff) * sizeof(char));
	while(buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i] = buff[i];
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {'\0'};
	ssize_t		read_size;
	char		*line;

	//gestion d'erreur du fd

	line = NULL;
	if (buff[0] == '\0')
		line = new_line(fd, buff, &read_size);
	else
		line = recover_line(buff);
//	clear_buffer(buff);
	printf("buff = %s\n", buff);
	
	return(line);

}

int	main(void)
{
	/****************TEST FT STRLEN_N**********************/
	
	char	str[16] = "coucou\nROMANE";
	int i = ft_strlen_n(str);
	printf("%d", i);

	int		fd = open("text.txt", O_RDONLY);
	char 	*line = "rat";

	printf("BUFFER_SIZE = %d\n\n", BUFFER_SIZE);

	while (line != NULL)
	{
		line = get_next_line(fd);
		ft_strlen_n(line);
		if (line) printf("line = %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
