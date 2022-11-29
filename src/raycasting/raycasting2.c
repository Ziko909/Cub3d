/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:05:29 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/29 05:01:09 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

bool	is_not_valid_index(char *str, int index)
{
	return (str && (index > (int) ft_strlen(str) || index < 0));
}

double	distance_to_wall(t_var *g, double intersectionx, double intersectiony)
{
	return (sqrt(fabs(g->player->pos_x - intersectionx)
			* fabs(g->player->pos_x - intersectionx)
			+ (fabs(g->player->pos_y - intersectiony)
				* fabs(g->player->pos_y - intersectiony))));
}

bool	is_wall(t_var *g, int x, int y)
{
	x = floor(x / TILE_SIZE);
	y = floor(y / TILE_SIZE);
	if ((y < 0 || y > (g->data->map_lines - 1))
		|| is_not_valid_index((g->data->map)[y], x))
		return (true);
	if ((g->data->map)[y][x] == '1' || (g->data->map)[y][x] == ' ')
		return (true);
	return (false);
}

bool	check_is_wall(t_var *g, t_ray *node, char c)
{
	int	x;
	int	y;

	if (c == 'h')
	{
		x = node->h_intersectionx;
		y = node->h_intersectiony;
		if (node->angle > PI && node->angle <= (2 * PI))
			y--;
	}
	if (c == 'v')
	{
		x = node->v_intersectionx;
		y = node->v_intersectiony;
		if (node->angle >= (PI / 2) && node->angle <= ((3 * PI) / 2))
			x--;
	}
	return (is_wall(g, x, y));
}

float	horizontal(t_var *g, t_ray *node)
{
	double	ystep;
	double	xstep;

	xstep = fabs(TILE_SIZE / tan(node->angle));
	ystep = TILE_SIZE;
	if (node->angle >= PI && node->angle <= (2 * PI))
		ystep *= -1;
	if (node->angle >= (PI / 2) && node->angle <= ((3 * PI) / 2))
		xstep *= -1;
	node->h_intersectiony = floor(g->player->pos_y / TILE_SIZE) * TILE_SIZE;
	if (node->angle >= 0 && node->angle <= PI)
		node->h_intersectiony += TILE_SIZE;
	if (node->angle >= PI / 2 && node->angle <= (3 * PI) / 2)
		node->h_intersectionx = g->player->pos_x
			- fabs((fabs(g->player->pos_y - node->h_intersectiony)
					/ tan(node->angle)));
	else
		node->h_intersectionx = g->player->pos_x + fabs((fabs(g->player->pos_y - node->h_intersectiony) / tan(node->angle)));
	while (check_is_wall(g, node, 'h') == false)
	{
		node->h_intersectionx += xstep;
		node->h_intersectiony += ystep;
	}
	return (distance_to_wall(g, node->h_intersectionx, node->h_intersectiony));
}

float	vertical(t_var *g, t_ray *node)
{
	double	ystep;
	double	xstep;

	ystep = fabs(TILE_SIZE * tan(node->angle));
	xstep = TILE_SIZE;
	if (node->angle >= PI && node->angle <= (2 * PI))
		ystep *= -1;
	if (node->angle >= (PI / 2) && node->angle <= (3 * PI) / 2)
		xstep *= -1;
	node->v_intersectionx = floor(g->player->pos_x / TILE_SIZE) * TILE_SIZE;
	if (!(node->angle >= (PI / 2) && node->angle <= 3 * PI / 2))
		node->v_intersectionx += TILE_SIZE;
	if (node->angle >= PI && node->angle <= (2 * PI))
		node->v_intersectiony = g->player->pos_y - fabs((fabs(g->player->pos_x - node->v_intersectionx) * tan(node->angle)));
	else
		node->v_intersectiony = g->player->pos_y + fabs((fabs(g->player->pos_x - node->v_intersectionx) * tan(node->angle)));
	while (check_is_wall(g, node, 'v') == false)
	{
		node->v_intersectionx += xstep;
		node->v_intersectiony += ystep;
	}
	return (distance_to_wall(g, node->v_intersectionx, node->v_intersectiony));
}

void	get_intersection_p(t_var *g, t_ray *node)
{
	float	h;
	float	v;

	h = horizontal(g, node);
	v = vertical(g, node);
	if (h < v)
	{
		node->hit_horizontal = 1;
		node->distance_wall = fabs(h * cos(fabs(g->player->angle - node->angle)));
		node->x_intersection = node->h_intersectionx;
		node->y_intersection = node->h_intersectiony;
	}
	else
	{
		node->hit_horizontal = 0;
		node->distance_wall = fabs(v * cos(fabs(g->player->angle - node->angle)));
		node->x_intersection = node->v_intersectionx;
		node->y_intersection = node->v_intersectiony;
	}
}
