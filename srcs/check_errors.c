/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:07:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/08/12 12:40:27 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void throw_error(const char* error) {
	perror(error);
	exit(1);
}

void check_nargs(int argc){
	if(argc != NUM_ARGS)
		throw_error(ERROR_ARGS);
}