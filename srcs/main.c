/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:32:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/09/06 13:06:41 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[])
{

	struct s_args args;
	int fd[2];
	int pid;
	int status;

	check_errors(argc, argv, &args);
	args.fd_in = open_file_in(argv[1]);
	if (pipe(fd) < 0)
		throw_error("Error en pipe");
	if (!(pid = fork())) //Hijo 1
	{
		close(fd[READ_END]);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		execve(args.cmd1[0], args.cmd1, 0);
	}
	else if (pid > 0) //Padre -- Proceso principal
	{
		close(fd[WRITE_END]);
		if (!(pid = fork())) //hijo 2
		{
			args.fd_out = open_file_out(argv[4]);
			dup2(fd[READ_END], STDIN_FILENO);
			close(fd[READ_END]);
			dup2(args.fd_out, STDOUT_FILENO);
			execve(args.cmd2[0], args.cmd2, 0);
		}
		else if(pid > 0) //padre
		{
			close(fd[READ_END]);
		}
		else
			throw_error("Error en hijo 2");
		}
	else
		throw_error("Error en fork");
	wait(&status);
	wait(&status);
	close(args.fd_in);
	close(args.fd_out);
	return (0);
	}
