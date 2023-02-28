/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:59:46 by yaidriss          #+#    #+#             */
/*   Updated: 2023/03/01 00:22:09 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handl_errors(int i)
{
	red();
	if (i == 1)
		ft_printf("map unvalied \n");
	else if (i == 3)
		ft_printf("\nborder unvalid\n");
	else if (i == 4)
		ft_printf("\nUpper / Lower boarder is not valid\n");
	else if (i == 5)
		ft_printf("\nside boarder not valid\n");
	else if (i == 6)
		ft_printf("\nreading error\n");
	else if (i == 7)
		ft_printf("\nFailed >> Moved outside map boarder\n");
	else if (i == 8)
		ft_printf("\nFailed >> No Valid Path \n");
	else if (i == 9)
		ft_printf("Failed >> 1 or More of Required Element Missing  \n");
	else if (i == 10)
		ft_printf("Failed >> No Valid Arguements! \n");
	reset();
	exit(0);
}
