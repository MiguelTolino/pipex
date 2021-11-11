/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:32:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/11 13:49:40 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	struct t_args	args;
	int				fd[2];
	int				pid;
	int				status;

	args.paths = envp;
	check_errors(argc, argv, &args);
	args.fd_in = open_file_in(argv[1]);
	if (pipe(fd) < 0)
		throw_error("Error en pipe");
	if (!(pid = fork())) //Hijo 1
	{
		if (dup2(args.fd_in, STDIN_FILENO) < 0)
			throw_error("Error:");
		close(fd[READ_END]);
		if (dup2(fd[WRITE_END], STDOUT_FILENO) < 0)
			throw_error("Error:");
		close(fd[WRITE_END]);
		execve(args.cmd1[0], args.cmd1, 0);
		throw_error("Execution Failed");
	}
	else if (pid > 0) //Padre -- Proceso principal
	{
		close(fd[WRITE_END]);
		if (!(pid = fork())) //hijo 2
		{
			args.fd_out = open_file_out(argv[4]);
			if (dup2(fd[READ_END], STDIN_FILENO) < 0)
				throw_error("Error:");
			close(fd[READ_END]);
			if (dup2(args.fd_out, STDOUT_FILENO) < 0)
				throw_error("Error");
			execve(args.cmd2[0], args.cmd2, 0);
			throw_error("Execution Failed");
		}
		else if (pid > 0) //padre
			close(fd[READ_END]);
		else
			throw_error("Error en hijo 2");
	}
	else
		throw_error("Error en fork");
	wait(&status);
	wait(&status);
	//close(args.fd_in);
	//close(args.fd_out);
	double_free(args.cmd1);
	double_free(args.cmd2);
	return (0);
}
