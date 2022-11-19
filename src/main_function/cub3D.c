/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:20:47 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/18 23:48:04 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int ac, char **av)
{
	t_var	g;

	if (ac == 2)
	{
		initialize_data(&g);
		start_processing(av[1], &g);
		init_player_info(&g);
		creat_rays_list(&g);
		ft_mlx(&g);
	}
	return (0);
}
