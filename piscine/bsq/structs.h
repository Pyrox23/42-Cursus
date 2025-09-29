/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:05:01 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/07/02 16:37:15 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define TRUE 1
# define FALSE 0

typedef struct s_square
{
	int	x;
	int	y;
	int	side;
}	t_square;

typedef struct s_map
{
	int					width;
	int					height;
	char				empty;
	char				fill;
	char				obs;
	char				**mtx;
}	t_map;

void				find_obs(t_map *map_ptr);
char				**ft_split(char *str, char *set);
int					solve(t_map *map_ptr);
unsigned long		get_nbr(char *map, unsigned long digit);
int					check_map(char *map);
int					process_file(char *argv, char **buff);
unsigned long long	get_size(int file);
int					check_map(char *map);
char				*open_standard(void);
void				try_map_input(char *buff, char *name);
void				print_mtx(struct s_map *obj);
struct s_map		struct_obj(char **mtx);
void				free_struct(struct s_map *map_ptr);
#endif
