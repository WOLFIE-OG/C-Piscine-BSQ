/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:30:24 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 22:15:17 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int	can_place_square(t_map *map, uint32_t x, uint32_t y, uint32_t size)
{
	uint32_t	index;

	if ((y + size > map->nbr_line) || (x + size > map->max_length))
		return (0);
	index = 0;
	while (index < size)
		if (ft_strnchr(&map->map[y + index++][x], size, 'o'))
			return (0);
	return (1);
}

void	square_init(t_square *square)
{
	square->x = 0;
	square->y = 0;
	square->size = 0;
}

void	square_set(t_square *square, uint32_t x, uint32_t y, uint32_t size)
{
	square->x = x;
	square->y = y;
	square->size = size;
}

void	try(t_map *map, t_square *square, uint32_t x, uint32_t y)
{
	uint32_t	size;

	size = 1;
	while (size <= map->nbr_line && size <= map->max_length)
	{
		if (can_place_square(map, x, y, size) == 1)
			if (size > square->size)
				square_set(square, x, y, size);
		++size;
	}
}

t_square	*bsq_solver(t_map *map)
{
	uint32_t	x;
	uint32_t	y;
	t_square	*square;

	square = malloc(sizeof(t_square));
	if (!square)
		return (NULL);
	square_init(square);
	y = 0;
	while (y < map->nbr_line)
	{
		x = 0;
		while (x < map->max_length)
			try(map, square, x++, y);
		++y;
	}
	return (square);
}
