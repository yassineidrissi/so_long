/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:24:00 by yaidriss          #+#    #+#             */
/*   Updated: 2023/02/26 17:25:41 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw(t_map *m)
{
    int j;
    int i;

    i = -1;
    j = 0;
		printf("the width of the map is %d\n",m->width);
		printf("the height of the map is %d\n",m->hight);
    while(++i < m->hight) 
    {
        j = -1;
        while(++j < m->width)
        {   
            if (m->map[i][j] == '1')
                mlx_put_image_to_window(m->mlx, m->window, m->img, j*48, i*48);
            else if(m->map[i][j] == '0') 
                mlx_put_image_to_window(m->mlx, m->window, m->img_floor, j*48, i*48);
            else if(m->map[i][j] == 'E') 
                mlx_put_image_to_window(m->mlx, m->window, m->img_door, j*48, i*48);
            else if(m->map[i][j] == 'P') 
                mlx_put_image_to_window(m->mlx, m->window, m->img_char, j*48, i*48);
            else if(m->map[i][j] == 'C') 
                mlx_put_image_to_window(m->mlx, m->window, m->img_clc, j*48, i*48);
            else if(m->map[i][j] == 'N') 
                mlx_put_image_to_window(m->mlx, m->window, m->img_eney, j*48, i*48);
    				printf("im here and i egale a %d and j = %d\n", i, j);
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
	int i;
	t_map	map;

	(void)ac;
	map.fd = open(av[1], O_RDONLY);
	if (map.fd < 0)
		handl_errors(1);
	fill_map(&map);
	validation(&map);
	i = -1;
    while(map.map2[++i])
		printf("%s\n",map.map2[i]);
	ft_init_xlm(&map);
	// print_map(&map);
    draw(&map);
 	mlx_key_hook(map.window, move_char, &map);
    // mlx_loop_hook(map.mlx, enemy_move,&map);
    mlx_loop(map.mlx);
    return (0);
}
