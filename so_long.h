/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:49:53 by yaidriss          #+#    #+#             */
/*   Updated: 2022/11/11 12:36:33 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>    
// # include "minilibx/mlx.h"
# include "srcs/get_next_line.h"

typedef struct map
{
	int		count_e;
	int		count_c;
	int		count_p;
	int		first_p;
	int		second_p;
	int		f_exit;
	int		count_moves;
	char	**map;
	char	**map2;
	int		width;
	int		hight;
	int		valid;
	int		size;
	int		fd;
	int		fd2;
	char	*next;
	void	*mlx;
	void	*window;
	void	*img;
	void	*img_floor;
	void	*img_door;
	void	*img_char;
	void	*img_clc;
	void 	*img_eney;
	int		img_w;
	int		img_h;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*wall;
	char	*ground;
	char	*exit;
	char	*collectable;
	int		coin_valid;
	char	*player;
	char	*player_s;
	char	*enemy;
    int     current_location;
}t_map;

//******** so_long.c **********************//
int check_char(char buffer);
int element_validation(t_map *map);
void validation(t_map* map);
void fill_map(t_map *map);
int border_validation(t_map *map);
//!!*******  src ***********************!/
char **ft_split(char const *str,char c);
char	*ft_strdup(const char	*s1);
///******* error.c ***********************//
void	handl_errors(int i);
//******** print_map ********************//
void print_map(t_map *map);
//********* Path*************************//
int locate_p(t_map *m);
int exit_finder(t_map *m,int i);
int check_surrounding(t_map *m,  int i);
//int check_box(t_map *m,int current_loc);
int	check_box( t_map *map,int ppos);
void find_path(t_map *m);
//************* colors **********************//
void red();
void reset();
void Green();
void yellow();
void Black();
void Cyan();


//************* movment ***********************//
int  	move_char(int c, t_map *m);
void 	move_up(t_map *m, int current_loc, int width, char self, char enemy);
void 	move_down(t_map *m, int current_loc, int width, char self, char enemy);
void 	move_right(t_map *m, int current_loc, char self, char enemy);
void 	move_left(t_map *m, int current_loc, char self, char enemy);
void 	draw(t_map *m);
int 	enemy_move(t_map *map);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
void 	print_move(t_map *map);
int 	locate_E(t_map *m);
void 	death(int loc_p, int loc_e, int loc_en);
int 	locate_exit(t_map *m);
int		ft_strlen(char *s);
void  	term(int p_loc, int e_loc, int en_loc);
void 	ft_in(t_map *m, int hight, int width);
char	*ft_itoa(int n);
void 	ft_init_xlm(t_map *map);

#endif