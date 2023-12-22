#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		i = n - 1;
		while (n--)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (n--)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
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

char	*ft_strjoin_n(char const *s1, char const *s2)
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

char	*ft_strdup(const char *s)
{
	size_t		len_s;
	size_t		i;
	char		*s2;

	len_s = ft_strlen_n((char *)s);
	s2 = malloc(len_s + 1 * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len_s + 1)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}
