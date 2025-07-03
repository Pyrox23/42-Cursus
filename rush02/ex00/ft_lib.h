/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:07:22 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/29 22:43:13 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

int					ft_strlen(char *str);
char				*ft_append(char *m1, char *m2);
char				*find_key(char **dict, char *str);
char				*find_name(char **dict, char *input, char *ans, int depth);
char				*make_number(int depth, char *input);
char				*last_resort(char **dict, char *input, char *ans);
char				*fill(char *res, char *m1, char *m2);
char				*ft_append(char *m1, char *m2);
int					ft_strcmp(char *s1, char *s2);
int					is_splitter(char c, char *charset);
void				format_word(char **arr, char *str, char *set,
						unsigned long long len);
unsigned long long	alloc_word(char **arr, char *str, char *set);
char				**ft_split(char *str, char *charset);
int					translate(char **dict, char *input);
char				*format_number(char *str);
unsigned long long	get_size(int file);
char				*create_dict(int *file, char *name);
void				ft_init(char *dict, int *aux, char **av, int input);
void				free_memory(char **memory);
void				print_name_nb(char *name);
char				*case_long(char **dict, char *input, char *ans,
						char *length);
char				*case_short(char **dict, char *input, char *ans);
char				*allocate_length(char *input, int digits, int size);
char				*find_name_v2(char **dict, int *depth, char *ans,
						char **input);
#endif
