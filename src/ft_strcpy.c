/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:07:32 by otodd             #+#    #+#             */
/*   Updated: 2023/10/25 18:41:41 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (ft_strlen(dest) != ft_strlen(src))
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}
