/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:52:27 by rel-hach          #+#    #+#             */
/*   Updated: 2022/10/17 15:20:29 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	check_file_extention(char *file_name)
{
	char	*extension;
	
	extension = ft_strrchr(file_name, '.');
	if (extension == NULL)
		return (false);
	if (strcmp(extension, ".cub") != 0)
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
