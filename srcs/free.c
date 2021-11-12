/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:59:06 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/11 14:21:57 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	double_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
