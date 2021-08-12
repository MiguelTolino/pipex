/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:07:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/08/11 18:08:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void check_nargs(int argc){

	if(argc != NUM_ARGS) {
		perror("Error: Number of arguments invalid");
		exit(1);
	}
}