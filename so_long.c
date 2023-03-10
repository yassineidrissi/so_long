/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:24:00 by yaidriss          #+#    #+#             */
/*   Updated: 2023/03/10 23:29:55 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pix(t_map *m, int i, int j)
{
	if (m->map[i][j] == '1')
		mlx_put_image_to_window(m->mlx, m->window, m->img, \
	j * 48, i * 48);
	else if (m->map[i][j] == 'P')
		mlx_put_image_to_window(m->mlx, m->window, \
	m->img_player, j * 48, i * 48);
	else if (m->exit.x == i && m->exit.y == j && !m->count_c)
		mlx_put_image_to_window(m->mlx, m->window, \
			m->img_door, j * 48, i * 48);
	else if (m->exit.x == i && m->exit.y == j && m->count_c)
		mlx_put_image_to_window(m->mlx, m->window, \
		m->img_floor, j * 48, i * 48);
	else if (m->map[i][j] == '0')
		mlx_put_image_to_window(m->mlx, m->window, \
		m->img_floor, j * 48, i * 48);
	else if (m->map[i][j] == 'C')
		mlx_put_image_to_window(m->mlx, m->window, \
		m->img_colc, j * 48, i * 48);
}

void	draw(t_map *m)
{
	int	j;
	int	i;

	i = -1;
	j = 0;
	while (++i < m->hight)
	{
		j = -1;
		while (++j < m->width)
		{
			put_pix(m, i, j);
		}
	}
}

void	ft_init_xlm(t_map *map)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, (map->width * 48), \
	(map->hight * 48), "hello world");
	map->img = mlx_xpm_file_to_image(map->mlx, "./img/wall.xpm", \
	&map->img_w, &map->img_h);
	map->img_floor = mlx_xpm_file_to_image(map->mlx, "./img/free_tile.xpm", \
	&map->img_w, &map->img_h);
	map->img_door = mlx_xpm_file_to_image(map->mlx, "./img/door.xpm", \
	&map->img_w, &map->img_h);
	map->img_player = mlx_xpm_file_to_image(map->mlx, "./img/player.xpm", \
	&map->img_w, &map->img_h);
	map->img_colc = mlx_xpm_file_to_image(map->mlx, "./img/coin.xpm", \
	&map->img_w, &map->img_h);
	if (!map->mlx || !map->window || !map->img || !map->img_floor || !map->img_colc)
		handl_errors(1);
}
	//! need to add condition for protection!
	//! add esc to exit 

int	ft_close(t_map *map)
{
	ft_free_double(map->map);
	close(map->fd);
	exit(1);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		handl_errors(10);
	validation_args(av[1]);
	map.fd = open(av[1], O_RDONLY);
	if (map.fd < 0)
		handl_errors(1);
	fill_map(&map);
	validation(&map);
	ft_init_xlm(&map);
	draw(&map);
	mlx_key_hook(map.window, move_char, &map);
	mlx_hook(map.window, 17, 0, ft_close, &map);
	mlx_loop(map.mlx);
	return (0);
}

//! give me the name of the script to handl the norminette : C_formater_4