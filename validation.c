/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:06:10 by yaidriss          #+#    #+#             */
/*   Updated: 2022/11/09 19:38:20 by yaidriss         ###   ########.fr       */
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
	printf("%d\n", i);
}

void	validation(t_map	*map)
{
	test_rectangular(map);
	test_walls(map);
}