/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:35:17 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/21 22:26:32 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	
int ft_capture(int key,t_map *m)
{
    (void) key;
    (void) *m;
    return 0;
}

void move_up(t_map *m, int current_loc, int width, char self, char enemy)
{
    if(m->map[current_loc - width] == '0') 
    {
        m->map[m->current_location] = '0';
        m->current_location = m->current_location - m->width  ;
        m->map[m->current_location] = self;
        m->count_moves++;
    }
    else  if(m->map[current_loc - width] == enemy)
        exit(0);
}

void move_down(t_map *m, int current_loc, int width, char self, char enemy)
{
    if(m->map[current_loc + width ] == '0')
    {
        m->map[m->current_location] = '0';
        m->current_location = m->current_location + m->width  ;
        m->map[m->current_location] = self;
        m->count_moves++;  
    }
    else if(m->map[current_loc + width ] == enemy)
        exit(0);
}

void move_right(t_map *m, int current_loc, char self, char enemy)
{
    if(m->map[current_loc + 1] == '0')
    {
        m->map[m->current_location] = '0';
        m->current_location = m->current_location +  1;
        m->map[m->current_location] = self;
        m->count_moves++;  
    }
    else if(m->map[current_loc + 1] == enemy) 
        exit(0);
}

void move_left(t_map *m, int current_loc, char self, char enemy)
{
    if(m->map[current_loc - 1] == '0') 
    {
        m->map[m->current_location] = '0';
        m->current_location = m->current_location - 1;
        m->map[m->current_location] = self;
        m->count_moves++;  
    }
    else if(m->map[current_loc - 1] == enemy)
        exit(0);
}

int  move_char(int c, t_map *m)
{
    int current_loc = locate_p(m);
    int width = m->width;
    
    if(c == 13)
        move_up(m, current_loc, width, 'P', 'N');
    else if(c == 0)
        move_left(m, current_loc, 'P', 'N');
    else if(c == 1)
        move_down(m, current_loc, width, 'P', 'N');
    else if(c == 2)
        move_right(m, current_loc, 'P', 'N');
    draw(m);
    print_map(m);
	return (0);
}

void death(int loc_p, int loc_e, int loc_en)
{
    if (loc_p == loc_en)
    {
        printf("hero died\n");
        exit(0);
    }
    else if(loc_p == loc_e)
    {
        printf("game finished\n");
        exit(0);
    }
}

int locate_exit(t_map *m)
{
    int i;
    i = m->width + 2;
    while (m->map[i] != 'E')
        i++;
    m->current_location  = i; 
    return (i);
}

int locate_E(t_map *m)
{
    int i;
    i = m->width;
    while (m->map[i] != 'N')
        i++;
    m->current_location  = i; 
    return (i);
}

int enemy_move(t_map *map)
{
    int enemy_loc;
    static int flag;
    
    enemy_loc = locate_E(map);
    if (map->map[enemy_loc + 1 ] != '1' && flag == 0) 
        move_right(map,enemy_loc,'N','P');
    else if (map->map[enemy_loc - 1 ] != '1' )
    {
        flag = 1;
         if (map->map[enemy_loc - 2 ] == '1' )
            flag =0;
        move_left(map,enemy_loc,'N','P');
    }
    usleep(100000);
    draw(map);
    return 0;
}