/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:06:10 by yaidriss          #+#    #+#             */
/*   Updated: 2022/11/08 18:21:12 by yaidriss         ###   ########.fr       */
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
	map->width = ft_strlen(map->map[0]);
	while(map->map[i])
		if(ft_strlen(map->map[i]) == map->width)
			
}

int	validation(t_map	*map)
{
	test_rectangular(map);
}