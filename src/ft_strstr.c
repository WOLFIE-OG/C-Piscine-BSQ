/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:46:39 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 18:46:45 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	index;

	while (*str)
	{
		index = 0;
		while (str[index] == to_find[index])
			if (!to_find[++index])
				return (str);
		++str;
	}
	return (NULL);
}
