/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:38:50 by yaidriss          #+#    #+#             */
/*   Updated: 2023/03/07 22:00:56 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validation(t_map	*map)
{
	test_rectangular(map);
	test_walls(map);
	test_caraters(map);
	test_valid_map(map);
	if (!find_path_map(map->map2))
		handl_errors(8);
	ft_free_double(map->map2);
}

void	validation_args(char *v)
{
	char	**s;

	s = ft_split(v, '.');
	if (!s || !s[0] || !s[1] || s[2] || ft_cmp(s[1], "ber"))
	{
		ft_free_double(s);
		handl_errors(10);
	}
	ft_free_double(s);
}

t_loc	ft_location(t_map *m, char c)
{
	t_loc	pos;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (++i < m->hight)
	{
		j = -1;
		while (m->map[i][++j])
		{
			if (m->map[i][j] == c)
			{
					pos.x = i;
					pos.y = j;
			}
		}
	}
	return (pos);
}

// ft_printf("the value of s[1] is %d\n", ft_cmp(s[1], "ber"));
// void	fill_map(t_map *map)
// {
// 	char	*buffer;
// 	char	*buffer2;

// 	map->next = (char *)1;
// 	buffer = NULL;
// 	while (map->next)
// 	{
// 		map->next = get_next_line(map->fd);
// 		buffer = ft_my_strjoin(buffer, map->next, 1);
// 	}
// 	buffer2 = ft_strdup(buffer);
// 	map->map = ft_split(buffer, '\n');
// 	map->map2 = ft_split(buffer2, '\n');
// 	free(buffer);
// 	free(buffer2);
// }

// void	test_rectangular(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = 0;
// 	map->hight = 0;
// 	while (map->map[map->hight])
// 		map->hight++;
// 	map->width = ft_strlen(map->map[0]);
// 	while (map->map[i])
// 		if (ft_strlen(map->map[i++]) == map->width)
// 			j++;
// 	if (j != map->hight)
// 		handl_errors(3);
// }

// void	test_walls(t_map *map)
// {
// 	int	i;

// 	i = -1;
// 	while (map->map[0][++i])
// 		if (map->map[0][i] != '1' || map->map[map->hight - 1][i] != '1')
// 			handl_errors(3);
// 	i = -1;
// 	while (++i < map->hight)
// 		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
// 			handl_errors(3);
// }

// void	test_caraters(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	map->count_p = 0;
// 	map->count_e = 0;
// 	map->count_c = 0;
// 	while (++i < map->hight)
// 	{
// 		j = -1;
// 		while (map->map[i][++j])
// 		{
// 			if (map->map[i][j] == 'P')
// 			{
// 				map->count_p++;
// 				map->first_p = i;
// 				map->second_p = j;
// 			}
// 			else if (map->map[i][j] == 'C')
// 				map->count_c++;
// 			else if (map->map[i][j] == 'E')
// 				map->count_e++;
// 		}
// 	}
// 	if (map->count_p != 1 || map->count_e != 1 || map->count_c < 1)
// 		handl_errors(9);
// }

// // int	test_valid_map(t_map *map, int i,int j)
// // {
// // 	char **mp = map->map2;
// // 	map->valid = 0;
// // 	if (mp[i + 1][j] == 'E' |
//| mp[i - 1][j] == 'E'|| mp[i][j + 1] == 'E' || mp[i][j - 1] == 'E')
// // 		map->valid = 1;
// // 	if (mp[i + 1][j]
// != 'E' && mp[i + 1][j] != 'z' && mp[i + 1][j] != '1' && map->valid)
// // 	{
// // 		mp[i + 1][j] = 'z';
// // 		map->valid = test_valid_map(map,i + 1,j);
// // 	}
// // 	if (mp[i][j + 1] != 'E' && mp[i][j
// + 1] != 'z' && mp[i][j + 1] != '1'&& map->valid)
// // 	{
// // 		mp[i][j + 1] = 'z';
// // 		map->valid = test_valid_map(map,i,j + 1);
// // 	}
// // 	if (mp[i - 1][j] != 'E' && mp[i - 1][j]
// != 'z' && mp[i - 1][j] != '1'&& map->valid)
// // 	{
// // 		mp[i - 1][j] = 'z';
// // 		map->valid = test_valid_map(map,i - 1,j);
// // 	}
// // 	if (mp[i][j - 1] /
//!= 'E' && mp[i][j - 1] != 'z' && mp[i][j - 1] != '1'&& map->valid)
// // 	{
// // 		mp[i][j - 1] = 'z';
// // 		map->valid = test_valid_map(map,i,j - 1);
// // 	}
// // 	ft_printf("we are in localisation %d,%d\n",i, j);
// // 	return(map->valid);
// // }

// void change_neighbor(char **mp,int i,int j)
// {
// 	int k;
// 	int h;

// 	k = -1;
// 	while(k < 2)
// 	{	
// 		h = -1;
// 		while(h < 2)
// 		{
// 			if(mp[i + k][i + h] != 'V' && mp[i + k][j + h] != '1')	
// 				mp[i][j] = 'V';
// 			h += 2;
// 		}
// 		k += 2;	
// 	}
// }
// int	test_valid_map(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	char **mp = map->map2;

// 	i = 0;
// 	while (++i < map->hight)
// 	{
// 		j = -1;
// 		while (mp[i][++j])
// 			if (map->map[i][j] != '1')
// 				change_neighbor(mp, i - 1, j - 1);
// 	}
// 	return(find_path_map(mp,map->hight));
// }

// void	validation(t_map	*map)
// {
// 	test_rectangular(map);
// 	test_walls(map);
// 	test_caraters(map);
// 	ft_printf("i am here");
// 	if (!test_valid_map(map))
// 		handl_errors(8);
// }
