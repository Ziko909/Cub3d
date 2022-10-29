/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:20:15 by zaabou            #+#    #+#             */
/*   Updated: 2022/10/29 10:11:27 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <libc.h>
# include <errno.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"
# include <mlx.h>
# include <math.h>
# define PI 3.1415926
# define WIN_WIDTH 1500
# define WIN_HEIGHT 900
# define NUM_RAYS WIN_WIDTH
# define FOV 60
# define MINI_MAP_WIDTH 400
# define MINI_MAP_HEIGHT 200
# define TILE_SIZE 20
# define rays_color 0x0000FF00
typedef struct s_game
{
    char            *line;
    struct s_game   *next;
} t_game;

typedef struct player
{
    int pos_x;
    int pos_y;
    int turn;
    int move;
    int m_speed;
    int r_speed;
    float  angle;
}t_player;

typedef struct ray
{
    int     id;
    float     h_intersectionx;
    float     h_intersectiony;
    float     v_intersectionx;
    float     v_intersectiony;
    float     x_intersection;
    float     y_intersection;
    float   angle;
    float   distance_wall;
    float   distance_rays;
    struct  ray *next;
}t_ray;

typedef struct mlx
{
    void    *ptr_mlx;
    void    *ptr_win;
    void    *ptr_img;
    char    *ptr_img_data;
    int     bpp;
    int     size_len;
    int     endian;
}t_mlx;

typedef struct data
{
    char            **map;
    char            *path_north;
    char            *path_south;
    char            *path_west;
    char            *path_east;
    int             f_color;
    int             c_color;
    int             nb_player;
    int             map_lines;
    int             large_line;
}t_data;

typedef struct s_var
{
    t_player    *player;
    t_ray       **head;
    t_mlx       *mlx_ptr;
    t_data      *data;
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
void	save_player_position(t_var *g, char c, int x, int y);

// GNL

char	*ft_get_line(char *buffer);
char	*get_remaining_part(char *old_buffer);
char	*ft_read(int fd, char *buffer);
char	*get_next_line(int fd);
int     ft_check_newline(char *s);

// mlx api
void	ft_mlx(t_var *g);
// rays
void    ft_add_back(t_ray **head, t_ray *new);
t_ray   *ft_creat_node(int count);
void    creat_rays_list(t_var *g);
void    get_intersection_p(t_var *g, t_ray *ray);
void	raycasting(t_var *g);
// rendering
void	ft_rendering(t_var *g);
void	ft_draw_line(t_var *g, int x_e, int y_e);
void	ft_colorize_pixel(t_var *g, int x, int y, int color);
// minimap system
void	ft_mini_map(t_var *g);
void	ft_colorize_img(t_var *g, int color, int x, int y);

#endif