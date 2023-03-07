/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemnet2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:46:25 by yaidriss          #+#    #+#             */
/*   Updated: 2023/03/07 22:50:45 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_char_plus(int c, t_map *m, int i, int j)
{
	if (c == 13)
	{
		move_up(m, i, j, 'P');
		m->img_char = mlx_xpm_file_to_image(m->mlx, "./img/player.xpm" \
		, &m->img_w, &m->img_h);
	}
	else if (c == 0)
	{
		move_left(m, i, j, 'P');
		m->img_char = mlx_xpm_file_to_image(m->mlx, "./img/player_left.xpm" \
		, &m->img_w, &m->img_h);
	}
	else if (c == 1)
	{
		move_down(m, i, j, 'P');
		m->img_char = mlx_xpm_file_to_image(m->mlx, "./img/player_down.xpm" \
		, &m->img_w, &m->img_h);
	}
	else if (c == 2)
	{
		move_right(m, i, j, 'P');
		m->img_char = mlx_xpm_file_to_image(m->mlx, "./img/player_right.xpm" \
		, &m->img_w, &m->img_h);
	}
	draw(m);
}
