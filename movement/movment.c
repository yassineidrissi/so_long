/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:18:17 by yaidriss          #+#    #+#             */
/*   Updated: 2023/03/07 22:55:43 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *m, int i, int j, char self)
{
	if (m->map[i - 1][j] == '0' || (m->map[i - 1][j] == 'E' && m->count_c))
	{
		m->map[i][j] = '0';
		m->player.x = i - 1;
		m->player.y = j;
		m->map[i - 1][j] = self;
		m->map[i][j] = '0';
	}
	else if (m->map[i - 1][j] == 'C')
	{
			m->map[i][j] = '0';
			m->player.x = i - 1;
			m->player.y = j;
			m->map[i - 1][j] = self;
			m->map[i][j] = '0';
			m->count_c--;
	}
	else if (m->exit.x == i - 1 && m->exit.y == j && !m->count_c)
		exit(0);
}
		// else  if(m->exit.x == i - 1 && m->exit.y == j && m->count_c)
		// {
		// 		m->map[i][j] = '0';
		// 		m->player.x = i - 1;
		// 		m->player.y = j;
		// 		m->map[i - 1][j] = self;
		// 		m->map[i][j] = '0';
		// }

void	move_down(t_map *m, int i, int j, char self)
{
	if (m->map[i + 1][j] == '0' || (m->map[i + 1][j] == 'E' && m->count_c))
	{
			m->map[i][j] = '0';
			m->player.x = i + 1;
			m->player.y = j;
			m->map[i + 1][j] = self;
			m->map[i][j] = '0';
	}
	else if (m->map[i + 1][j] == 'C')
	{
			m->map[i][j] = '0';
			m->player.x = i + 1;
			m->player.y = j;
			m->map[i + 1][j] = self;
			m->map[i][j] = '0';
			m->count_c--;
	}
	else if (m->exit.x == i + 1 && m->exit.y == j && !m->count_c)
		exit(0);
}
		// else  if(m->exit.x == i + 1 && m->exit.y == j && m->count_c)
		// {
		// 		m->map[i][j] = '0';
		// 		m->map[i + 1][j] = self;
		// 		m->map[i][j] = '0';
		// }

void	move_right(t_map *m, int i, int j, char self)
{
	if (m->map[i][j + 1] == '0' || (m->map[i][j + 1] == 'E' && m->count_c))
	{
			m->map[i][j] = '0';
			m->player.x = i;
			m->player.y = j + 1;
			m->map[i][j + 1] = self;
			m->map[i][j] = '0';
	}
	else if (m->map[i][j + 1] == 'C')
	{
			m->map[i][j] = '0';
			m->player.x = i;
			m->player.y = j + 1;
			m->map[i][j + 1] = self;
			m->map[i][j] = '0';
			m->count_c--;
	}
	else if (m->exit.x == i && m->exit.y == j + 1 && !m->count_c)
		exit(0);
}

void	move_left(t_map *m, int i, int j, char self)
{
	if (m->map[i][j - 1] == '0' || (m->map[i][j - 1] == 'E' && m->count_c))
	{
			m->map[i][j - 1] = '0';
			m->player.x = i;
			m->player.y = j - 1;
			m->map[i][j - 1] = self;
			m->map[i][j] = '0';
	}
	else if (m->map[i][j - 1] == 'C')
	{
			m->map[i][j] = '0';
			m->player.x = i;
			m->player.y = j - 1;
			m->map[i][j - 1] = self;
			m->map[i][j] = '0';
			m->count_c--;
	}
	else if (m->exit.x == i && m->exit.y == j - 1 && !m->count_c)
		exit(0);
}

int	move_char(int c, t_map *m)
{
	if (!m->count_c)
		m->map[m->exit.x][m->exit.y] = 'E';
	move_char_plus(c, m, m->player.x, m->player.y);
	draw(m);
	return (0);
}
// print_map(m);
// ft_printf("im here insade the move_char \n");