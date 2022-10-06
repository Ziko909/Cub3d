/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:30:46 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/06 19:15:02 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_lstadd_back_doubly(t_game **lst, t_game *new)
{
	t_game	*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = *lst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
			new->prev = temp;
		}
	}
}

t_game	*ft_new_node(char *line)
{
	t_game	*new;

	new = ft_calloc(1, sizeof(t_game));
	new->line = ft_strdup(line);
	new->next =  NULL;
	new->prev = NULL;
	return (new);
}

bool	check_map_extension(char *map_file)
{
	char	*extension;
	
	extension = ft_strrchr(map_file, '.');
	if (extension == NULL)
		return (false);
	if (strcmp(extension, ".cub") != 0)
		return (false);
	return (true);
}

void	hold_map_elements(t_game **head, int fd)
{
	t_game	*node;
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return ;
	else if (ft_strncmp(line, "\n", 1) != 0)
	{
		node = ft_new_node(line);
		ft_lstadd_back_doubly(&(*head), node);
	}
	free(line);
	hold_map_elements(&(*head), fd);
}

char	**parsing(char *map_file)
{
	t_game	*head;
	int		fd;

	if (check_map_extension(map_file) == false)
		ft_put_error("File format is not supported");
	fd = open(map_file, O_RDONLY, 00444);
	if (fd == -1)
		ft_put_error(strerror(errno));
	hold_map_elements(&head, fd);
		return (NULL);
	return (NULL);
}

