/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:36:49 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/03 10:30:55 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_mlx(t_var *g)
{
	g->mlx_ptr->ptr_mlx = mlx_init();
	g->mlx_ptr->ptr_win = mlx_new_window(g->mlx_ptr->ptr_mlx, WIN_WIDTH,
			WIN_HEIGHT, "CUB3D");
	g->mlx_ptr->ptr_img = mlx_new_image(g->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	g->mlx_ptr->ptr_img_data = mlx_get_data_addr(g->mlx_ptr->ptr_img,
			&(g->mlx_ptr->bpp),
			&(g->mlx_ptr->size_len),
			&(g->mlx_ptr->endian));
}

void	ft_colorize_img(t_var *g, int color, int x, int y)
{
	int	countx;
	int	county;

	county = -1;
	while (++county <= (TILE_SIZE - 1))
	{
		countx = -1;
		if ((y + county) < 700)
			continue ;
		while (++countx <= (TILE_SIZE - 1))
		{
			if ((x + countx < 550) || (x + countx) > 950)
				continue ;
			if (county == (TILE_SIZE - 1) || countx == (TILE_SIZE - 1))
				ft_colorize_pixel(g, (x + countx), (y + county), 0x004E4E4E);
			else
				ft_colorize_pixel(g, (x + countx), (y + county), color);
		}
	}
}

void	ft_colorize_pixel(t_var *g, int x, int y, int color)
{
	int	*pixel;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = (int *)(g->mlx_ptr->ptr_img_data + (y * g->mlx_ptr->size_len)
			+ (x * g->mlx_ptr->bpp / 8));
	*pixel = color;
}
