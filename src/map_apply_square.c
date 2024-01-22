/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_apply_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:42:52 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 18:43:09 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

void	map_apply_square(t_map *map, t_square *square)
{
	uint32_t	index;

	index = 0;
	while (index < square->size)
	{
		ft_strnset(&map->map[square->y + index][square->x],
			map->char_full, square->size);
		++index;
	}
}
