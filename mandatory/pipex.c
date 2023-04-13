/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:58:56 by apiloian          #+#    #+#             */
/*   Updated: 2023/04/01 19:58:56 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	piping(t_pipex *pipex, char **argv, char **env, int i)
{
	char	**args;
	char	*path;

	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
	{
		args = ft_split(argv[i], ' ');
		path = x_path(pipex, args[0], env);
		if (i == 2)
		{
			dup2(pipex->infile, STDIN_FILENO);
			dup2(pipex->fd[1], STDOUT_FILENO);
			close(pipex->fd[0]);
			close(pipex->infile);
		}
		else if (i == pipex->cmds - 1)
		{
			dup2(pipex->outfile, STDOUT_FILENO);
			dup2(pipex->fd[0], STDIN_FILENO);
			close(pipex->fd[1]);
			close(pipex->outfile);
		}
		execve(path, args, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	i = 2;
	pipex.cmds = argc - 1;
	if (argc == 5)
	{
		opening(&pipex, argc, argv);
		pipe(pipex.fd);
		while (i < pipex.cmds)
			piping(&pipex, argv, env, i++);
		closing(&pipex);
		while (wait(NULL) != -1)
			;
	}
	else
		write(1, "Error!\nIncorrect number of arguments!\n", 39);
	return (0);
}
