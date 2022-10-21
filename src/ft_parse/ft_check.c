/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:02:42 by rel-hach          #+#    #+#             */
/*   Updated: 2022/10/19 16:37:02 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_check_syntax_and_store_element(t_game *head, t_var *g)
{
	t_game	*temp;

	temp = ft_check_textures(g, head);
	if (temp)
		ft_check_map(g, temp);
	ft_free_lists(head);
}
