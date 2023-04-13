/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:47:41 by apiloian          #+#    #+#             */
/*   Updated: 2023/02/20 15:47:41 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr_gnl(char *s, unsigned int start, size_t len, int flag)
{
	char	*str;

	if (!s || !*s)
		return (0);
	if (start > ft_strlen_gnl(s))
		len = 0;
	if (len > ft_strlen_gnl(s + start))
		len = ft_strlen_gnl(s + start);
	str = malloc(len + 1);
	if (!str)
		return (0);
	ft_strlcpy_gnl(str, s + start, len + 1, flag);
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int i, int j)
{
	char	*new_str;

	if (!s1 || !s2 || !*s1 || !*s2)
		return (0);
	new_str = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!new_str)
		return (0);
	while (s1[j])
	{
		new_str[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = 0;
	free(s1);
	return (new_str);
}

char	*fill(char *ret, char *buf, char **str, int fd)
{
	int	i;

	if (*str != NULL && **str)
	{
		ft_strcpy(buf, *str);
		free (*str);
		*str = NULL;
	}
	else
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0 && ret == NULL)
		{
			free(*str);
			*str = NULL;
			return (NULL);
		}
		buf[i] = 0;
	}
	return (buf);
}

char	*check(char *ret, char *buf, int *i)
{
	if (!ret)
		ret = ft_strdup(buf);
	else
		ret = ft_strjoin_gnl(ret, buf, 0, 0);
	*i = 0;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char		*str = NULL;
	char			*ret;
	int				i;
	char			buf[BUFFER_SIZE + 1];

	ret = NULL;
	while (1)
	{
		if (fill(ret, buf, &str, fd) == NULL)
			return (NULL);
		if (!*buf)
			return (ret);
		ret = check(ret, buf, &i);
		while (ret[i])
		{
			if (ret[i] == '\n')
			{
				free(str);
				str = ft_substr_gnl(ret, i + 1, ft_strlen_gnl(ret), 0);
				ret = ft_substr_gnl(ret, 0, i + 1, 1);
				return (ret);
			}
			i++;
		}
	}
}
