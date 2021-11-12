/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:12:23 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/12 18:55:40 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

int	open_file_in(char *argv)
{
	int	fd;

	fd = open(argv, O_RDWR);
	if (fd < 0)
		throw_error(argv);
	return (fd);
}

int	open_file_out(char *argv)
{
	int	fd;

	fd = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		throw_error(argv);
	return (fd);
}
