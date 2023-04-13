/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:53:55 by apiloian          #+#    #+#             */
/*   Updated: 2023/04/06 12:53:55 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(t_pipex *pipex, char *lim, int argc)
{
	char	*str;

	if (argc > 5)
	{
		pipex->infile = open("heredoc", O_RDWR | O_CREAT, 0644);
		while (1)
		{
			write(1, "pipe heredoc> ", 15);
			str = get_next_line(0);
			if (!str || *str)
			{
				write (1, "\n", 1);
				unlink("heredoc");
				exit (0);
			}
			if (strncmp(lim, str, ft_strlen(str) - 1) == 0
				&& strncmp(lim, str, ft_strlen(lim)) == 0)
			{
				free(str);
				break ;
			}
			write(pipex->infile, str, ft_strlen(str));
			free(str);
		}
		close (pipex->infile);
	}
	else
	{
		write(1, "Error!\nToo few arguments!\n", 27);
		exit(0);
	}
}
