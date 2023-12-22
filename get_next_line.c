#include "get_next_line.h"

char	*clear_buffer(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			ft_strcpy(buff, (buff + i + 1)); //free apres \n ? 
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
	while (buff[i] && buff[i] != '\n')
	{
		tmp[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		tmp[i] = buff[i];
		clear_buffer(buff);
		printf("buff = %s\n", buff);
	}	
	//clear la partie du buffer qui est aller dans tmp.
	return (tmp);
}
char	*fill_line(int fd, char *buff, ssize_t *read_size)
{
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = malloc(1 * sizeof(char));
	tmp[0] = '\0';
	if (buff[0] != '\0')
	{
		tmp = recover_line(buff);
	}	
	while((*read_size = read(fd, buff, BUFFER_SIZE)) && *read_size >= 1) //&& operation prioritaire
	{
		//printf("read_size = %zd\n", *read_size); 
		buff[*read_size] = '\0'; //pour la fin:w de fichier
		str = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = ft_strdup(str); // manque un free a la fin de la ligne  
		if (ft_strchr(buff, '\n'))
		{	
			free(tmp);	
			break;
		}
		
	}
	return (str);

}

char	*get_next_line(int fd)
{
	ssize_t	read_size;
	static char	buff[BUFFER_SIZE + 1]; //pas besoin de \0 pour staticm deja a \0 en static
	char	*line;
	//gestion d'erreur du fd

	line = NULL; 
	line = fill_line(fd, buff, &read_size);
	if (read_size <= 0)
		return (line);
	clear_buffer(buff);
	//printf("\nbuff = %s\n\n", buff);
	return (line);
}
int	main(void)
{
	
	// /******* TEST RECOVER LINE *************

	char	s[] = "Coucou les pigeons\n Morgane ne vient pas travailler\n";
	char	*s2 = '\0'; 
	s2 = recover_line(s, s2);
	printf("%s", s2);

	****************************************/


	/*************TEST STRCPY***************/
	/*char	*buff = "12345\n67";
	printf("%s", clear_buffer(buff));
	
// 	/************TEST GET NEXT LINE**********/
	
// 	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
// 	int		fd = open("text.txt", O_RDONLY);
// 	char	*line = "ouaf";

// //	printf("%d\n", fd);

// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	// printf("%s", clear_buffer(buff));
// 	return 0;
// }