/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:49:51 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/11 01:30:50 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	normalize_angle(double *angle)
{
	if (*angle > 2 * PI)
		*angle -= 2 * PI;
	else if (*angle < 0)
		*angle += 2 * PI;
}

int	ft_rendering(t_var *g)
{
	ft_check_movements(g);
	normalize_angle(&(g->player->angle));
	fill_img(g);
	raycasting(g);
	draw_wall(g);
	mlx_put_image_to_window((g->mlx_ptr)->ptr_mlx,
		(g->mlx_ptr)->ptr_win, (g->mlx_ptr)->ptr_img, 0, 0);
	return (1);
}
