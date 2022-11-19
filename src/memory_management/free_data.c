/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:37:54 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/19 00:15:12 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_free(t_var *g)
{
	if (g->player != NULL)
		free(g->player);
	if (g->data != NULL)
		free_data(g->data);
	if (g->head != NULL)
		free_rays_list(g->head);
	if (g->tex != NULL)
		free_textures(g);
	if (g->mlx_ptr != NULL)
		free_mlx(g->mlx_ptr);
}

void	free_data(t_data *data)
{
	int	index;

	if (data->map != NULL)
	{
		index = -1;
		while ((data->map)[++index] != NULL)
			free ((data->map)[index]);
		free (data->map);
	}
	if (data->path_north != NULL)
		free (data->path_north);
	if (data->path_south != NULL)
		free (data->path_south);
	if (data->path_west != NULL)
		free (data->path_west);
	if (data->path_east != NULL)
		free (data->path_east);
}

void	free_rays_list(t_ray **ray)
{
	t_ray	*tmp;

	while (*ray)
	{
		tmp = *ray;
		*ray = (*ray)->next;
		free(tmp);
	}
	free (ray);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->ptr_img != NULL)
		mlx_destroy_image(mlx->ptr_mlx, mlx->ptr_img);
	if (mlx->ptr_win != NULL)
		mlx_destroy_window(mlx->ptr_mlx, mlx->ptr_win);
}

void	free_textures(t_var *g)
{
	int	index;

	index = 0;
	while (index < 4)
	{
		if ((g->tex)[index].img != NULL)
			mlx_destroy_image(g->mlx_ptr->ptr_mlx, (g->tex)[index].img);
		index++;
	}
}
