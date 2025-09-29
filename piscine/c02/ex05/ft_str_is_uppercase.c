/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:28:10 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/16 16:30:21 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0 && str[i] >= 'A' && str[i] <= 'Z')
		i++;
	if (str[i] == 0)
		return (1);
	else
		return (0);
}
