#include "get_next_line.h"
#include <string.h>

char *get_next_line(int fd)
{
	ssize_t BUFFER_SIZE = 15;
	char	buff[BUFFER_SIZE]; // memoire tampon
	char	*buff2;
	read (fd, buff, BUFFER_SIZE);
	buff2 = malloc(strlen(buff) * sizeof(char));
	strcpy(buff2, buff);	
	return (buff2);
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY); // fd plaque d'immatriculation, fd = 3 (normalement). Cree un lien avec de la memoire morte.
	printf("%s", get_next_line(fd));
}