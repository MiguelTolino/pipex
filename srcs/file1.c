/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:12:23 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/08/17 12:05:37 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>
#define BUFF_SIZE 256

int open_file(char *argv)
{
	int fd;

	fd = open(argv, O_RDWR);
	if (fd < 0)
		throw_error(FILE_ERROR);
	return (fd);
}

void read_file(s_args *args)
{
	char *buff;
	char *aux;
	ssize_t bytes;

	args->file1 = ft_strdup("");
	buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
	while ((bytes = read(args->fd_in, buff, BUFF_SIZE)) > 0)
	{
		aux = ft_strjoin(args->file1, buff);
		free(args->file1);
		args->file1 = aux;
		ft_bzero(buff, BUFF_SIZE);
	}
	free(buff);
}

void treat_file1(s_args *args, char *argv)
{
	args->fd_in = open_file(argv);
	read_file(args);
	close(args->fd_in);
}
