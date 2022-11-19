/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 05:20:15 by zaabou            #+#    #+#             */
/*   Updated: 2022/11/19 00:56:13 by zaabou           ###   ########.fr       */
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

// used macros
# define PI 3.14159265
# define WIN_WIDTH 1500
# define WIN_HEIGHT 900
# define NUM_RAYS WIN_WIDTH
# define FOV 60
# define MINI_MAP_WIDTH 400
# define MINI_MAP_HEIGHT 200
# define TILE_SIZE 20
# define LINE_COLOR 0x001EBB08
# define UP 2
# define DOWN -2
# define RIGHT 1
# define LEFT -1
# define SOUTH 0
# define NORTH 1
# define EAST 2
# define WEST 3

typedef struct s_game
{
	char			*line;
	struct s_game	*next;
}	t_game;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_tex;

typedef struct ray
{
	double		h_intersectionx;
	double		h_intersectiony;
	double		v_intersectionx;
	double		v_intersectiony;
	double		x_intersection;
	double		y_intersection;
	double		angle;
	double		distance_wall;
	double		distance_rays;
	double		distance_to_pp;
	int			id;
	int			hit_horizontal;
	int			slice_top;
	int			slice_bottom;
	int			slice_width;
	int			slice_height;
	bool		facing_up;
	bool		facing_right;
	struct ray	*next;
}t_ray;

typedef struct player
{
	double	pos_x;
	double	pos_y;
	double	r_speed;
	double	angle;
	int		turn;
	int		move;
	int		m_speed;
	char	direction;
}t_player;

typedef struct mlx
{
	void	*ptr_mlx;
	void	*ptr_win;
	void	*ptr_img;
	char	*ptr_img_data;
	int		bpp;
	int		size_len;
	int		endian;
}t_mlx;

typedef struct data
{
	char	**map;
	char	*path_north;
	char	*path_south;
	char	*path_west;
	char	*path_east;
	int		f_color;
	int		c_color;
	int		nb_player;
	int		map_lines;
	int		large_line;
}t_data;

typedef struct s_var
{
	t_player	*player;
	t_ray		**head;
	t_mlx		*mlx_ptr;
	t_data		*data;
	t_tex		*tex;
}	t_var;

// Error Function
void	ft_put_error(t_var *g, char *error_msg);

// needed linked lists related functions :
t_game	*create_new_node(t_var *g, char *line);
void	ft_lst_add_to_back(t_game **head, t_game *node);
t_game	*hold_map_elements(t_var *g, int fd);
void	ft_free_lists(t_game *head);
void	free_tdstr(char **str);
int		ft_listsize(t_game *lst);

// Parsing Functions :
// starting the process :
bool	check_file_extention(char *file_name);
void	start_processing(char *file_name, t_var *g);
void	ft_print_element(t_var *g);

// Functions used to store and check elemet :
// check textures syntax :
void	ft_check_syntax_and_store_element(t_game *head, t_var *g);
int		ft_search(char *str, t_var *g);
char	*ft_add(char *addto, char *getfrom, t_var *g);
t_game	*ft_check_textures(t_var *g, t_game *head);
int		check_if_exist(char *word, char *str);
void	check_no_repeat(t_var *g, char *str);
void	check_commas(t_var *g, char *str);
int		ft_strisnum(t_var *g, char *str);

// store Paths and color channels :
void	ft_check_store_rgb(t_var *g, char *str, char c);
void	ft_store_paths(t_var *g, char c, char *str);
void	check_paths(t_var *g);

// Functions used to check & store Map :
void	check_map_validity(t_var *g, char **map);
int		count_map_lines(t_var *g, t_game *head);
void	ft_check_map(t_var *g, t_game *head);
void	store_check_map_validity(t_var *g, t_game *head, int count);
void	ft_skip_space(char *str);
int		ch(char c);
void	save_player_position(t_var *g, char c, int x, int y);

// GNL
char	*ft_get_line(char *buffer);
char	*get_remaining_part(char *old_buffer);
char	*ft_read(int fd, char *buffer);
char	*get_next_line(int fd);
int		ft_check_newline(char *s);

// player
	// info 
void	init_player_info(t_var *g);
	// movements
void	ft_check_movements(t_var *g);
void	ft_update_pos_up(t_var *g);
void	ft_update_pos_down(t_var *g);
void	ft_update_pos_right(t_var *g);
void	ft_update_pos_left(t_var *g);

// mlx api
void	ft_mlx(t_var *g);
int		ft_press_key(int key, t_var *g);
void	ft_create_new_img(t_var *g);
int		destroy_win(t_var *g);

// rays
void	ft_add_back(t_ray **head, t_ray *new);
t_ray	*ft_creat_node(int count, t_var *g);
void	creat_rays_list(t_var *g);
void	get_intersection_p(t_var *g, t_ray *ray);
void	raycasting(t_var *g);
bool	check_is_wall(t_var *g, t_ray *node, char c);
double	distance_to_wall(t_var *g, double intersectionx, double intersectiony);
void	direction(t_ray *node);

// rendering
int		ft_rendering(t_var *g);
void	ft_draw_line(t_var *g, int x_e, int y_e);
void	ft_colorize_pixel(t_var *g, int x, int y, int color);

// memory management
void	initialize_data(t_var *g);
void	ft_free(t_var *g);
void	free_data(t_data *data);
void	free_rays_list(t_ray **ray);
void	free_mlx(t_mlx *mlx);
void	free_textures(t_var *g);

// helpful
bool	ft_strcmp(char *str1, char *str2);
void	normalize_angle(double *angle);
void	fill_img(t_var *g);
int		ft_release_key(int key, t_var *g);
bool	is_wall(t_var *g, int x, int y);
int		distance(t_var *g, int c);
char	*join_str(char *s1, char *s2);
bool	valid_index(int j, char *prev_line, char *next_line);

// textures
void    init_textures (t_var *g, t_tex *tex);
void    draw_wall(t_var *g);
void    drawing_wall_slices (t_ray *ray, t_var *g, t_tex *tex, int tex_nb);
void    finding_wall_top_bottom(t_ray *ray);
int     finding_accurate_texture(t_ray *ray);
int     get_x_cordinate(t_ray *ray);
int     get_y_cordinate(t_ray *ray, int y);

// minimap
void	put_elements(t_var *g);
int		distance(t_var *g, int c);
void	ft_put_direction(t_var *g);
void	ft_put_player(t_var *g);
void	ft_colorize_img(t_var *g, int color, int x, int y);
#endif
