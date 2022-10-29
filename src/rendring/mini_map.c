/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:43:04 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/29 03:18:13 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3d.h>

void	ft_put_player(t_var *g)
{
	int	x;
	int	y;

	y = g->player->pos_y - 4;
	while (y <= g->player->pos_y + 4)
	{
		x = g->player->pos_x - 4;
		while (x <= g->player->pos_x + 4)
		{
			ft_colorize_pixel(g, x, y, 0x00212F3D);
			x++;
		}
		y++;
	}
}

void	ft_mini_map(t_var *g)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	while ((g->data->map)[++y])
	{
		x = -1;
		while ((g->data->map)[y][++x])
		{
			if ((g->data->map)[y][x] == '1')
				color = 0x00ff1a1a;
			else if (g->data->map[y][x] == '0' || g->data->map[y][x] == 'N'
					|| g->data->map[y][x] == 'S' || g->data->map[y][x] == 'W'
					|| g->data->map[y][x] == 'E')
				color = 0x00FFFFFF;
			else if (g->data->map[y][x] == ' ')
				color = 0x00000000;
			ft_colorize_img(g, color, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
	ft_put_player(g);
 }