/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 03:01:15 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/09 17:35:31 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fill_img(t_var *g)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	color = g->data->c_color;
	while (y < WIN_HEIGHT)
	{
		if (y == (WIN_HEIGHT / 2))
			color = g->data->f_color;
		x = 0;
		while (x < WIN_WIDTH)
		{
			ft_colorize_pixel(g, x, y, color);
			x++;
		}
		y++;
	}
}

int	ft_release_key(int key, t_var *g)
{
	if (key == 123 || key == 124)
		g->player->turn = 0;
	else if (key == 0 || key == 1
		|| key == 2 || key == 13)
		g->player->move = 0;
	return (0);
}

int	ft_press_key(int key, t_var *g)
{
	if (key == 0)
		g->player->move = LEFT;
	else if (key == 2)
		g->player->move = RIGHT;
	else if (key == 1)
		g->player->move = DOWN;
	else if (key == 13)
		g->player->move = UP;
	else if (key == 124)
		g->player->turn = RIGHT;
	else if (key == 123)
		g->player->turn = LEFT;
	else if (key == 53)
		destroy_win(g);
	return (0);
}
