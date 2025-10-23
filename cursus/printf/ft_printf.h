/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:01:14 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/23 23:21:04 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# define BASE_10 "0123456789"

int		ft_printf(char const *fmt, ...);
int		ft_ultoa_base(size_t nbr, char *base);
int		check_case(va_list ap, char flag, size_t *bw);
size_t	case_p(size_t ptr);
size_t	case_s(char *s);
size_t	case_c(char c);
size_t	ft_strlen(const char *s);
int		print_nbr(int n);

#endif