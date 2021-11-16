/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:57:21 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/16 21:54:08 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	index;
	unsigned int	s_len;

	if (!s)
		return (0);
	index = 0;
	s_len = strlen(s);
	if (s_len < len)
		len = s_len;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	while (index < len && start < s_len && s[index])
	{
		substr[index] = s[start];
		start++;
		index++;
	}
	substr[index] = '\0';
	return (substr);
}
