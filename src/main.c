/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:35:48 by ttakami           #+#    #+#             */
/*   Updated: 2022/10/28 19:52:01 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	void	open_pipe(t_fd_info *fd_info);
static	void	validate_args(int argc);
static	void	wait_childproc(void);

int	main(int argc, char **argv, char **envp)
{
	t_fd_info	fd_info;

	validate_args(argc);
	open_fd(argv, &fd_info);
	open_pipe(&fd_info);
	exec_childproc(&fd_info, argv, envp, 0);
	exec_childproc(&fd_info, argv, envp, 1);
	close_fd(&fd_info);
	close_pipe(&fd_info);
	wait_childproc();
	exit(EXIT_SUCCESS);
}

static	void	validate_args(int argc)
{
	if (argc != 5)
		perror_and_exit(NULL, MY_ERR_INPUT);
}

static	void	open_pipe(t_fd_info *f)
{
	if (pipe(f->pipe_fd) < 0)
		perror_and_exit("pipe", NULL);
}

static	void	wait_childproc(void)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (waitpid(-1, NULL, 0) == -1)
			perror_and_exit("wait", NULL);
		i++;
	}
}
