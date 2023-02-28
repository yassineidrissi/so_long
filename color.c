/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:02:10 by yaidriss          #+#    #+#             */
/*   Updated: 2023/03/01 00:22:06 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void yellow()
{
  ft_printf("\033[1;33m");
}

void red()
{
    ft_printf("\033[1;31m");
}

void reset()
{
    ft_printf("\033[0m");
}

void Green()
{
    ft_printf("\033[0;32m");
}

void Black()
{    
    ft_printf("\033[0;30m");
}
void Cyan()
{
    ft_printf("\033[0;36m");
}
    