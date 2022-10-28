/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:23:55 by ttakami           #+#    #+#             */
/*   Updated: 2022/10/28 19:58:02 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"

# define MY_ERR_INPUT "invalid number of arguments\n"
# define MY_ERR_CMD ": command not found\n"

typedef struct s_fd_info
{
	int	input_fd;
	int	output_fd;
	int	pipe_fd[2];
}		t_fd_info;

void	open_fd(char **argv, t_fd_info *f);
void	close_fd(t_fd_info *f);
void	close_pipe(t_fd_info *f);
void	perror_and_exit(char *err_name, char *my_err_msg);
void	exec_childproc(t_fd_info *f, char **argv, char **envp, int is_second);

#endif
