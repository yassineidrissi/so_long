/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:23:14 by yaidriss          #+#    #+#             */
/*   Updated: 2022/11/09 20:23:36 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char	*s1)
{
	char	*s;
	char	*ptr;
	int		i;

	i = 0;
	s = (char *)s1;
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (0);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
