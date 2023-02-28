#include "so_long.h"

void  term(int p_loc, int e_loc, int en_loc)
{
    if(p_loc == e_loc )
    {
        ft_printf("\nthe end\n");
        exit(0);
    }
    else if ( p_loc == en_loc)
    {
        ft_printf("\nhero died\n");
        exit(0);
    }
}

void ft_in(t_map *m, int hight, int width)
{
    m->hight = hight;
    m->width = width;
    m->size = hight * width;
    m->count_moves = 0;
}