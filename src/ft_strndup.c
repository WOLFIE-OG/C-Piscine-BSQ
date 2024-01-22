/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:44:41 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 20:59:49 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

char	*ft_strndup(char *src, unsigned int n)
{
	char *const	memory = malloc(n + 1);

	if (!memory)
		return (NULL);
	memory[n] = 0;
	ft_strncpy(memory, src, n);
	return (memory);
}
