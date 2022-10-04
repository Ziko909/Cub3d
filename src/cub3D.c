/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:20:47 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/04 05:23:27 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_put_error(char *error_msg)
{
	int	stdo;

	stdo = dup(1);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	printf("\x1b[31m Error : Cub3d : %s\x1b[0m\n", error_msg);
	dup2(stdo, 1);
	close(stdo);
	exit(1);
}

char	**parsing(char *map_file)
{
	int	map_fd;

	map_fd = open(map_file, O_RDONLY, 00444);
	if (map_fd == -1)
		ft_put_error(strerror(errno));
	return (NULL);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		parsing(av[1]);
	}
	return (0);
}
