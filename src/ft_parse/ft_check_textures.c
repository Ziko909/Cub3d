/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:57:57 by rel-hach          #+#    #+#             */
/*   Updated: 2022/10/21 00:46:25 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		ft_search(char *str)
{
	char	*to_comp;
	char	*word;
	int		i;

	i = 0;
	to_comp = "SO NO WE EA F C";
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	word = malloc(sizeof(char) * i + 1);
	ft_strlcpy(word, str, i + 1);
	if (check_if_exist(word, to_comp))
		return (free(word), 1);
	return (free(word), 0);
}

char	*ft_add(char *addto, char *getfrom)
{
	char	*new;
	char	*first;

	first = malloc(sizeof(char) * 2);
	first[0] = getfrom[0];
	first[1] = '\0';
	new = ft_strjoin(addto, first);
	free(first);
	return (new);
}

void    ft_check_store_rgb(t_var *g, char *str, char c)
{
	char	**splitted;
	char	*new;
	int		i;

	i = -1;
	new = ft_strtrim(str, " \t\n");
	check_commas(new);
	splitted = ft_split(new, ',');
	free(new);
	while (splitted[++i] && ft_strisnum(splitted[i]))
    {
		if (ft_atoi(splitted[i]) > 255 || ft_atoi(splitted[i]) < 0) 
			ft_put_error("Color channel must be expressed from 0 to 255");
    }
	if (c == 'C')
		g->c_color = ft_atoi(splitted[0]) << 16 | ft_atoi(splitted[1]) << 8
				| ft_atoi(splitted[2]);
	if (c == 'F')
		g->f_color = ft_atoi(splitted[0]) << 16 | ft_atoi(splitted[1]) << 8
				| ft_atoi(splitted[2]);
	free_tdstr(splitted);
}

void	ft_store_paths(t_var *g, char c, char *str)
{
	if (c == 'N')
		g->path_north = ft_strtrim(str, " \t\n");
	if (c == 'S')
		g->path_south = ft_strtrim(str, " \t\n");
	if (c == 'W')
		g->path_west = ft_strtrim(str, " \t\n");
	if (c == 'E')
		g->path_east = ft_strtrim(str, " \t\n");
}

t_game	*ft_check_textures(t_var *g, t_game *head)
{
	t_game	*temp;
	char	*str;
	int		i;

	temp = head;
	str = ft_strdup("");
	while (temp && ft_strlen(str) != 6)
	{
		i = 0;
		if (ft_search(temp->line))
		{
			while (temp->line[i] == ' ' && temp->line[i])
				i++;
			str = ft_add(str, &temp->line[i]);
			if (temp->line[i] == 'F' || temp->line[i] == 'C')
				ft_check_store_rgb(g, &temp->line[i + 1], temp->line[i]);
			else
				ft_store_paths(g, temp->line[i], &temp->line[i + 2]);
		}
		temp = temp->next;
	}
	check_no_repeat(str);
	check_paths(g);
	return (free(str), temp);
}