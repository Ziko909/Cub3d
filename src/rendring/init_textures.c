/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:55:40 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/05 15:51:53 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void    init_textures (t_var *g, t_tex *tex)
{
    tex[0].img = mlx_xpm_file_to_image(g->mlx_ptr->ptr_mlx, g->data->path_south, &tex[0].width, &tex[0].width);
    tex[1].img = mlx_xpm_file_to_image(g->mlx_ptr->ptr_mlx, g->data->path_north, &tex[1].width, &tex[1].width);
    tex[2].img = mlx_xpm_file_to_image(g->mlx_ptr->ptr_mlx, g->data->path_west, &tex[2].width, &tex[2].width);
    tex[3].img = mlx_xpm_file_to_image(g->mlx_ptr->ptr_mlx, g->data->path_east, &tex[3].width, &tex[3].width);
   /*|-------------------------------------------------------------------------------------------------------|*/
    tex[0].addr = mlx_get_data_addr(g->mlx_ptr->ptr_mlx, &tex[0].bpp, &tex[0].line_len, &tex[0].endian);
    tex[1].addr = mlx_get_data_addr(g->mlx_ptr->ptr_mlx, &tex[1].bpp, &tex[1].line_len, &tex[1].endian);
    tex[2].addr = mlx_get_data_addr(g->mlx_ptr->ptr_mlx, &tex[2].bpp, &tex[2].line_len, &tex[2].endian);
    tex[3].addr = mlx_get_data_addr(g->mlx_ptr->ptr_mlx, &tex[3].bpp, &tex[3].line_len, &tex[3].endian);
}
