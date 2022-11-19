/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:44:59 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/08 17:47:38 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_check_movements(t_var *g)
{
	if (g->player->move == UP)
		ft_update_pos_up(g);
	else if (g->player->move == DOWN)
		ft_update_pos_down(g);
	else if (g->player->move == RIGHT)
		ft_update_pos_right(g);
	else if (g->player->move == LEFT)
		ft_update_pos_left(g);
	if (g->player->turn == RIGHT)
		g->player->angle += g->player->r_speed;
	if (g->player->turn == LEFT)
		g->player->angle -= g->player->r_speed;
}

void	ft_update_pos_up(t_var *g)
{
	double	new_x;
	double	new_y;

	new_x = g->player->pos_x + (g->player->m_speed * cos(g->player->angle));
	new_y = g->player->pos_y + (g->player->m_speed * sin(g->player->angle));
	if (is_wall(g, new_x, new_y) == false)
	{
		g->player->pos_x = new_x;
		g->player->pos_y = new_y;
	}
}

void	ft_update_pos_down(t_var *g)
{
	double	new_x;
	double	new_y;

	new_x = g->player->pos_x - (g->player->m_speed * cos(g->player->angle));
	new_y = g->player->pos_y - (g->player->m_speed * sin(g->player->angle));
	if (is_wall(g, new_x, new_y) == false)
	{
		g->player->pos_x = new_x;
		g->player->pos_y = new_y;
	}
}

void	ft_update_pos_right(t_var *g)
{
	double	new_x;
	double	new_y;
	double	angle;

	angle = g->player->angle + (90 * (PI / 180));
	normalize_angle(&angle);
	new_x = (g->player->pos_x + (g->player->m_speed * cos(angle)));
	new_y = (g->player->pos_y + (g->player->m_speed * sin(angle)));
	if (is_wall(g, new_x, new_y) == false)
	{
		g->player->pos_x = new_x;
		g->player->pos_y = new_y;
	}
}

void	ft_update_pos_left(t_var *g)
{
	double	new_x;
	double	new_y;
	double	angle;

	angle = g->player->angle + (90 * (PI / 180));
	normalize_angle(&angle);
	new_x = (g->player->pos_x - (g->player->m_speed * cos(angle)));
	new_y = (g->player->pos_y - (g->player->m_speed * sin(angle)));
	if (is_wall(g, new_x, new_y) == false)
	{
		g->player->pos_x = new_x;
		g->player->pos_y = new_y;
	}
}
