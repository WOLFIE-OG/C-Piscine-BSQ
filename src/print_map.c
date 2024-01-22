/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:35:05 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 23:35:25 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

void	print_map(t_map *map)
{
	char		**surface;
	uint32_t	nbr_line;

	if (!map)
		return ;
	nbr_line = map->nbr_line;
	surface = map->map;
	while (nbr_line--)
	{
		write(1, *surface++, map->max_length);
		write(1, "\n", 1);
	}
}
