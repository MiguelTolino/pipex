/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:07:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/12 13:41:18 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	throw_error(const char *error)
{
	perror(error);
	exit(1);
}

void	check_nargs(int argc)
{
	if (argc != NUM_ARGS)
		throw_error(ERROR_ARGS);
}

void	check_errors(int argc, char **argv, char **envp, t_args *args)
{
	check_nargs(argc);
	args->paths = search_paths(envp);
	if (!args->paths)
		throw_error("Program could not detect $PATH");
	check_permissions(argv[2], argv[3], args);
}
