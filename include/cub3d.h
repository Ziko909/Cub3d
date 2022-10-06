/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:20:15 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/06 19:15:17 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <libc.h>
# include <errno.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"

typedef enum e_type
{
    textures,
    nord,
    south,
    west,
    east,
    floor,
    Ceilling,
    map_line
} t_type;

typedef struct s_game
{
    char            *line;
    t_type          type;
    struct s_game   *next;
    struct s_game   *prev;
} t_game;

// Error Function
void	ft_put_error(char *error_msg);
// Parsing Functions
char	**parsing(char *map_file);
bool	check_map_extension(char *map_file);
void	hold_map_elements(t_game **head, int fd);
void	ft_lstadd_back_doubly(t_game **lst, t_game *new);
t_game	*ft_new_node(char *line);


#endif