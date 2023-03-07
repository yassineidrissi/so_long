/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:18:17 by yaidriss          #+#    #+#             */
/*   Updated: 2023/03/07 22:07:34 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_loc	*position(int i, int j)
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
    else  if(m->exit.x == i && m->exit.y == j - 1 && !m->count_c)
        exit(0);
}

int  move_char(int c, t_map *m)
{
    int i = m->player->x;
    int j = m->player->y;
     
		if (!m->count_c)
			m->map[m->exit.x][m->exit.y] = 'E';
    if(c == 13)
		{
      move_up(m, i, j, 'P', 'N');
			m->img_char = mlx_xpm_file_to_image(m->mlx, "./img/player.xpm",&m->img_w, &m->img_h);
		}
		// ft_printf("im here insade the move_char \n");
    else if(c == 0)
		{
      move_left(m, i, j, 'P', 'N');
			m->img_char = mlx_xpm_file_to_image(m->mlx, "./img/player_left.xpm",&m->img_w, &m->img_h);
		}
    else if(c == 1)
		{
      move_down(m, i, j,'P', 'N');
			m->img_char = mlx_xpm_file_to_image(m->mlx, "./img/player_down.xpm",&m->img_w, &m->img_h);
		}
    else if(c == 2)
		{
	    move_right(m, i, j, 'P', 'N');
			m->img_char = mlx_xpm_file_to_image(m->mlx, "./img/player_right.xpm",&m->img_w, &m->img_h);
		}
		draw(m);
    // print_map(m);
	return (0);
}
