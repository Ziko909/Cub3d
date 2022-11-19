/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:43:28 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/11 06:22:09 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_player_info(t_var *g)
{
	if (g->player->direction == 'N')
		g->player->angle = 270 * (PI / 180);
	if (g->player->direction == 'S')
		g->player->angle = 90 * (PI / 180);
	if (g->player->direction == 'E')
		g->player->angle = 0;
	if (g->player->direction == 'W')
		g->player->angle = 180 * (PI / 180);
	g->player->m_speed = 4;
	g->player->r_speed = 4 * (PI / 180);
}
