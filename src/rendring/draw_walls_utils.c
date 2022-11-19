/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:54:50 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/11 02:14:15 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	finding_wall_top_bottom(t_ray *ray)
{
	ray->distance_to_pp = (WIN_WIDTH / 2) / tan((FOV * (PI / 180)) / 2);
	ray->slice_height = (TILE_SIZE / ray->distance_wall) * ray->distance_to_pp;
	ray->slice_top = (int)((WIN_HEIGHT / 2) - (ray->slice_height / 2));
	if (ray->slice_top < 0)
		ray->slice_top = 0;
	ray->slice_bottom = (WIN_HEIGHT / 2) + (ray->slice_height / 2);
	if (ray->slice_bottom > WIN_HEIGHT)
		ray->slice_bottom = WIN_HEIGHT;
}

int	finding_accurate_texture(t_ray *ray)
{
	if (ray->hit_horizontal && !ray->facing_up)
		return (SOUTH);
	else if (ray->hit_horizontal && ray->facing_up)
		return (NORTH);
	else if (!ray->hit_horizontal && ray->facing_right)
		return (EAST);
	else if (!ray->hit_horizontal && !ray->facing_right)
		return (WEST);
	return (0);
}

int	get_x_cordinate(t_ray *ray, t_tex *tex, int tex_nb)
{
	double	x_texture;

	if (ray->hit_horizontal)
		x_texture = (ray->x_intersection / TILE_SIZE)
			- floor(ray->x_intersection / TILE_SIZE);
	else
		x_texture = (ray->y_intersection / TILE_SIZE)
			- floor(ray->y_intersection / TILE_SIZE);
	if (tex_nb == SOUTH || tex_nb == WEST)
		x_texture = 1 - x_texture;
	x_texture = x_texture * (double)(tex[tex_nb].width);
	return ((int)x_texture);
}

int	get_y_cordinate(t_ray *ray, int y, t_tex *tex, int tex_nb)
{
	int	distance_from_top;
	int	y_texture;

	distance_from_top = y + (ray->slice_height / 2) - (WIN_HEIGHT / 2);
	y_texture = distance_from_top
		* ((float)tex[tex_nb].height / ray->slice_height);
	return (y_texture);
}

void	drawing_wall_slices(t_ray *ray, t_var *g, t_tex *tex, int tex_nb)
{
	int			x_texture;
	int			y_texture;
	int			color;
	int			y;

	y = ray->slice_top;
	x_texture = get_x_cordinate(ray, tex, tex_nb);
	while (y < ray->slice_bottom)
	{
		y_texture = get_y_cordinate(ray, y, tex, tex_nb);
		color = *(int *)(tex[tex_nb].addr + y_texture * tex[tex_nb].line_len
				+ x_texture * (tex[tex_nb].bpp / 8));
		ft_colorize_pixel(g, ray->id, y, color);
		y++;
	}
}
