/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:47:21 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 23:22:29 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

static char	**segment_array(char *str, char *charset, int *len_charset)
{
	char	*prev;
	char	**memory;
	int		nbr_segment;

	nbr_segment = 1;
	*len_charset = 0;
	while (charset[*len_charset])
		++*len_charset;
	if (!*len_charset)
		*len_charset = 1;
	while (*str)
	{
		prev = str;
		str = ft_strstr(str, charset);
		if (str == NULL)
			break ;
		if (str - prev >= *len_charset)
			++nbr_segment;
		str += *len_charset;
	}
	memory = malloc(sizeof(char *) * (nbr_segment + 1));
	memory[nbr_segment] = 0;
	return (memory);
}

static inline char	*segment_dup(char *previous, int length)
{
	char	*tmp;

	if (length == 0)
		while (previous[length])
			++length;
	tmp = malloc(length + 1);
	*tmp = 0;
	return (ft_strncat(tmp, previous, length));
}

char	**ft_split(char *str, char *charset)
{
	char		*prev;
	int			len_charset;
	char		**split;
	char		**head;
	char *const	head_str = str;

	head = segment_array(str, charset, &len_charset);
	split = head;
	while (*str)
	{
		prev = str;
		str = ft_strstr(str, charset);
		if (str == NULL || str == head_str)
		{
			*split = segment_dup(prev, 0);
			break ;
		}
		if (str - prev)
			*split++ = segment_dup(prev, str - prev);
		str += len_charset;
	}
	return (head);
}
