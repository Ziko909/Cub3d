/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 06:11:49 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/10 15:40:24 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	direction(t_ray *node)
{
	if (node->angle >= 0 && node->angle <= PI)
		node->facing_up = false;
	else
		node->facing_up = true;
	if (node->angle >= (PI / 2) && node->angle <= ((3 * PI) / 2))
		node->facing_right = false;
	else
		node->facing_right = true;
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

t_ray	*ft_creat_node(int count, t_var *g)
{
	t_ray	*new;

	new = ft_calloc(1, sizeof(t_ray));
	if (!new)
		ft_put_error(g, "Allocation Failed");
	new->id = count;
	new->angle = 0;
	new->distance_wall = 0;
	new->distance_rays = (FOV * (PI / 180)) / WIN_WIDTH;
	new->x_intersection = 0;
	new->y_intersection = 0;
	new->distance_to_pp = 0;
	new->slice_height = 0;
	new->slice_bottom = 0;
	new->slice_top = 0;
	new->slice_bottom = 0;
	return (new);
}

void	creat_rays_list(t_var *g)
{
	int		count;
	t_ray	*node;

	count = 0;
	while (count < NUM_RAYS)
	{
		node = ft_creat_node(count, g);
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
		direction(tmp);
		get_intersection_p(g, tmp);
		angle += tmp->distance_rays;
		tmp = tmp->next;
	}
}
