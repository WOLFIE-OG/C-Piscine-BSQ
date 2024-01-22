/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:40:52 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 22:55:35 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int32_t	populate_data(t_map *map, char *buffer)
{
	char	*head;

	head = load_metadata(map, buffer);
	if (!head || !is_valid_map(map, head))
		return (0);
	load_map(map, head);
	return (1);
}

t_map	*parser_stdin(void)
{
	t_map	*map;
	t_data	*data;

	map = malloc(sizeof(t_map));
	data = dump_all_data_from_fd(0);
	if (!populate_data(map, data->memory))
	{
		free(data->memory);
		free(data);
		return (NULL);
	}
	free(data->memory);
	free(data);
	return (map);
}

t_map	*parser_file(char *pathname)
{
	int		fd;
	t_map	*map;
	t_data	*data;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		return (NULL);
	}
	data = dump_all_data_from_fd(fd);
	if (!populate_data(map, data->memory))
	{
		free(data->memory);
		free(data);
		return (NULL);
	}
	free(data->memory);
	free(data);
	close(fd);
	return (map);
}
