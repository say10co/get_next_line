/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:00:01 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/13 23:34:37 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*temp;
	char		*line;
	int			rv;

	line = (char *)malloc(BUFFER_SIZE);
	rv = read(fd, buffer, BUFFER_SIZE);
	while (rv > 0)
	{
		if (!line)
			line = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(line, buffer);
			if (!temp)
				return (NULL);
			free(line);
			line = temp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		rv = read(fd, buffer, BUFFER_SIZE);
	}
	if (rv < 0)
		return (NULL);
	return (ft_rstrip(line));
}

int main(void)
{
	int		fd;
	char	*res;

	fd = open("sample3.txt", O_RDONLY);
	if(fd < 0)
		return (0);
	
	res = get_next_line(fd);
	printf("%s\n", res);
	return (0);
}
