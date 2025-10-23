/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:01:14 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/12 19:47:10 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

typedef unsigned long long	t_ull;
typedef unsigned int		t_ui;

int		ft_printf(char const *fmt, ...);
char	*ft_ultoa_base(t_ull nbr, char *base);
int		check_case(va_list ap, char flag, size_t *bw);
size_t	case_c(char c);

#endif