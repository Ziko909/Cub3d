/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:02:56 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/18 23:44:12 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	check_no_repeat(t_var *g, char *str)
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
				ft_put_error(g, "Syntax is not correct0");
			j++;
		}
	}
	if (i != 6)
		ft_put_error(g, "Syntax is not correct1");
}

int	check_if_exist(char *word, char *str)
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

void	check_commas(t_var *g, char *str)
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
				ft_put_error(g, "Syntax is not correct.");
		}
		i++;
	}
	if (count != 2)
		ft_put_error(g, "Syntax is not correct..");
}

int	ft_strisnum(t_var *g, char *str)
{
	int	i;

	i = 0;
	while (*str == ' ' && *str)
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_put_error(g, "Color channels must be expressed in decimal");
		i++;
	}
	return (1);
}

void	check_paths(t_var *g)
{
	if (g->data->path_north[0] == '\0' || g->data->path_south[0] == '\0')
		ft_put_error(g, "Invalid Path");
	if (g->data->path_west[0] == '\0' || g->data->path_east[0] == '\0')
		ft_put_error(g, "Invalid Path");
}
