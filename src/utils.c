/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:11:04 by ttakami           #+#    #+#             */
/*   Updated: 2022/10/28 19:59:45 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_fd(char **argv, t_fd_info *f)
{
	f->input_fd = open(argv[1], O_RDONLY);
	if (f->input_fd < 0)
		perror_and_exit(argv[1], NULL);
	f->output_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (f->output_fd < 0)
		perror_and_exit(argv[4], NULL);
}

void	close_fd(t_fd_info *f)
{
	if (close(f->input_fd) == -1)
		perror_and_exit("close", NULL);
	if (close(f->output_fd) == -1)
		perror_and_exit("close", NULL);
}

void	close_pipe(t_fd_info *f)
{
	size_t	i;

	i = 0;
	while (i < 2)
	{
		if (close(f->pipe_fd[i]) == -1)
			perror_and_exit("close", NULL);
		i++;
	}
}

void	perror_and_exit(char *err_name, char *my_err_msg)
{
	char	*msg;

	ft_putstr_fd("\x1b[31m", STDERR_FILENO);
	if (my_err_msg)
	{
		if (err_name)
		{
			msg = ft_strjoin(err_name, my_err_msg);
			if (!msg)
				perror_and_exit("malloc", NULL);
			free(err_name);
			ft_putstr_fd(msg, STDERR_FILENO);
		}
		else
			ft_putstr_fd(my_err_msg, STDERR_FILENO);
	}
	else
		perror(err_name);
	ft_putstr_fd("\x1b[39m", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
