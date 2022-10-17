/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:09:55 by rel-hach          #+#    #+#             */
/*   Updated: 2022/10/13 02:29:08 by rel-hach         ###   ########.fr       */
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

void	save_player_position(t_var *g, char c, int i, int j)
{
	if (c == 'S' || c == 'N' || c == 'E' || c == 'W')
	{
		g->pos_x = i;
		g->pos_y = j;
		g->nb_player++;
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
}