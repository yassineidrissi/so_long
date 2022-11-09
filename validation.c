/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:06:10 by yaidriss          #+#    #+#             */
/*   Updated: 2022/11/09 20:17:38 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_map *map)
{
	map->next = (char *)1;
	char *buffer;

	buffer = NULL;
	while(map->next)
	{
		map->next = get_next_line(map->fd);
		buffer = ft_my_strjoin(buffer , map->next, 1);
	}
	map->map = ft_split(buffer, '\n');
}

void test_rectangular(t_map *map)
{
	int i;
	int j;
	
	j = 0;
	i = 0;
	map->hight = 0;
	while(map->map[map->hight])
		map->hight++;
	map->width = ft_strlen(map->map[0]);
	while(map->map[i])
		if(ft_strlen(map->map[i++]) == map->width)
			j++;
	// printf("%d\n %d", j,map->hight);
	if (j != map->hight)
		handl_errors(3);
}

void test_walls(t_map *map)
{
	int i;

	i = -1;
	while(map->map[0][++i])
		if(map->map[0][i] != '1' || map->map[map->hight - 1][i] != '1')
			handl_errors(3);
	i = -1;
	while(++i < map->hight)
		if(map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			handl_errors(3);
}

void test_caraters(t_map *map)
{
	int i;
	int j;

	i = -1;
	map->count_p = 0;
	map->count_e = 0;
	map->count_c = 0;
	while(++i < map->hight)
	{
		j = -1;
		while(map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
				map->count_p++;	
			else if (map->map[i][j] == 'C')
				map->count_c++;
			else if (map->map[i][j] == 'E')
				map->count_e++;
		}
	}
	// printf("%d\n %d %d", map->count_c, map->count_e, map->count_p);
	if(map->count_p != 1 || map->count_e != 1 || map->count_c < 1)
		handl_errors(9);
}

void test_valid_map(t_map *map)
{
	
}

void	validation(t_map	*map)
{
	test_rectangular(map);
	test_walls(map);
	test_caraters(map);
	test_valid_map(map)
}