/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_childproc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:17:28 by ttakami           #+#    #+#             */
/*   Updated: 2022/10/28 19:51:59 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	void	set_stdio_fd(t_fd_info *f, int is_second);
static	void	*free_twodarray(char **s);
static	char	*get_cmd_path(char *cmd_name, char **envp);
static	void	executor(char **argv, char **envp, int is_second);

void	exec_childproc(t_fd_info *f, char **argv, char **envp, int is_second)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror_and_exit("fork", NULL);
	if (!pid)
	{
		set_stdio_fd(f, is_second);
		close_fd(f);
		close_pipe(f);
		executor(argv, envp, is_second);
	}
}

static	void	set_stdio_fd(t_fd_info *f, int is_second)
{
	if (!is_second)
	{
		if (dup2(f->input_fd, STDIN_FILENO) == -1)
			perror_and_exit("dup2", NULL);
		if (dup2(f->pipe_fd[1], STDOUT_FILENO) == -1)
			perror_and_exit("dup2", NULL);
	}
	else
	{
		if (dup2(f->pipe_fd[0], STDIN_FILENO) == -1)
			perror_and_exit("dup2", NULL);
		if (dup2(f->output_fd, STDOUT_FILENO) == -1)
			perror_and_exit("dup2", NULL);
	}
}

static	void	*free_twodarray(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static	char	*get_cmd_path(char *cmd_name, char **envp)
{
	char	**all_paths;
	char	*tmp;
	char	*result;

	while (ft_strncmp("PATH=", *envp, 5) != 0)
		envp++;
	all_paths = ft_split((*envp + 5), ':');
	if (!all_paths)
		return (NULL);
	while (*all_paths)
	{
		tmp = ft_strjoin(*all_paths, "/");
		if (!tmp)
			return (free_twodarray(all_paths));
		result = ft_strjoin(tmp, cmd_name);
		free(tmp);
		if (!result)
			return (free_twodarray(all_paths));
		if (access(result, F_OK) == 0)
			return (result);
		free(result);
		all_paths++;
	}
	return (ft_strdup(cmd_name));
}

static	void	executor(char **argv, char **envp, int is_second)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(argv[2 + is_second], ' ');
	if (!cmd_args)
		perror_and_exit("ft_split", NULL);
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		free_twodarray(cmd_args);
		perror_and_exit("malloc", NULL);
	}
	if (access(cmd_path, F_OK) != 0)
	{
		free_twodarray(cmd_args);
		perror_and_exit(cmd_path, MY_ERR_CMD);
	}
	execve(cmd_path, cmd_args, envp);
	free(cmd_path);
	free_twodarray(cmd_args);
	perror_and_exit("execve", NULL);
}
