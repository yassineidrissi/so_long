/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:50:09 by yaidriss          #+#    #+#             */
/*   Updated: 2022/10/30 19:05:53 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	void(ac);
	t_map map;

	map.fd = open(av[0],O_RDONLY);
	if (map.fd < 0)
		handl_errors(1);
	
	
		
}