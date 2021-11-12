/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:32:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/12 13:50:52 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex < file1 cmd1 cmd2 file2

void	child_process(int *fd, t_args *args, char **envp)
{
	close(fd[READ_END]);
	if (dup2(args->fd_in, STDIN_FILENO) < 0)
		throw_error("Error:");
	close(args->fd_in);
	if (dup2(fd[WRITE_END], STDOUT_FILENO) < 0)
		throw_error("Error:");
	close(fd[WRITE_END]);
	if (execve(args->cmd1[0], args->cmd1, envp) < 0)
		throw_error("Execution Failed");
}

void	parent_process(int *fd, int pid, t_args *args, char **envp)
{
	close(fd[WRITE_END]);
	pid = fork();
	if (!pid)
	{
		close(fd[WRITE_END]);
		if (dup2(fd[READ_END], STDIN_FILENO) < 0)
			throw_error("Error:");
		close(fd[READ_END]);
		if (dup2(args->fd_out, STDOUT_FILENO) < 0)
			throw_error("Error");
		if (execve(args->cmd2[0], args->cmd2, envp) < 0)
			throw_error("Execution Failed");
	}
	else if (pid > 0)
	{
		close(fd[READ_END]);
		close(fd[WRITE_END]);
	}
	else
		throw_error("Error en hijo 2");
}

int	main(int argc, char *argv[], char *envp[])
{
	struct t_args	args;
	int				fd[2];
	pid_t			pid;
	int				status;

	check_errors(argc, argv, envp, &args);
	args.fd_in = open_file_in(argv[1]);
	if (pipe(fd) < 0)
		throw_error("Pipe Error");
	pid = fork();
	if (!pid)
		child_process(fd, &args, envp);
	else if (pid > 0)
	{
		args.fd_out = open_file_out(argv[4]);
		parent_process(fd, pid, &args, envp);
	}
	else
		throw_error("Error en fork");
	wait(&status);
	wait(&status);
	double_free(args.cmd1);
	double_free(args.cmd2);
	return (0);
}
