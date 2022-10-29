/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 06:11:49 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/29 22:21:28 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3d.h>

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
		if (angle > 2 * PI)
			angle -= 2 * PI;
		else if (angle < 0)
			angle += 2 * PI; 
		tmp->angle = angle;
		get_intersection_p(g, tmp);
		ft_draw_line(g, tmp->x_intersection, tmp->y_intersection);
		angle += tmp->distance_rays;
		tmp = tmp->next;
	}
}
