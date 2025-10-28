/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:26:41 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/29 00:05:12 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define I_MIN "2147483648"
# define I_MAX "2147483647"
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
//# include "ft_printf.h"
//# include "libft.h"

void	sort_stack(int *s_in, int *s_tmp, int size);
int		*check_input(char **ls, int size);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
void	stop_program(int *s_in, int *s_tmp, int ext_val);

#endif