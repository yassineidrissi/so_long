/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:59:46 by yaidriss          #+#    #+#             */
/*   Updated: 2022/11/07 19:46:21 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handl_errors(int i)
{
	red();
	if (i == 1)
		printf("map unvalied \n");
	else if (i == 3)
		printf("\nborder unvalid\n");
	else if (i == 4)
		printf("\nUpper / Lower boarder is not valid\n");
	else if (i == 5)
		printf("\nside boarder not valid\n");
	else if (i == 6)
		printf("\nreading error\n");
	else if (i == 7)
		printf("\nFailed >> Moved outside map boarder\n");
	else if (i == 8)
		printf("\nFailed >> No Valid Path \n");
	else if (i == 9)
		printf("Failed >> 1 or More of Required Element Missing  \n");
	reset();
	exit(0);
}
