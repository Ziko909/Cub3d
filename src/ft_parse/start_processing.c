/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:52:27 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/01 23:01:13 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	ft_strcmp(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
			return (false);
		str1++;
		str2++;
	}
	return (true);
}

bool	check_file_extention(char *file_name)
{
	char	*extension;
	
	extension = ft_strrchr(file_name, '.');
	if (extension == NULL)
		return (false);
	if (ft_strcmp(extension, ".cub") == false)
		return (false);
	return (true);
}

void	start_processing(char *file_name, t_var *g)
{
	t_game  *head;
	int		fd;

	head = NULL;
	if (check_file_extention(file_name) == false)
		ft_put_error("File format is not supported");
	fd = open(file_name, O_RDONLY, 00444);
	if (fd == -1)
		ft_put_error(strerror(errno));
	head = hold_map_elements(fd);
	ft_check_syntax_and_store_element(head, g);
}
