/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:50:09 by yaidriss          #+#    #+#             */
/*   Updated: 2022/11/22 21:32:34 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw(t_map *m)
{
    int j;
    int i;  

    i = -1;
    while(i < m->hight)
    {
        j = -1;
        while(j <= m->size)
        {   
            if (m->map[i][j] == '1')
                mlx_put_image_to_window(m->mlx, m->window, m->img, j,i);
            else if(m->map[i][j] == '0') 
                mlx_put_image_to_window(m->mlx, m->window, m->img_floor, j,i);
            else if(m->map[i][j] == 'E') 
                mlx_put_image_to_window(m->mlx, m->window, m->img_door, j,i);
            else if(m->map[i][j] == 'P') 
                mlx_put_image_to_window(m->mlx, m->window, m->img_char, j,i);
            else if(m->map[i][j] == 'C') 
                mlx_put_image_to_window(m->mlx, m->window, m->img_clc, j,i);
            else if(m->map[i][j] == 'N') 
                mlx_put_image_to_window(m->mlx, m->window, m->img_eney, j,i);
        }
    }
    mlx_string_put(m->mlx, m->window, 10, 10, 0xFFFF5615, ft_itoa(m->count_moves));
}

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
	ft_init_xlm(&map);
	while(map.map2[++i])
		printf("%s\n",map.map2[i]);
	// print_map(&map);
    draw(&map);
 	// mlx_key_hook(map.window, move_char, &map);
    // mlx_loop_hook(map.mlx, enemy_move,&map);
    // mlx_loop(map.mlx);
}
