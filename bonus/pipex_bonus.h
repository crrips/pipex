/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:39:24 by apiloian          #+#    #+#             */
/*   Updated: 2023/04/01 19:39:24 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define INT_PIPEX 4242

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	pid1;
	int		fd[INT_PIPEX][2];
	int		infile;
	int		outfile;
	int		cmds;
	char	*path;
	char	**cmd_path;
}		t_pipex;

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*get_next_line(int fd);

void	here_doc(t_pipex *pipex, char *lim, int argc);
char	*x_path(t_pipex *pipex, char *argv, char **env);
void	opening(t_pipex *pipex, int argc, char **argv);
void	closing(t_pipex *pipex);

#endif