#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	static char	*s[1];
	char	*buffer;
	char		*temp;
	int			rv;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	rv = read(fd, buffer, BUFFER_SIZE);
	//printf("stacked : %s\n", s[0]);
	while (rv > 0)
	{
		buffer[rv] = '\0';
		if (!s[0])
			s[0] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(s[0], buffer);
			free(s[0]);
			s[0] = temp;
		}
		if (ft_strchr(s[0], '\n'))
			break ;
		rv = read(fd, buffer, BUFFER_SIZE);
	}
	if (rv < 0)
		return (NULL);
	free(buffer);
	return (ft_strip(s));
}
int	main(void)
{
	int		fd;
	int		j;
	char	*res;

	fd = open("sample2.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	j = 0;
	res = get_next_line(fd);
	while (res)
	{
		printf("<->%s", res);
		j++;
		res = get_next_line(fd);
	}
	return (0);
}
