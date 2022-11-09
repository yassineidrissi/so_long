/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:50:09 by yaidriss          #+#    #+#             */
/*   Updated: 2022/11/09 18:57:10 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	(void)ac;

	t_map map;

	map.fd = open(av[1],O_RDONLY);
	if (map.fd < 0)
		handl_errors(1);
	fill_map(&map);
	validation(&map);
	// while(map.map[i])
	// 	printf("%s\n",map.map[i++]);
}