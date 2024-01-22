/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_metadata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:28:10 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 21:52:09 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

static void	load(t_map *map, char *nbr, char *block)
{
	map->nbr_line = ft_atoi(nbr);
	map->char_empty = block[0];
	map->char_obstacle = block[1];
	map->char_full = block[2];
}

static int32_t	extra_metadata(t_map *map, char *str)
{
	char		*nbr;
	char		*block;
	uint32_t	len_str;

	len_str = ft_strlen(str);
	nbr = ft_strndup(str, len_str - 3);
	if (!nbr)
		return (0);
	if (!ft_str_is_numeric(nbr))
	{
		free(nbr);
		return (0);
	}
	block = ft_strdup(str + len_str - 3);
	if (!block)
	{
		free(nbr);
		return (0);
	}
	load(map, nbr, block);
	free(nbr);
	free(block);
	return (1);
}

char	*load_metadata(t_map *map, char *str)
{
	char *const	tail = ft_strstr(str, "\n");
	uint32_t	len;
	char		*tmp;

	if (!tail)
		return (NULL);
	len = tail - str;
	if (len < 4 || len > 10)
		return (NULL);
	tmp = ft_strndup(str, len);
	if (!ft_str_is_printable(tmp) || !extra_metadata(map, tmp))
	{
		free(tmp);
		return (NULL);
	}
	return (tail + 1);
}
