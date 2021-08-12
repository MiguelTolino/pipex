/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:33:02 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/08/11 20:24:04 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define NUM_ARGS 5

#define ERROR_ARGS "Error: Number of arguments invalid"
#define FILE_ERROR "Error: Can't open file or doesn't exists"
#define CMD_ERROR "Error: Number of arguments invalid"
#define NUMBER_ERROR "Error: Number of arguments invalid"

typedef struct s_args
{
	char *buffer;
	int fd_in;
	int fd_out;
	char *cmd1;
	char *cmd2;
	char *file1;
	char *file2;
} s_args;

void check_nargs(int argc);
void treat_cmd(s_args *args, char *argv);
void treat_file1(s_args *args, char *argv);

#endif
