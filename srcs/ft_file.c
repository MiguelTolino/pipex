/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:12:23 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/09/06 13:07:40 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int open_file_in(char *argv)
{
	int fd;

	fd = open(argv, O_RDWR);
	if (fd < 0)
		throw_error(FILE_ERROR);
	return (fd);
}

int open_file_out(char *argv)
{
	int fd;

	fd = open(argv, O_WRONLY | O_CREAT, 0622);
	if (fd < 0)
		throw_error(FILE_ERROR);
	return (fd);
}
