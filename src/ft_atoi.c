/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:41:17 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 18:41:18 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	value;
	int	negative;

	value = 0;
	negative = 1;
	while (*str == 0x20 || (*str > 0x08 && *str < 0x0E))
		++str;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			negative *= -1;
	while (*str > 0x2F && *str < 0x3A)
		value = value * 10 + *str++ - 0x30;
	return (value * negative);
}
