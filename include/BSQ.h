/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:59:34 by glodenos          #+#    #+#             */
/*   Updated: 2023/10/25 23:19:53 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define MEMORY_BLOCK_SIZE 1024

typedef struct s_data {
	char		*memory;
	uint32_t	size;
}	t_data;

typedef struct s_map {
	uint32_t	nbr_line;
	uint32_t	max_length;
	char		**map;
	char		char_empty;
	char		char_obstacle;
	char		char_full;
}	t_map;

typedef struct s_square {
	uint32_t	x;
	uint32_t	y;
	uint32_t	size;
}	t_square;

t_data		*dump_all_data_from_fd(int fd);
t_square	*bsq_solver(t_map *map);
void		*ft_memcpy(void *dest, void *src, unsigned int n);
int			is_num(char c);
int			ft_atoi(char *str);
char		*ft_strdup(char *src);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strnchr(char *str, unsigned int n, char c);
char		*ft_strnset(char *str, char c, unsigned int n);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
char		ft_strlen(char *str);
char		*ft_strstr(char *str, char *to_find);
char		**ft_split(char *str, char *charset);
char		*ft_strncat(char *dest, char *src, unsigned int nb);
void		ft_putstr(char *str);
void		ft_putstr_ln(char *str);
char		*ft_strndup(char *src, unsigned int n);
t_map		*parser_stdin(void);
t_map		*parser_file(char *pathname);
void		print_map(t_map *map);
void		map_apply_square(t_map *map, t_square *square);
int32_t		is_valid_map(t_map *map, char *str);
int			ft_str_is_numeric(char *str);
int			ft_str_is_printable(char *str);
char		*load_metadata(t_map *map, char *str);
void		load_map(t_map *map, char *str);
int			ft_is_printable(char c);

#endif
