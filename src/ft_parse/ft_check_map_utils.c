/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:09:55 by rel-hach          #+#    #+#             */
/*   Updated: 2022/10/27 11:40:24 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_skip_space(char *str)
{
	while (*str == ' ' && *str != '\0')
		str++;
}

int		ch(char c)
{
	if (c == '0' || c == '1')
		return 1;
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	save_player_position(t_var *g, char c, int x, int y)
{
	if (c == 'S' || c == 'N' || c == 'E' || c == 'W')
	{
		g->player->pos_x = (x * TILE_SIZE) + (TILE_SIZE / 2);
		g->player->pos_y = (y * TILE_SIZE) + (TILE_SIZE / 2);
		g->data->nb_player++;
	}
}

void	free_tdstr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}