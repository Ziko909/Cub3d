/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:20:15 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/04 05:20:16 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <libc.h>
# include <errno.h>

// Error Function
void	ft_put_error(char *error_msg);
// Parsing Functions
char	**parsing(char *map_file);

#endif