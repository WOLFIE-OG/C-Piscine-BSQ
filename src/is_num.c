/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:46:57 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 18:47:04 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BSQ.h>

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}
