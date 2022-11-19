/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:37:00 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/18 16:04:44 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_put_error(t_var *g, char *error_msg)
{
	ft_free(g);
	write(2, "\x1b[31m Error : Cube3d : ", 23);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\x1b[0m \n", 1);
	exit(1);
}
