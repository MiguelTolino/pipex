/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_permissions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:40:57 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/12 13:47:36 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_access(t_args *args, char **cmd, int *bool)
{
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
}

int	*check_commands(t_args *args)
{
	int		i;
	int		*bool;
	char	*cmd[2];

	bool = (int *)calloc(2, sizeof(int));
	i = 0;
	while (args->paths[i])
	{
		cmd[0] = ft_strjoin(args->paths[i], args->cmd1[0]);
		cmd[1] = ft_strjoin(args->paths[i], args->cmd2[0]);
		check_access(args, cmd, bool);
		free(cmd[1]);
		i++;
	}
	return (bool);
}

void	check_permissions(char *cmd1, char *cmd2, t_args *args)
{
	int	*bool;

	args->cmd1 = ft_split(cmd1, ' ');
	args->cmd2 = ft_split(cmd2, ' ');
	bool = check_commands(args);
	if (!bool[0] || !bool[1])
		throw_error(CMD_ERROR1);
	double_free(args->paths);
	free(bool);
}
