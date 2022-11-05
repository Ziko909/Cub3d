/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 05:48:27 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/05 20:44:38 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// first : calculate size of wall 

void    finding_wall_top_bottom(t_ray *ray)
{
    // calculate distance to projection plane (screen)
    ray->distance_to_pp = (WIN_WIDTH / 2) / tan((FOV * (PI / 180)) / 2);
    // calculate wall slice height
    ray->slice_height = (TILE_SIZE / ray->distance_wall) * ray->distance_to_pp;
    // calculate wall slice top point
    ray->slice_top = (int)((WIN_HEIGHT / 2) - (ray->slice_height / 2));
    // if slice top point is less than zero then we assign to it the zero value
    if (ray->slice_top < 0)
        ray->slice_top = 0;
    // calculate wall slice top point
    ray->slice_bottom = (WIN_HEIGHT / 2) + (ray->slice_height / 2);
    // if slice top point is greather than the screen height then we assign to it the max screen height
    if (ray->slice_bottom > WIN_HEIGHT)
        ray->slice_bottom = WIN_HEIGHT;
}

int finding_accurate_texture(t_ray *ray)
{
    // ray hits the horizontal grid and the ray angle is looking down to the sud
    if (ray->hit_horizontal && ray->angle < 0 && ray->angle >= PI)
        return (0);
    // ray hits the horizontal grid and the ray angle is looking down to the nord
    if (ray->hit_horizontal && ((ray->angle >= 0) && (ray->angle < PI)))
        return (1);
    // ray hits the vertical grid and the ray angle is looking down to the west right
    if (ray->hit_vertical && ((ray->angle >= PI / 2) && (ray->angle >= 3 * PI / 2)))
        return (2);
    // ray hits the horizontal grid and the ray angle is looking up to the east left .. 
    if (ray->hit_vertical && ((ray->angle < PI / 2) && (ray->angle <= 3 * PI / 2)))
        return (3);
    return (0);
}

int get_x_cordinate(t_ray *ray)
{
    int x_texture = 0;

    if (ray->hit_horizontal)
        x_texture = (int)ray->x_intersection % TILE_SIZE;
    else if (ray->hit_vertical)
        x_texture = (int)ray->y_intersection % TILE_SIZE;
    x_texture = x_texture * (TILE_SIZE / ray->slice_height);
    return (x_texture);
}

int get_y_cordinate(t_ray *ray, int y)
{
    int distance_from_top;
    int y_texture;

    distance_from_top = y + (ray->slice_height / 2) - (WIN_HEIGHT / 2);
    y_texture = distance_from_top * (TILE_SIZE / ray->slice_height);
    return (y_texture);
}

void    drawing_wall_slices (t_ray *ray, t_var *g, t_tex *tex, int tex_nb)
{
    int     x_texture;
    int     y_texture;
    char    *color;
    int     y;

    y = ray->slice_top;
    x_texture = get_x_cordinate(ray);
    while (y <= ray->slice_bottom)
    {
        y_texture = get_y_cordinate(ray, y);
        color = tex[tex_nb].addr + y_texture * tex[tex_nb].line_len + x_texture * (tex[tex_nb].bpp / 8);
        ft_colorize_pixel(g, ray->id, y, *(int *)color);
        //a++;
        y++;
    }
}

void    draw_wall(t_var *g)
{
    t_ray   *ray;
    t_tex   *tex;
    int     texture_nb;

    tex = malloc(sizeof(t_tex) * 4);
    if (!tex)
        exit(EXIT_FAILURE);
    init_textures(g, tex);
    ray = *(g->head);
    while (ray != NULL)
    {
        // finding top bottom points
        finding_wall_top_bottom(ray);
        // finding the accurate texture
        texture_nb = finding_accurate_texture(ray);
        // now drawing wall slices :
        drawing_wall_slices(ray, g, tex, texture_nb);
        ray = ray->next;
    }
}