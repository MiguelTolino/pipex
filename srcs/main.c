/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:32:53 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/08/11 20:23:06 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[]) {

	struct s_args args;
	int n_arg;

	n_arg = 1;
	check_nargs(argc);
	while (n_arg < argc)
	{
		if (n_arg == 1)
			treat_file1(&args, argv[n_arg]);
	/*	else if (n_arg == 2)
			treat_cmd1(&args, argv[n_arg]);
		else if (n_arg == 3)
			treat_cmd2(&args, argv[n_arg]);
		else if (n_arg == 4)
			treat_file2(&args, argv[n_arg]);
	*/	n_arg++;
	}
	return (0);
}
