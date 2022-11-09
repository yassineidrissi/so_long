/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:06:10 by yaidriss          #+#    #+#             */
/*   Updated: 2022/11/08 19:24:13 by yaidriss         ###   ########.fr       */
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
	
	i = 0;
	map->hight = 0;
	while(map->map[map->hight])
		map->hight++;
	map->width = ft_strlen(map->map[0]);
	while(map->map[i])
		if(ft_strlen(map->map[i++]) == map->width)
			;
	if (i != map->hight)
		handl_errors(2);
}

void test_walls(t_map *map)
{
	int i;

	i = 0;
	while(map->map[0][i])
		if(map->map[0][i] != 1 || map->map[map->hight - 1][i++] != 1)
			handl_errors(2);
	i = 0;
	while(map->map[i][0])
		if(map->map[i][0] != 1 || map->map[map->width - 1][i++] != 1)
			handl_errors(2);
	
	
}

void	validation(t_map	*map)
{
	test_rectangular(map);
	test_walls(map);
}