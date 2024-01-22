/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:45:13 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 22:52:38 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int	ft_bsq(t_map *map)
{
	t_square	*square;

	if (!map)
	{
		ft_putstr_ln("map error");
		return (0);
	}
	square = bsq_solver(map);
	map_apply_square(map, square);
	print_map(map);
	return (0);
}

int	main(int argc, char **argv)
{
	int	println;

	println = 0;
	if (argc == 1)
		return (ft_bsq(parser_stdin()));
	while (--argc)
	{
		if (println)
			ft_putstr("\n");
		ft_bsq(parser_file(*++argv));
		println = 1;
	}
	return (0);
}
