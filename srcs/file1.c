/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:12:23 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/08/16 18:57:14 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

int open_file(char *argv)
{
	int fd;

	fd = open(argv, O_RDWR);
	if (fd < 0)
	{
		perror(FILE_ERROR);
		exit(1);
	}
	return (fd);
}

void read_file(s_args *args)
{
	char *buff;
	char *aux;
	ssize_t bytes;

	args->file1 = ft_strdup("");
	aux = ft_strdup("");
	buff = (char *)malloc(sizeof(char) * 256);
	while ((bytes = read(args->fd_in, buff, 256)) >= 0)
	{
		if (bytes == 0)
			break;
		aux = ft_strjoin(args->file1, buff);
		free(args->file1);
		args->file1 = aux;
	}
	free(buff);
	printf("%s", args->file1);
}

void treat_file1(s_args *args, char *argv)
{
	args->fd_in = open_file(argv);
	read_file(args);
	close(args->fd_in);
}
