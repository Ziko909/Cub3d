/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:30:46 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/04 16:42:27 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	**parsing(char *map_file)
{
	char	**map;
	int	map_fd;

	if (check_map_extension(map_file) == false)
		ft_put_error("The Map Must have .ber extension");
	map_fd = open(map_file, O_RDONLY, 00444);
	if (map_fd == -1)
		ft_put_error(strerror(errno));
	map = get_map(map_fd);
	if (map == NULL)
		return (NULL);
	return (NULL);
}

char	**get_map(int map_fd)
{
	return (NULL);
}

bool	check_map_extension(char *map_file)
{
	char	*extension;
	
	extension = strrchr(map_file, '.');
	if (extension == NULL)
		return (false);
	if (strcmp(extension, ".cub") != 0)
		return (false);
	return (true);
}
