/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:43:04 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/29 05:48:39 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	distance(t_var *g, int c)
{
	if (c == 'x')
		return (-(g->player->pos_x - 750));
	if (c == 'y')
		return (-(g->player->pos_y - 800));
	return (1);
}

void	ft_put_direction(t_var *g)
{
	int	d;
	int	i;

	d = 0;
	i = 0;
	while (i <= 3)
	{
		d += PI / 180;
		ft_draw_line(g, (g->player->pos_x + distance(g, 'x'))
			+ (20 * cos(g->player->angle + d)),
			(g->player->pos_y + distance(g, 'y'))
			+ (20 * sin(g->player->angle + d)));
		i++;
	}
}

void	ft_put_player(t_var *g)
{
	int	x;
	int	y;

	y = (g->player->pos_y - 4) + distance(g, 'y');
	while (y <= (g->player->pos_y + 4) + distance(g, 'y'))
	{
		x = (g->player->pos_x - 4) + distance(g, 'x');
		while (x <= (g->player->pos_x + 4) + distance(g, 'x'))
		{
			ft_colorize_pixel(g, x, y, 0x00212F3D);
			x++;
		}
		y++;
	}
	ft_put_direction(g);
}

void	put_elements(t_var *g)
{
	int	x;
	int	y;
	int	ex;
	int	ey;
	int	color;

	y = -1;
	while ((g->data->map)[++y])
	{
		x = -1;
		while ((g->data->map)[y][++x])
		{
			if ((g->data->map)[y][x] == ' ')
				color = 0x00000000;
			if ((g->data->map)[y][x] == '1')
				color = 0x00966F33;
			else if (g->data->map[y][x] == '0' || g->data->map[y][x] == 'N'
					|| g->data->map[y][x] == 'S' || g->data->map[y][x] == 'W'
					|| g->data->map[y][x] == 'E')
				color = 0x00FFFFFF;
			ex = (x * TILE_SIZE) + distance(g, 'x');
			ey = (y * TILE_SIZE) + distance(g, 'y');
			ft_colorize_img(g, color, ex, ey);
		}
	}
}

void	ft_draw_line(t_var *g, int x_e, int y_e)
{
	float	steps;
	float	increment_x;
	float	increment_y;
	float	x;
	float	y;

	x = g->player->pos_x + distance(g, 'x');
	y = g->player->pos_y + distance(g, 'y');
	if (fabs(x_e - (g->player->pos_x + distance(g, 'x')))
		>= fabs(y_e - (g->player->pos_y + distance(g, 'y'))))
		steps = fabs(x_e - (g->player->pos_x + distance(g, 'x')));
	else
		steps = fabs(y_e - (g->player->pos_y + distance(g, 'y')));
	increment_x = (x_e - (g->player->pos_x + distance(g, 'x'))) / steps;
	increment_y = (y_e - (g->player->pos_y + distance(g, 'y'))) / steps;
	while (steps >= 0)
	{
		ft_colorize_pixel(g, round(x), round(y), LINE_COLOR);
		x += increment_x;
		y += increment_y;
		steps--;
	}
}
