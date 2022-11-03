/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:20:47 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/03 11:39:29 by zaabou           ###   ########.fr       */
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
	g->data = ft_calloc(1, sizeof(t_data));
	g->mlx_ptr = ft_calloc(1, sizeof(t_mlx));
	g->player = ft_calloc(1, sizeof(t_player));
	g->head = ft_calloc(1, sizeof(t_ray *));
	*(g->head) = NULL;
}

void	init_player_info(t_player *pl)
{
	pl->angle = (3 * PI) / 2 + (30 * (PI / 180));
	pl->m_speed = 5;
	pl->r_speed = 5 * (PI / 180);
}

int	main(int ac, char **av)
{
	t_var	g;

	if (ac == 2)
	{
		initialize_data(&g);
		start_processing(av[1], &g);
		init_player_info(g.player);
		ft_mlx(&g);
		creat_rays_list(&g);
		mlx_hook(g.mlx_ptr->ptr_win, 2, 0, ft_press_key, &g);
		mlx_loop_hook(g.mlx_ptr->ptr_mlx, ft_rendering, &g);
		mlx_loop(g.mlx_ptr->ptr_mlx);
	}
	return (0);
}
