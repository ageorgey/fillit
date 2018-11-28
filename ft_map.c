/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muamdah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:20:47 by muamdah           #+#    #+#             */
/*   Updated: 2018/04/02 15:47:26 by muamdah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_delete(int *tab_coor, char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y])
	{
		if (map[y][x] == tab_coor[8])
			map[y][x] = '.';
		x++;
		if (map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
}

static int		ft_count(char **map)
{
	int y;
	int i;

	y = 0;
	i = 0;
	while (map[y][i] != '\0')
		i++;
	return (i);
}

static int		ft_position(int *tab_coor, char **map, int x, int y)
{
	if (x + tab_coor[3] < 0 || y + tab_coor[2] >= ft_count(map) ||
		map[y + tab_coor[2]][x + tab_coor[3]] != '.')
		return (0);
	if (x + tab_coor[5] < 0 || y + tab_coor[4] >= ft_count(map) ||
		map[y + tab_coor[4]][x + tab_coor[5]] != '.')
		return (0);
	if (x + tab_coor[7] < 0 || y + tab_coor[6] >= ft_count(map) ||
		map[y + tab_coor[6]][x + tab_coor[7]] != '.')
		return (0);
	map[y][x] = tab_coor[8];
	map[y + tab_coor[2]][x + tab_coor[3]] = tab_coor[8];
	map[y + tab_coor[4]][x + tab_coor[5]] = tab_coor[8];
	map[y + tab_coor[6]][x + tab_coor[7]] = tab_coor[8];
	return (1);
}

int				ft_fill(int **tab_final, char **map, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!tab_final[i])
		return (1);
	while (map[y])
	{
		if (map[y][x] == '.')
			if (ft_position(tab_final[i], map, x, y))
			{
				if (ft_fill(tab_final, map, i + 1))
					return (1);
				ft_delete(tab_final[i], map);
			}
		x++;
		if (map[y][x] == '\0')
		{
			y++;
			x = 0;
		}
	}
	return (0);
}
