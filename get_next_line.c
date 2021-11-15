/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:00:01 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/15 16:06:55 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char *s[1];
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			rv;

	rv = read(fd, buffer, BUFFER_SIZE);
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
		if (ft_strchr(buffer, '\n'))
			break ;
		rv = read(fd, buffer, BUFFER_SIZE);
	}
	if (rv <= 0)
		return (s[0]);
	return (ft_strip(s, BUFFER_SIZE));
}

int main(void)
{
	int		fd;
	int		j;
	char	*res;

	fd = open("test.txt", O_WRONLY);
	if(fd < 0)
		return (0);
	j = 0;
	while (j < 2)
	{	
		res = get_next_line(fd);
		printf("<->%s\n", res);
		j++;
	}
	return (0);
}
