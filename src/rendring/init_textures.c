/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:55:40 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/19 23:56:43 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_textures(t_var *g)
{
	g->tex[SOUTH].img = mlx_xpm_file_to_image(g->mlx_ptr->ptr_mlx,
			g->data->path_south, &g->tex[SOUTH].width, &g->tex[SOUTH].height);
	g->tex[NORTH].img = mlx_xpm_file_to_image(g->mlx_ptr->ptr_mlx,
			g->data->path_north, &g->tex[NORTH].width, &g->tex[NORTH].height);
	g->tex[EAST].img = mlx_xpm_file_to_image(g->mlx_ptr->ptr_mlx,
			g->data->path_east, &g->tex[EAST].width, &g->tex[EAST].height);
	g->tex[WEST].img = mlx_xpm_file_to_image(g->mlx_ptr->ptr_mlx,
			g->data->path_west, &g->tex[WEST].width, &g->tex[WEST].height);
	if (!g->tex[SOUTH].img || !g->tex[NORTH].img
		|| !g->tex[EAST].img || !g->tex[WEST].img)
		ft_put_error(g, "XPM files are missing");
	g->tex[SOUTH].addr = mlx_get_data_addr(g->tex[SOUTH].img,
			&g->tex[SOUTH].bpp, &g->tex[SOUTH].line_len, &g->tex[SOUTH].endian);
	g->tex[NORTH].addr = mlx_get_data_addr(g->tex[NORTH].img,
			&g->tex[NORTH].bpp, &g->tex[NORTH].line_len, &g->tex[NORTH].endian);
	g->tex[EAST].addr = mlx_get_data_addr(g->tex[EAST].img, &g->tex[EAST].bpp,
			&g->tex[EAST].line_len, &g->tex[EAST].endian);
	g->tex[WEST].addr = mlx_get_data_addr(g->tex[WEST].img, &g->tex[WEST].bpp,
			&g->tex[WEST].line_len, &g->tex[WEST].endian);
	if (!g->tex[SOUTH].addr || !g->tex[NORTH].addr
		|| !g->tex[EAST].addr || !g->tex[WEST].addr)
		ft_put_error(g, "couldn't return image infos");
}
