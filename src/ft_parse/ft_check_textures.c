/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:57:57 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/19 01:26:33 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_search(char *str, t_var *g)
{
	char	*to_comp;
	char	*word;
	int		i;

	i = 0;
	to_comp = "SO NO WE EA F C";
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	word = malloc(sizeof(char) * i + 1);
	if (!word)
		ft_put_error(g, "Allocation failed");
	ft_strlcpy(word, str, i + 1);
	if (check_if_exist(word, to_comp))
		return (free(word), 1);
	return (free(word), 0);
}

char	*ft_add(char *addto, char *getfrom, t_var *g)
{
	char	*new;
	char	*first;

	first = malloc(sizeof(char) * 2);
	if (!first)
		ft_put_error(g, "Allocation failed");
	first[0] = getfrom[0];
	first[1] = '\0';
	new = join_str(addto, first);
	if (!new)
		ft_put_error(g, "Allocation failed");
	free(first);
	return (new);
}

void	ft_check_store_rgb(t_var *g, char *str, char c)
{
	char	**splitted;
	char	*new;
	int		i;

	i = -1;
	new = ft_strtrim(str, " \t\n");
	if (!new)
		ft_put_error(g, "Allocation Failed");
	check_commas(g, new);
	splitted = ft_split(new, ',');
	if (!splitted)
		ft_put_error(g, "Allocation Failed");
	free(new);
	while (splitted[++i] && ft_strisnum(g, splitted[i]))
	{
		if (ft_atoi(splitted[i]) > 255 || ft_atoi(splitted[i]) < 0)
			ft_put_error(g, "Color channel must be expressed from 0 to 255");
	}
	if (c == 'C')
		g->data->c_color = ft_atoi(splitted[0]) << 16
			| ft_atoi(splitted[1]) << 8 | ft_atoi(splitted[2]);
	if (c == 'F')
		g->data->f_color = ft_atoi(splitted[0]) << 16
			| ft_atoi(splitted[1]) << 8 | ft_atoi(splitted[2]);
	free_tdstr(splitted);
}

void	ft_store_paths(t_var *g, char c, char *str)
{
	if (c == 'N')
	{
		g->data->path_north = ft_strtrim(str, " \t\n");
		if (!g->data->path_north)
			ft_put_error(g, "Allocation failed");
	}
	if (c == 'S')
	{
		g->data->path_south = ft_strtrim(str, " \t\n");
		if (!g->data->path_south)
			ft_put_error(g, "Allocation failed");
	}
	if (c == 'W')
	{
		g->data->path_west = ft_strtrim(str, " \t\n");
		if (!g->data->path_west)
			ft_put_error(g, "Allocation failed");
	}
	if (c == 'E')
	{
		g->data->path_east = ft_strtrim(str, " \t\n");
		if (!g->data->path_east)
			ft_put_error(g, "Allocation failed");
	}
}

t_game	*ft_check_textures(t_var *g, t_game *head)
{
	t_game	*temp;
	char	*str;
	int		i;

	temp = head;
	str = ft_strdup("");
	if (!str)
		ft_put_error(g, "Allocation failed");
	while (temp && ft_strlen(str) != 6)
	{
		i = 0;
		if (ft_search(temp->line, g))
		{
			while (temp->line[i] == ' ' && temp->line[i])
				i++;
			str = ft_add(str, &temp->line[i], g);
			if (temp->line[i] == 'F' || temp->line[i] == 'C')
				ft_check_store_rgb(g, &temp->line[i + 1], temp->line[i]);
			else
				ft_store_paths(g, temp->line[i], &temp->line[i + 2]);
		}
		temp = temp->next;
	}
	(check_no_repeat(g, str), check_paths(g));
	return (free(str), temp);
}
