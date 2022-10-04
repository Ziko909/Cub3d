/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:20:47 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/04 18:06:05 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_put_error(char *error_msg)
{
	write(2, "\x1b[31m Error : Cub3d : ", 20);
	write(2, error_msg, strlen(error_msg));
	write(2, "\x1b[0m \n", 1);
	exit(1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		parsing(av[1]);
	}
	return (0);
}
