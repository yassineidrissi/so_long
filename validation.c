/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:06:10 by yaidriss          #+#    #+#             */
/*   Updated: 2022/11/07 19:56:35 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_map *map)
{
	map->next = (char *)1;
	char *buffer;

	buffer = NULL;
	while(buffer)
	{
		map->next = get_next_line(map->fd);
		buffer = ft_my_strjoin(buffer , map->next, 1);
	}
	map->map = ft_split(buffer, '\n');
}

// int	validation(t_map	*map)
// {
	
// }