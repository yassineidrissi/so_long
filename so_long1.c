/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:08:19 by yaidriss          #+#    #+#             */
/*   Updated: 2023/01/22 20:16:52 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 

int main(int ac, char **av)
{
	char storge[500];
	if(ac != 2)
	{
		printf("Error\n");
		return (0);
	}
	int fd = open(av[1], O_RDONLY);
	printf("our fd is : %d\n", fd);
	read(fd,storge,500);
	printf("our storge is :\n%s\n", storge);
	return (0);
	
}