#include "get_next_line.h"

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if ((unsigned char)c == '\0')
		return ((char *)s);
	if (!*s)
		return (NULL);
	return ((char *)s);
}
size_t	ft_strlen_n(const	char *s)
{
	size_t	i;

	i = 0;
	while(s[i] && s[i] != '\n')
	{
		i++;
	}
	if (s[i] == '\n')
		return (i + 1);
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen_n(s1) + ft_strlen_n(s2);
	//printf("len = %ld\n", len);
	s3 = malloc((len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (*s1)
		s3[i++] = *s1++;
	while (*s2 && *s2 != '\n')
	{
		s3[i++] = *s2++;
	}
	if (*s2 == '\n')
	{	
		s3[i++] = *s2;
	}
	s3[i] = '\0';
	return (s3);
}
/*int	main(void)
{
	char 	*tmp = "Coucou";
	char	*buff = " les pigeons\n";

	//printf("len = %ld", ft_strlen_n(buff));
	char	*str = ft_strjoin(tmp, buff);
	printf("%s_", str);
}*/

