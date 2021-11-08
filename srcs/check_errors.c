/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:07:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/08 23:07:27 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	throw_error(const char *error)
{
	perror(error);
	exit(0);
}

void	check_nargs(int argc)
{
	if (argc != NUM_ARGS)
		throw_error(ERROR_ARGS);
}

void	save_cmds(char *cmd1, char *cmd2, s_args *args)
{
	args->cmd1 = ft_split(cmd1, ' ');
	args->cmd2 = ft_split(cmd2, ' ');
}

void	check_permissions(char *cmd1, char *cmd2, s_args *args)
{
	int		i;
	char	*cmd[2];
	int		bool[2];

	i = 0;
	bool[0] = 0;
	bool[1] = 0;
	args->paths = ft_split(CMD_PATH, ':');
	save_cmds(cmd1, cmd2, args);
	while (args->paths[i])
	{
		cmd[0] = ft_strjoin(args->paths[i], args->cmd1[0]);
		cmd[1] = ft_strjoin(args->paths[i], args->cmd2[0]);
		if (!(access(cmd[0], X_OK)))
		{
			free(args->cmd1[0]);
			args->cmd1[0] = ft_strdup(cmd[0]);
			bool[0] = 1;
		}
		free(cmd[0]);
		if (!(access(cmd[1], X_OK)))
		{
			free(args->cmd2[0]);
			args->cmd2[0] = ft_strdup(cmd[1]);
			bool[1] = 1;
		}
		free(cmd[1]);
		i++;
	}
	if (!bool[0] || !bool[1])
		throw_error(CMD_ERROR1);
	double_free(args->paths);
}

void	check_errors(int argc, char **argv, s_args *args)
{
	check_nargs(argc);
	check_permissions(argv[2], argv[3], args);
}
