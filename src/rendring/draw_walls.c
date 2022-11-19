/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 05:48:27 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/09 17:49:34 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_wall(t_var *g)
{
	t_ray	*ray;
	int		texture_nb;

	ray = *(g->head);
	while (ray != NULL)
	{
		finding_wall_top_bottom(ray);
		texture_nb = finding_accurate_texture(ray);
		drawing_wall_slices(ray, g, g->tex, texture_nb);
		ray = ray->next;
	}
}
