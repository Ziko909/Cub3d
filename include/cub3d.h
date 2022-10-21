/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:20:15 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/20 06:00:14 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <libc.h>
# include <errno.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"
# include <mlx.h>

typedef struct s_game
{
    char            *line;
    struct s_game   *next;
} t_game;

typedef struct s_var
{
    struct s_game   *head;
    void            *ptr_mlx;
    void            *ptr_win;
    void            *ptr_img;
    char            *ptr_img_data;
    char            **map;
    char            *path_north;
    char            *path_south;
    char            *path_west;
    char            *path_east;
    int             f_color;
    int             c_color;
    int             pos_x;
    int             pos_y;
    int             nb_player;
    int             map_lines;
    int             large_line;
} t_var;



// Error Function
void	ft_put_error(char *error_msg);

// needed linked lists related functions :
t_game  *create_new_node(char *line);
void    ft_lst_add_to_back(t_game **head, t_game *node);
t_game  *hold_map_elements(int fd);
void	ft_free_lists(t_game *head);
void	free_tdstr(char **str);
int	    ft_listsize(t_game *lst);

// Parsing Functions :
// starting the process :

bool	check_file_extention(char *file_name);
void	initialize_data(t_var *g);
void	start_processing(char *file_name, t_var *g);
void	ft_print_element(t_var *g);

// Functions used to store and check elemet :
// check textures syntax :

void	ft_check_syntax_and_store_element(t_game *head, t_var *g);
int		ft_search(char *str);
char	*ft_add(char *addto, char *getfrom);
t_game	*ft_check_textures(t_var *g, t_game *head);
void	check_no_repeat(char *str);
int		check_if_exist(char *word, char *str);
void	check_commas(char *str);
int		ft_strisnum(char *str);

// store Paths and color channels :

void    ft_check_store_rgb(t_var *g, char *str, char c);
void	ft_store_paths(t_var *g, char c, char *str);
void	check_paths(t_var *g);

// Functions used to check & store Map :

void	check_map_validity(t_var *g, char **map);
int		count_map_lines(t_game *head);
void    ft_check_map(t_var *g, t_game *head);
void	save_check_map_validity(t_var *g, t_game *head, int count);
void	ft_skip_space(char *str);
int		ch(char c);
void	save_player_position(t_var *g, char c, int i, int j);


// GNL

char	*ft_get_line(char *buffer);
char	*get_remaining_part(char *old_buffer);
char	*ft_read(int fd, char *buffer);
char	*get_next_line(int fd);
int     ft_check_newline(char *s);

// Mini_map Functions :

void    init_and_create_window(t_var *g);
int     is_player(char c);
int     get_color(char c);
void    ft_put(int color, int x, int y);
void    ft_show_minimap(t_var *g);



#endif