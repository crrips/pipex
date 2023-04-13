/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:58:52 by apiloian          #+#    #+#             */
/*   Updated: 2023/04/01 19:58:52 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env)
{
	char	*path;
	int		i;

	path = "PATH=";
	i = 0;
	while (env[i])
	{
		if (*env[i] == 'P')
		{
			if (!(ft_strncmp(path, env[i], 5)))
			{
				path = env[i];
				while (*path != '/')
					path++;
				return (path);
			}
		}
		i++;
	}
	return (0);
}

char	*x_path(t_pipex *pipex, char *argv, char **env)
{
	int		i;
	char	*path;

	i = 0;
	pipex->path = find_path(env);
	pipex->cmd_path = ft_split(pipex->path, ':');
	while (pipex->cmd_path[i])
	{
		pipex->cmd_path[i] = ft_strjoin(pipex->cmd_path[i], "/");
		pipex->cmd_path[i] = ft_strjoin(pipex->cmd_path[i], argv);
		if (access(pipex->cmd_path[i], F_OK) == 0)
		{
			path = pipex->cmd_path[i];
			return (path);
		}
		i++;
	}
	write(1, "command not found\n", 19);
	exit(0);
}

void	opening(t_pipex *pipex, int argc, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		perror("");
		exit(0);
	}
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile == -1)
	{
		perror("");
		exit(0);
	}
}

void	closing(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->infile);
	close(pipex->outfile);
}
