/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:00:10 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 22:00:13 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

char	*ft_strdup(char *src)
{
	char *const	memory = malloc(ft_strlen(src) + 1);

	if (!memory)
		return (NULL);
	return (ft_strcpy(memory, src));
}
