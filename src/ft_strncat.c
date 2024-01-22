/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:50:37 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 18:50:40 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *const	head = dest;

	while (*dest)
		++dest;
	while (*src && nb--)
		*dest++ = *src++;
	*dest = 0;
	return (head);
}
