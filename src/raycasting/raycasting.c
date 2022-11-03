/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 06:11:49 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/03 09:46:19 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_update_pos_left_right(t_var *g, int key)
{
	double	new_x;
	double	new_y;
	double	angle;

	angle = g->player->angle + (90 * (PI / 180));
	normalize_angle(&angle);
	if (key == 0)
	{
		new_x = (g->player->pos_x - (g->player->m_speed * cos(angle)));
		new_y = (g->player->pos_y - (g->player->m_speed * sin(angle)));
		if (is_wall(g, new_x, new_y) == false)
		{
			g->player->pos_x = new_x;
			g->player->pos_y = new_y;
		}
	}
	if (key == 2)
	{
		new_x = (g->player->pos_x + (g->player->m_speed * cos(angle)));
		new_y = (g->player->pos_y + (g->player->m_speed * sin(angle)));
		if (is_wall(g, new_x, new_y) == false)
		{
			g->player->pos_x = new_x;
			g->player->pos_y = new_y;
		}
	}
}

void	ft_update_pos_up_down(t_var *g, int key)
{
	double	new_x;
	double	new_y;

	if (key == 13)
	{
		new_x = g->player->pos_x + (g->player->m_speed * cos(g->player->angle));
		new_y = g->player->pos_y + (g->player->m_speed * sin(g->player->angle));
		if (is_wall(g, new_x, new_y) == false)
		{
			g->player->pos_x = new_x;
			g->player->pos_y = new_y;
		}
	}
	else if (key == 1)
	{
		new_x = g->player->pos_x - (g->player->m_speed * cos(g->player->angle));
		new_y = g->player->pos_y - (g->player->m_speed * sin(g->player->angle));
		if (is_wall(g, new_x, new_y) == false)
		{
			g->player->pos_x = new_x;
			g->player->pos_y = new_y;
		}
	}
}

void	fill_img(t_var *g)
{
	int	x;
	int	y;
	int	color;

	y = 1;
	color = g->data->c_color;
	while (y <= WIN_HEIGHT)
	{
		if (y == (WIN_HEIGHT / 2))
			color = g->data->f_color;
		x = 1;
		while (x <= WIN_WIDTH)
		{
			if (x >= 550 && x <= 950 && y >= 700 && y <= 900)
				ft_colorize_pixel(g, x, y, 0x00000000);
			else
				ft_colorize_pixel(g, x, y, color);
			x++;
		}
		y++;
	}
}

int	ft_release_key(t_var *g)
{
	g->player->turn = 0;
	g->player->move = 0;
	return (0);
}

int	ft_press_key(int key, t_var *g)
{
	if (key == 0)
		ft_update_pos_left_right(g, key);
	if (key == 2)
		ft_update_pos_left_right(g, key);
	if (key == 1)
		ft_update_pos_up_down(g, key);
	if (key == 13)
		ft_update_pos_up_down(g, key);
	if (key == 124)
		g->player->turn = 1;
	if (key == 123)
		g->player->turn = -1;
	return (0);
}

void	ft_add_back(t_ray **head, t_ray *new)
{
	t_ray	*tmp;

	if (*head == NULL)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_ray	*ft_creat_node(int count)
{
	t_ray	*new;

	new = ft_calloc(1, sizeof(t_ray));
	new->id = count;
	new->angle = 0;
	new->distance_wall = 0;
	new->distance_rays = (FOV * (PI / 180)) / WIN_WIDTH;
	new->x_intersection = 0;
	new->y_intersection = 0;
	return (new);
}

void	creat_rays_list(t_var *g)
{
	int		count;
	t_ray	*node;

	count = 0;
	while (count < NUM_RAYS)
	{
		node = ft_creat_node(count);
		ft_add_back(g->head, node);
		count++;
	}
}

void	raycasting(t_var *g)
{
	t_ray	*tmp;
	float	angle;

	tmp = *(g->head);
	angle = (g->player)->angle - ((FOV / 2) * (PI / 180));
	while (tmp != NULL)
	{
		tmp->angle = angle;
		normalize_angle(&tmp->angle);
		get_intersection_p(g, tmp);
		angle += tmp->distance_rays;
		tmp = tmp->next;
	}
}
