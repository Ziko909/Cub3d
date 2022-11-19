/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:53:23 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/09 17:55:50 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	initialize_data(t_var *g)
{
	g->data = NULL;
	g->mlx_ptr = NULL;
	g->player = NULL;
	g->head = NULL;
	g->tex = NULL;
	g->data = ft_calloc(1, sizeof(t_data));
	if (g->data == NULL)
		ft_put_error(g, "Allocation Failed");
	g->mlx_ptr = ft_calloc(1, sizeof(t_mlx));
	if (g->mlx_ptr == NULL)
		ft_put_error(g, "Allocation Failed");
	g->tex = ft_calloc(4, sizeof(t_tex));
	if (g->tex == NULL)
		ft_put_error(g, "Allocation Failed");
	g->player = ft_calloc(1, sizeof(t_player));
	if (g->player == NULL)
		ft_put_error(g, "Allocation Failed");
	g->head = ft_calloc(1, sizeof(t_ray *));
	if (g->head == NULL)
		ft_put_error(g, "Allocation Failed");
	*(g->head) = NULL;
}
