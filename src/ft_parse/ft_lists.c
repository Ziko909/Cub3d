/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:14:05 by rel-hach          #+#    #+#             */
/*   Updated: 2022/11/18 23:50:49 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_game	*create_new_node(t_var *g, char *line)
{
	t_game	*new;

	new = (t_game *)malloc (sizeof (t_game));
	if (!new)
		ft_put_error(g, "Allocation failed");
	new->line = line;
	new->next = NULL;
	return (new);
}

void	ft_lst_add_to_back(t_game **head, t_game *node)
{
	t_game	*temp;

	if (head)
	{
		if (*head == NULL)
			*head = node;
		else
		{
			temp = *head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = node;
		}
	}
}

t_game	*hold_map_elements(t_var *g, int fd)
{
	t_game	*head;
	t_game	*node;
	t_game	*temp;
	char	*line;

	head = NULL;
	line = get_next_line(fd);
	while (line)
	{
		node = create_new_node(g, line);
		ft_lst_add_to_back(&head, node);
		line = get_next_line(fd);
	}
	temp = head;
	while (temp && ft_strncmp(temp->line, "\n", 1) == 0)
		temp = temp->next;
	if (ft_listsize(temp) == 0)
		ft_put_error(g, "Map is Empty or contains only Newlines ..");
	return (head);
}

void	ft_free_lists(t_game *head)
{
	t_game	*temp;

	temp = head;
	while (temp)
	{
		head = head->next;
		free(temp->line);
		free(temp);
		temp = head;
	}
}

int	ft_listsize(t_game *lst)
{
	int		size;
	t_game	*temp;

	if (lst == NULL)
		return (0);
	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
