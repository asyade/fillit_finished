/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:10:20 by acorbeau          #+#    #+#             */
/*   Updated: 2017/04/24 22:40:47 by acorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <string.h>
#include <stdlib.h>

static t_point	*new_point(int x, int y)
{
	t_point *ret;

	if ((ret = (t_point *)malloc(sizeof(t_point *))) == NULL)
		return (NULL);
	ret->x = x;
	ret->y = y;
	return (ret);
}

int	get_tetri(t_tetri **tetri_ptr, char *buffer)
{
    int		pc;
    t_tetri		*tetri;
    int		ti;
    int		i;
    int		j;
    
    i = 0;
    j = 0;
    pc = 0;
    ti = 0;
    if ((tetri = malloc(sizeof(t_tetri))) == NULL)
        return (-1);
    while (buffer[i++])
        pc = (buffer[i - 1] == '#') ? pc + 1 : pc;
    if (pc != 4 || (tetri->points = ft_memalloc(sizeof(t_point) * pc)) == NULL)
    {
        free(tetri);
        return (-1);
    }
    tetri->points_count = pc;
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (buffer[j] == '#')
                if((tetri->points[ti++] = new_point(j, i)) == NULL)
                {
                    free(tetri);
                    return (-1);
                }
            j++;
        }
        buffer += 5;
        i++;
    }
    *tetri_ptr = tetri;
    return (pc);
}
