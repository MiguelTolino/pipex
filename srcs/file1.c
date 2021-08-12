/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:12:23 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/08/11 20:48:04 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int open_file(char *argv) {
	int fd;

	fd = open(argv, O_RDWR);
	if (fd < 0)
	{
		perror(FILE_ERROR);
		exit(1);
	}
	return (fd);
}

char *save_filename(char *argv){
	int len;
	char *str;

	len = 0;
	while (argv[len])
		len++;
	str = (char*)malloc(sizeof(char) * len);
	while (*argv)
	{
		*str = *argv;
		str++;
		argv++;
	}
	*str = '\0';
	return(str);
}

void read_file(s_args *args){
	char *buff;
	ssize_t bytes;

	buff = (char*)malloc(sizeof(char) * 256);
	while( (bytes = read(args->fd_in, buff, 256)) > 0)
		printf("%s", buff);
}

void treat_file1(s_args *args, char *argv) {
	args->fd_in = open_file(argv);
	args->file1 = save_filename(argv);
	read_file(args);
	close(args->fd_in);
}
