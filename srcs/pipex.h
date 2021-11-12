/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:33:02 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/12 13:41:33 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../lib/libft/libft.h"

# define NUM_ARGS 5
# define READ_END 0
# define WRITE_END 1

# define ERROR_ARGS "Error: Number of arguments invalid"
# define FILE_ERROR "Error: Can't open file or doesn't exists"
# define CMD_ERROR "Error: Number of arguments invalid"
# define NUMBER_ERROR "Error: Number of arguments invalid"
# define CMD_ERROR1 "Error: An issue with cmd occurs"
# define CMD_ERROR2 "Error: An issue with cmd2 occurs"

typedef struct t_args
{
	int		fd_in;
	int		fd_out;
	char	**cmd1;
	char	**cmd2;
	char	**paths;
}		t_args;

int		double_free(char **array);
void	check_errors(int argc, char **argv, char **envp, t_args *args);
void	check_permissions(char *cmd1, char *cmd2, t_args *args);
int		open_file_in(char *argv);
int		open_file_out(char *argv);
void	throw_error(const char *error);
char	**search_paths(char **envp);

#endif