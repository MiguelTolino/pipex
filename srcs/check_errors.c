/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:07:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/09/06 12:15:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void throw_error(const char *error)
{
	perror(error);
	exit(0);
}

void check_nargs(int argc)
{
	if (argc != NUM_ARGS)
		throw_error(ERROR_ARGS);
}

void save_cmds(char *cmd1, char *cmd2, s_args *args)
{
	args->cmd1 = ft_split(cmd1, ' ');
	args->cmd2 = ft_split(cmd2, ' ');
}
void check_permissions(char *cmd1, char *cmd2, s_args *args)
{
	char **split;
	char *cmd[2];
	int bool[2];

	bool[0] = 0;
	bool[1] = 0;
	split = ft_split(CMD_PATH, ':');
	save_cmds(cmd1, cmd2, args);

	while (*split)
	{
		cmd[0] = ft_strjoin(*split, args->cmd1[0]);
		cmd[1] = ft_strjoin(*split, args->cmd2[0]);

		if (!(access(cmd[0], X_OK)))
		{
			args->cmd1[0] = ft_strdup(cmd[0]);
			bool[0] = 1;
		}
		if (!(access(cmd[1], X_OK)))
		{
			args->cmd2[0] = ft_strdup(cmd[1]);
			bool[1] = 1;
		}
		split++;
	}
	if (!bool[0] || !bool[1])
		throw_error(CMD_ERROR1);
}

void check_errors(int argc, char **argv, s_args *args)
{
	check_nargs(argc);
	check_permissions(argv[2], argv[3], args);
}