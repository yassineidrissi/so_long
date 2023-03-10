/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:18:17 by yaidriss          #+#    #+#             */
/*   Updated: 2023/03/10 23:19:37 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	
// int ft_capture(int key,t_map *m)
// {
//     (void) key;
//     (void) *m;
//     return 0;
// }
t_loc *position(int i, int j)
{
    t_loc *pos = NULL;

    pos->x = i;
    pos->y = j;
    return(pos);
}

void move_up(t_map *m, int i, int j, char self, char enemy)
{
    
    (void) enemy;
	if(m->map[i - 1][j] == '0' || (m->map[i - 1][j] == 'E' && m->count_c)) 
    {
        m->map[i][j] = '0';
        m->player->x = i - 1;
				m->player->y = j;
        m->map[i - 1][j] = self;
        m->map[i][j] = '0';
    }
    else if(m->map[i - 1][j] == 'C') 
    {
				m->map[i][j] = '0';
        m->player->x = i - 1;
				m->player->y = j;
        m->map[i - 1][j] = self;
        m->map[i][j] = '0';
				m->count_c--;
    }
		else if(m->map[i - 1][j] == 'C') 
    {
				m->map[i][j] = '0';
        m->player->x = i - 1;
				m->player->y = j;
        m->map[i - 1][j] = self;
        m->map[i][j] = '0';
				m->count_c--;
    }
		// else  if(m->exit.x == i - 1 && m->exit.y == j && m->count_c)
		// {
		// 		m->map[i][j] = '0';
		// 		m->player->x = i - 1;
		// 		m->player->y = j;
		// 		m->map[i - 1][j] = self;
		// 		m->map[i][j] = '0';
		// }
    else  if(m->exit.x == i - 1 && m->exit.y == j && !m->count_c)
        exit(0);
}

void move_down(t_map *m, int i, int j, char self, char enemy)
{
    
    (void) enemy;
	if(m->map[i + 1][j] == '0' || (m->map[i + 1][j] == 'E' && m->count_c)) 
    {
        m->map[i][j] = '0';
        m->player->x = i + 1;
				m->player->y = j;
        m->map[i + 1][j] = self;
        m->map[i][j] = '0';
    }
    else if(m->map[i + 1][j] == 'C') 
    {
				m->map[i][j] = '0';
        m->player->x = i + 1;
				m->player->y = j;
        m->map[i + 1][j] = self;
        m->map[i][j] = '0';
				m->count_c--;
    }
		// else  if(m->exit.x == i + 1 && m->exit.y == j && m->count_c)
		// {
		// 		m->map[i][j] = '0';
		// 		m->map[i + 1][j] = self;
		// 		m->map[i][j] = '0';
		// }
    else  if(m->exit.x == i + 1 && m->exit.y == j && !m->count_c)
        exit(0);
}

void move_right(t_map *m, int i, int j, char self, char enemy)
{
    
    (void) enemy;
	if(m->map[i][j + 1] == '0' || (m->map[i][j + 1] == 'E' && m->count_c)) 
    {
        m->map[i][j] = '0';
        m->player->x = i;
				m->player->y = j + 1;
        m->map[i][j + 1] = self;
        m->map[i][j] = '0';
    } 
    else if(m->map[i][j + 1] == 'C') 
    {
				m->map[i][j] = '0';
        m->player->x = i;
				m->player->y = j + 1;
        m->map[i][j + 1] = self;
        m->map[i][j] = '0';
				m->count_c--;
    }
		// else  if(m->exit.x == i && m->exit.y == j + 1 && m->count_c)
		// {
		// 		m->map[i][j] = '0';
		// 		m->map[i][j + 1] = self;
		// 		m->map[i][j] = '0';
		// }
    else  if(m->exit.x == i && m->exit.y == j + 1 && !m->count_c)
        exit(0);
}

void move_left(t_map *m, int i, int j, char self, char enemy)
{
    
    (void) enemy;
	if(m->map[i][j - 1] == '0' || (m->map[i][j - 1] == 'E' && m->count_c)) 
    {
        m->map[i][j - 1] = '0';
        m->player->x = i;
				m->player->y = j - 1;
        m->map[i][j - 1] = self;
        m->map[i][j] = '0';
    }
    else if(m->map[i][j - 1] == 'C') 
    {
				m->map[i][j] = '0';
        m->player->x = i;
				m->player->y = j - 1;
        m->map[i][j - 1] = self;
        m->map[i][j] = '0';
				m->count_c--;
    }
		// else  if(m->exit.x == i && m->exit.y == j - 1 && m->count_c)
		// {
		// 		m->map[i][j] = '0';
		// 		m->player->x = i;
		// 		m->player->y = j - 1;
		// 		m->map[i][j - 1] = self;
		// 		m->map[i][j] = '0';
		// }
    else  if(m->exit.x == i && m->exit.y == j - 1 && !m->count_c)
        exit(0);
}

// void move_down(t_map *m, int current_loc, int width, char self, char enemy)
// {
//     if(m->map[current_loc + width ] == '0')
//     {
//         m->map[m->current_location] = '0';
//         m->current_location = m->current_location + m->width  ;
//         m->map[m->current_location] = self;
//         m->count_moves++;  
//     }
//     else if(m->map[current_loc + width ] == enemy)
//         exit(0);
// }

// void move_right(t_map *m, int current_loc, char self, char enemy)
// {
//     if(m->map[current_loc + 1] == '0')
//     {
//         m->map[m->current_location] = '0';
//         m->current_location = m->current_location +  1;
//         m->map[m->current_location] = self;
//         m->count_moves++;  
//     }
//     else if(m->map[current_loc + 1] == enemy) 
//         exit(0);
// }

// void move_left(t_map *m, int current_loc, char self, char enemy)
// {
//     if(m->map[current_loc - 1] == '0') 
//     {
//         m->map[m->current_location] = '0';
//         m->current_location = m->current_location - 1;
//         m->map[m->current_location] = self;
//         m->count_moves++;  
//     }
//     else if(m->map[current_loc - 1] == enemy)
//         exit(0);
// }

int  move_char(int c, t_map *m)
{
    int i = m->player->x;
    int j = m->player->y;
     
		if (!m->count_c)
			m->map[m->exit.x][m->exit.y] = 'E';
    if(c == 13)
		{
      move_up(m, i, j, 'P', 'N');
			m->img_player = mlx_xpm_file_to_image(m->mlx, "./img/player.xpm",&m->img_w, &m->img_h);
		}
		// ft_printf("im here insade the move_char \n");
    else if(c == 0)
		{
      move_left(m, i, j, 'P', 'N');
			m->img_player = mlx_xpm_file_to_image(m->mlx, "./img/player_left.xpm",&m->img_w, &m->img_h);
		}
    else if(c == 1)
		{
      move_down(m, i, j,'P', 'N');
			m->img_player = mlx_xpm_file_to_image(m->mlx, "./img/player_down.xpm",&m->img_w, &m->img_h);
		}
    else if(c == 2)
		{
	    move_right(m, i, j, 'P', 'N');
			m->img_player = mlx_xpm_file_to_image(m->mlx, "./img/player_right.xpm",&m->img_w, &m->img_h);
		}
		draw(m);
    // print_map(m);
	return (0);
}

// void death(int loc_p, int loc_e, int loc_en)
// {
//     if (loc_p == loc_en)
//     {
//         ft_printf("hero died\n");
//         exit(0);
//     }
//     else if(loc_p == loc_e)
//     {
//         ft_printf("game finished\n");
//         exit(0);
//     }
// }

// int locate_exit(t_map *m)
// {
//     int i;
//     i = m->width + 2;
//     while (m->map[i] != 'E')
//         i++;
//     m->current_location  = i; 
//     return (i);
// }

int locate_p(t_map *m)
{
    int i;
    int j;
    j = 0;
    i = m->width;
    while (m->map[i][j] != 'N')
        i++;
    m->current_location  = i; 
    return (i);
}

// int enemy_move(t_map *map)
// {
//     int enemy_loc;
//     static int flag;
    
//     enemy_loc = locate_E(map);
//     if (map->map[enemy_loc + 1 ] != '1' && flag == 0) 
//         move_right(map,enemy_loc,'N','P');
//     else if (map->map[enemy_loc - 1 ] != '1' )
//     {
//         flag = 1;
//          if (map->map[enemy_loc - 2 ] == '1' )
//             flag =0;
//         move_left(map,enemy_loc,'N','P');
//     }
//     usleep(100000);
//     draw(map);
//     return 0;
// }