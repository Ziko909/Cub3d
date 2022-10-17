/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:20:47 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/17 13:19:21 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_put_error(char *error_msg)
{
	write(2, "\x1b[31m Error : Cube3d : ", 23);
	write(2, error_msg, strlen(error_msg));
	write(2, "\x1b[0m \n", 1);
	exit(1);
}

void	initialize_data(t_var *g)
{
	g->pos_x = -1;
	g->pos_y = -1;
	g->path_east = NULL;
	g->path_north = NULL;
	g->path_south = NULL;
	g->path_west = NULL;
	g->map = NULL;
	g->nb_player = 0;
	g->c_color = 0;
	g->f_color = 0;
}

int	main(int ac, char **av)
{
	t_var	g;

	if (ac == 2)
	{
		initialize_data(&g);
		start_processing(av[1], &g);
		//ft_print_element(&g);
	}
	return (0);
}
