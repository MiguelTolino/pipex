/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:33:02 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/08/25 17:29:35 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define NUM_ARGS 5
#define CMD_PATH "/usr/local/sbin/:/usr/local/bin/:/usr/sbin/:/usr/bin/:/sbin/:/bin/"

#define ERROR_ARGS "Error: Number of arguments invalid"
#define FILE_ERROR "Error: Can't open file or doesn't exists"
#define CMD_ERROR "Error: Number of arguments invalid"
#define NUMBER_ERROR "Error: Number of arguments invalid"
#define CMD_ERROR1 "Error: An issue with cmd1 occurs"
#define CMD_ERROR2 "Error: An issue with cmd2 occurs"

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

void check_errors(int argc, char **argv,s_args *args);
void treat_file1(s_args *args, char *argv);
void throw_error(const char *error);
size_t ft_strlcat(char *dest, const char *src, size_t size);
size_t ft_strlen(const char *str);
char *ft_strdup(const char *s1);
char *ft_strjoin(char const *s1, char const *s2);
void ft_bzero(void *s, size_t n);
char **ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
