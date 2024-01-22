/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_all_data_from_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:38:46 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 22:37:03 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

t_data	*dump_all_data_from_fd(int fd)
{
	char		buffer[MEMORY_BLOCK_SIZE];
	uint32_t	len_memory;
	uint32_t	readen;
	char		*tmp;
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->size = 0;
	while (1)
	{
		readen = read(fd, buffer, MEMORY_BLOCK_SIZE);
		if (!readen)
			break ;
		len_memory = data->size;
		data->size += readen;
		tmp = data->memory;
		data->memory = malloc(data->size);
		ft_memcpy(data->memory, tmp, len_memory);
		ft_memcpy(data->memory + len_memory, buffer, readen);
	}
	return (data);
}
