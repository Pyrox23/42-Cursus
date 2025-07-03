/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:16:35 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/16 16:19:30 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0 && str[i] <= '9' && str[i] >= '0')
		i++;
	if (str[i] == 0)
		return (1);
	else
		return (0);
}
