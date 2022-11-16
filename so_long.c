/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:50:09 by yaidriss          #+#    #+#             */
/*   Updated: 2022/11/16 20:27:21 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_xlm(t_map *map)
{
    map->mlx = mlx_init();
    map->window = mlx_new_window(map->mlx,(map->width * 48),(map->hight * 48),"hello world");
    map->img = mlx_xpm_file_to_image(map->mlx,"./img/wall.xpm",&map->img_w, &map->img_h);
    map->img_floor = mlx_xpm_file_to_image(map->mlx,"./img/free_tile.xpm",&map->img_w, &map->img_h);
    map->img_door = mlx_xpm_file_to_image(map->mlx, "./img/door.xpm",&map->img_w, &map->img_h);
    map->img_char = mlx_xpm_file_to_image(map->mlx, "./img/knor.xpm",&map->img_w, &map->img_h);
    map->img_clc = mlx_xpm_file_to_image(map->mlx,  "./img/coin.xpm",&map->img_w, &map->img_h);
    map->img_eney = mlx_xpm_file_to_image(map->mlx, "./img/enemy.xpm", &map->img_w, &map->img_h);  
}

int	main(int ac, char **av)
{
	int i = -1;
	t_map	map;

	(void)ac;
	map.fd = open(av[1], O_RDONLY);
	if (map.fd < 0)
		handl_errors(1);
	fill_map(&map);
	validation(&map);
	while(map.map2[++i])
		printf("%s\n",map.map2[i]);
	void	ft_init_xlm(t_map *map);
}
