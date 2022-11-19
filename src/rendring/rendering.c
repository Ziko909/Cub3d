/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:49:51 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/18 17:20:44 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_mini_map(t_var *g)
{
	put_elements(g);
	ft_put_player(g);
}

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
	ft_mini_map(g);
	mlx_put_image_to_window((g->mlx_ptr)->ptr_mlx,
		(g->mlx_ptr)->ptr_win, (g->mlx_ptr)->ptr_img, 0, 0);
	return (1);
}

void	ft_draw_line(t_var *g, int x_e, int y_e)
{
	float	steps;
	int		dx;
	int		dy;
	int		i;
	float	increment_x;
	float	increment_y;
	float	x;
	float	y;

	x = g->player->pos_x + distance(g, 'x');
	y = g->player->pos_y + distance(g, 'y');
	dx = x_e - (g->player->pos_x + distance(g, 'x'));
	dy = y_e - (g->player->pos_y + distance(g, 'y'));
	if (abs(dx) >= abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	increment_x = dx / steps;
	increment_y = dy / steps;
	i = 0;
	while (i <= steps)
	{
		ft_colorize_pixel(g, round(x), round(y), LINE_COLOR);
		x += increment_x;
		y += increment_y;
		i++;
	}
}
