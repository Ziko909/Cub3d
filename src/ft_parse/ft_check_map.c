/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:06:31 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/10 21:33:51 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

bool	check_circumference(int j, char *line, char *prev_line, char *next_line)
{
	char	*str;

	str = "01NWSE";
	if (!ft_strchr(str, line[j - 1]) || !ft_strchr(str, line[j + 1]))
		return (false);
	else if (!ft_strchr(str, prev_line[j]))
		return (false);
	else if (!ft_strchr(str, next_line[j]))
		return (false);
	return (true);
}

void	check_map_validity(t_var *g, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'S')
			{
				if (i == 0 || !valid_index(j, map[i - 1], map[i + 1]))
					ft_put_error(g, "Map must be surrounded by walls here");
				if (j == 0 || !check_circumference(j, map[i],
						map[i - 1], map[i + 1]))
					ft_put_error(g, "Map must be surrounded by walls");
				save_player_position(g, map[i][j], j, i);
			}
		}
	}
	if (g->data->nb_player != 1)
		ft_put_error(g, "Wrong number of players");
}

void	store_check_map_validity(t_var *g, t_game *head, int count)
{
	t_game	*temp;
	int		i;

	temp = head;
	g->data->large_line = 0;
	i = -1;
	g->data->map = ft_calloc(sizeof (char *), count + 1);
	if (!g->data->map)
		ft_put_error(g, "Allocation failed");
	while (temp && ft_strncmp(temp->line, "\n", 1) != 0)
	{
		if (g->data->large_line < (int) ft_strlen(temp->line))
			g->data->large_line = (int) ft_strlen(temp->line);
		g->data->map[++i] = ft_strtrim(temp->line, "\n");
		if (!g->data->map[i])
			ft_put_error(g, "Allocation failed");
		temp = temp->next;
	}
	g->data->map_lines = count;
	check_map_validity(g, g->data->map);
}

int	count_map_lines(t_game *head, t_var *g)
{
	int		count;
	t_game	*temp;

	temp = head;
	count = 0;
	while (temp && ft_strncmp(temp->line, "\n", 1) != 0)
	{
		temp = temp->next;
		count++;
	}
	while (temp && ft_strncmp(temp->line, "\n", 1) == 0)
		temp = temp->next;
	if (temp)
		ft_put_error(g, "Map is invalid");
	return (count);
}

void	ft_check_map(t_var *g, t_game *head)
{
	t_game	*temp;
	int		count;

	temp = head;
	count = 0;
	while (temp->next && ft_strncmp(temp->line, "\n", 1) == 0)
		temp = temp->next;
	count = count_map_lines(temp, g);
	store_check_map_validity(g, temp, count);
}
