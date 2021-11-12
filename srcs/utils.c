/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:05:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/12 12:08:40 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	put_slash(char **paths)
{
	int		i;
	char	*aux;

	i = 0;
	while (paths[i])
	{
		aux = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = aux;
		i++;
	}
}

char	**search_paths(char **envp)
{
	int		i;
	char	**paths;
	char	*aux;

	i = 0;
	while (envp[i])
	{
		aux = ft_strnstr(envp[i], "PATH", ft_strlen("PATH"));
		if (aux)
		{
			aux = ft_strchr(aux, '=');
			aux++;
			paths = ft_split(aux, ':');
			put_slash(paths);
			return (paths);
		}
		i++;
	}
	return (NULL);
}
