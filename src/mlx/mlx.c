/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:36:49 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/28 21:39:44 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3d.h>

void	ft_mlx(t_var *g)
{
	g->mlx_ptr->ptr_mlx = mlx_init();
	g->mlx_ptr->ptr_win = mlx_new_window(g->mlx_ptr->ptr_mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	g->mlx_ptr->ptr_img = mlx_new_image(g->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	g->mlx_ptr->ptr_img_data = mlx_get_data_addr(g->mlx_ptr->ptr_img, &(g->mlx_ptr->bpp), &(g->mlx_ptr->size_len), &(g->mlx_ptr->endian));
}

void	ft_colorize_img(t_var *g, int color, int x, int y)
{
	int	countx;
	int	county;

	county = 0;
	while (county < (TILE_SIZE - 1))
	{
		countx = -1;
		while (++countx < (TILE_SIZE - 1))
			ft_colorize_pixel(g, (x + countx), (y + county), color);
		county++;
	}	
}

void	ft_colorize_pixel(t_var *g, int x, int y, int color)
{
	int	*pixel;

	pixel = (int *)(g->mlx_ptr->ptr_img_data + (y * g->mlx_ptr->size_len) + (x * g->mlx_ptr->bpp / 8));
	*pixel = color;
}