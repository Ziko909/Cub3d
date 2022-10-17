/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:02:56 by rel-hach          #+#    #+#             */
/*   Updated: 2022/10/17 11:22:03 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_no_repeat(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (str[i])
	{
		while (str[j])
		{
			if (str[j] == str[i])
				ft_put_error("Syntax is not correct");
			j++;
		}
		i++;
		j = i + 1;
	}
}

int		check_if_exist(char *word, char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == word[j])
		{
			j++;
			if (word[j] == '\0')
				return (1);
			else if (str[++i] == word[j])
				return (1);
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
			count++;
		if ((str[0] == ',') || (str[i] == ',' && str[i + 1] == ','))
			ft_put_error("Syntax is not correct");
		i++;
	}
	if (count != 2)
		ft_put_error("Syntax is not correct");
}

int		ft_strisnum(char *str)
{
	int	i;

	i = 0;
	ft_skip_space(str);
	if (str[i + 1] == '\0')
		ft_put_error("There is no number");
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			ft_put_error("Color channels must be expressed in decimal");
		i++;
	}
	return (1);
}

void	ft_print_element(t_var *g)
{
	printf("ceilling color : %x\n",g->c_color);
	printf("floor color : %x\n",g->f_color);
	printf("pos x = %d\n",g->pos_x);
	printf("pos y = %d\n",g->pos_y);
	printf("Path N : %s", g->path_north);
	printf("Path S : %s", g->path_south);
	printf("Path E : %s", g->path_east);
	printf("Path W : %s", g->path_west);
	printf("number of players : %d", g->nb_player);
}