/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:45:33 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 22:57:49 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

static int32_t	get_line_length(char *str)
{
	char *const	head = str;

	str = ft_strstr(head, "\n");
	if (!str)
		return (0);
	return (str - head);
}

static int32_t	is_valid_content(t_map *map, char *head, char *tail)
{
	--head;
	while (++head < tail)
		if ((*head != map->char_empty) && (*head != map->char_obstacle))
			return (0);
	return (1);
}

int32_t	is_valid_map(t_map *map, char *str)
{
	char			*prev;
	const uint32_t	norm_len = get_line_length(str);
	uint32_t		line_count;

	map->max_length = norm_len;
	if (!norm_len)
		return (0);
	line_count = 0;
	while (*str)
	{
		++line_count;
		if (line_count > norm_len)
			return (0);
		prev = str;
		str = ft_strstr(prev, "\n");
		if (str == NULL)
			break ;
		if ((str - prev != norm_len) || (!is_valid_content(map, prev, str)))
			return (0);
		++str;
	}
	if (line_count != map->nbr_line)
		return (0);
	return (1);
}
