/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:27:59 by apiloian          #+#    #+#             */
/*   Updated: 2023/04/08 14:12:34 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

int	word(int count, int i, char *s, char c)
{
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
		else
		{
			while (s[i] == c)
				i++;
		}
	}
	return (count);
}

char	**count_fill(int index, int i, char *s, char c)
{
	int		start;
	char	**split;

	split = malloc((word(0, 0, s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			split[index] = ft_substr(s, start, i - start);
			index++;
		}
	}
	split[index] = NULL;
	return (split);
}

char	**ft_split(char *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = count_fill(0, 0, (char *)s, c);
	if (!split)
		return (0);
	return (split);
}
