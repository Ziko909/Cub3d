/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:02:56 by rel-hach          #+#    #+#             */
/*   Updated: 2022/10/27 07:25:54 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_no_repeat(char *str)
{
	int		i;
	int		j;

	i = -1;
	while (str[++i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				ft_put_error("Syntax is not correct0");
			j++;
		}
	}
	if (i != 6)
		ft_put_error("Syntax is not correct1");
}

int		check_if_exist(char *word, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == word[j])
		{
			if ((word[j] == 'C' || word[j] == 'F') && !word[j + 1])
				return (1);
			else if (word[j] != 'C' && word[j] != 'F')
			{
				if ((word[j + 1] == str[i + 1]) && !word[j + 2])
					return (1);
			}
		}
		i++;
	}
	return (0);
}

void	check_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	ft_skip_space(str);
	while (str[i])
	{
		if (str[i] == ',')
		{
			count++;
			if (!ft_isdigit(str[i - 1]) || !ft_isdigit(str[i + 1]))
				ft_put_error("Syntax is not correct.");
		}
		i++;
	}
	if (count != 2)
		ft_put_error("Syntax is not correct..");
}

int		ft_strisnum(char *str)
{
	int	i;

	i = 0;
	while (*str == ' ' && *str)
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_put_error("Color channels must be expressed in decimal");
		i++;
	}
	return (1);
}

void	check_paths(t_var *g)
{
	if (g->data->path_north[0] == '\0' || g->data->path_south[0] == '\0')
		ft_put_error("Invalid Path");
	if (g->data->path_west[0] == '\0' || g->data->path_east[0] == '\0')
		ft_put_error("Invalid Path");
}

void	ft_print_element(t_var *g)
{
	printf("ceilling color : %x\n",g->data->c_color);
	printf("floor color : %x\n",g->data->f_color);
	printf("pos x = %d\n",g->player->pos_x);
	printf("pos y = %d\n",g->player->pos_y);
	printf("Path N : %s", g->data->path_north);
	printf("Path S : %s", g->data->path_south);
	printf("Path E : %s", g->data->path_east);
	printf("Path W : %s", g->data->path_west);
	printf("number of players : %d", g->data->nb_player);
}