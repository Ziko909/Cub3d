/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:36:49 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/29 05:44:11 by rel-hach         ###   ########.fr       */
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
	init_textures(g);
	mlx_hook(g->mlx_ptr->ptr_win, 17, 0, destroy_win, g);
	mlx_hook(g->mlx_ptr->ptr_win, 6, 1L << 4, ft_move_mouse, g);
	mlx_hook(g->mlx_ptr->ptr_win, 2, 1L << 0, ft_press_key, g);
	mlx_hook(g->mlx_ptr->ptr_win, 3, 1L << 1, ft_release_key, g);
	mlx_loop_hook(g->mlx_ptr->ptr_mlx, ft_rendering, g);
	mlx_loop(g->mlx_ptr->ptr_mlx);
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

int	ft_move_mouse(int x, int y, t_var *g)
{
	if (g->mlx_ptr->press_x == -1)
		g->mlx_ptr->press_x = x;
	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
		g->player->angle += (x - g->mlx_ptr->press_x) * ((2 * PI) / WIN_WIDTH);
	if (x < 0 && x > WIN_WIDTH && y < 0 && y > WIN_HEIGHT)
		g->mlx_ptr->press_x = -1;
	else
		g->mlx_ptr->press_x = x;
	normalize_angle(&g->player->angle);
	return (0);
}

int	destroy_win(t_var *g)
{
	ft_free(g);
	exit(EXIT_SUCCESS);
	return (1);
}
