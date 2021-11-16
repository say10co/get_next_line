/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:25:53 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/16 22:42:15 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>


char	*get_next_line(int fd)
{
	static char	*s[1];
	char		*buffer;
	char		*temp;
	int			rv;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	rv = read(fd, buffer, BUFFER_SIZE);
	while (rv > 0)
	{
		buffer[rv] = '\0';
		if (!s[0])
			s[0] = ft_strdup(buffer);
		else if (buffer)
		{
			temp = ft_strjoin(s[0], buffer);
			free(s[0]);
			s[0] = temp;
		}
		if (ft_strchr(s[0], '\n'))
			break ;
		rv = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_strip(s, rv, buffer));
}
/*
int	main(int ac, char**arv)
{
	int		fd;
	int		j;
	char	*res;

	ac--;
	fd = open(arv[1], O_RDONLY);
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
	//printf("break? : %s", res);
	return (0);
}
*/
