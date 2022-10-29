/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:49:51 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/29 03:10:54 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <cub3d.h>
# include <mlx.h>
void	ft_rendering(t_var *g)
{
	ft_mini_map(g);
}

void	ft_draw_line(t_var *g, int x_e, int y_e)
{
	// int	dx;
	// int	dy;
	// int	dp;
	// int	x_s;
	// int	y_s;

	// x_s = g->player->pos_x;
	// y_s = g->player->pos_y;
	// dx = abs(x_e - x_s);
	// dy = abs(y_e - y_s);
	// dp = (2 * dy) - dx;
	// while (1)
	// {
	// 	if (x_s == x_e && y_s == y_e)
	// 		break ;
	// 	if (dp < 0)
	// 	{
	// 		dp = dp + (2 * dy);
	// 		if (x_s < x_e)
	// 			x_s += 1;
	// 		else if (x_s > x_e)
	// 			x_s -= 1;
	// 	}
	// 	else
	// 	{
	// 		dp = dp + (2 * dy) - (2 * dx);
	// 		if (x_s < x_e)
	// 			x_s += 1;
	// 		else if (x_s > x_e)
	// 			x_s -= 1;
	// 		if (y_s < y_e) 
	// 			y_s += 1;
	// 		else if (y_s > y_e)
	// 			y_s -= 1;
	// 	}
	// 	ft_colorize_pixel(g, x_s, y_s, rays_color);
	float steps;
	int dx;
	int dy;
	float increment_x;
	float increment_y;
	float x;
	float y;

	x = g->player->pos_x;
	y = g->player->pos_y;
	int i = 0;

	dx = x_e - g->player->pos_x;
	dy = y_e - g->player->pos_y;
	if (abs(dx) >= abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	increment_x = dx / steps;
	increment_y = dy / steps;
	while (i <= steps)
	{
		ft_colorize_pixel(g, round(x), round(y), rays_color);
		x += increment_x;
		y += increment_y;
		i++;
	}
}