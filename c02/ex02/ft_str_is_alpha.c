/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:19:13 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/15 19:35:39 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str);

int	check_char(char *str, int i)
{
	if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		return (0);
	return (1);
}

int	ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0 && check_char(str, i) == 0)
		i++;
	if (str[i] == 0)
		return (1);
	else
		return (0);
}
