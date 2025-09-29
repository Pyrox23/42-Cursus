/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:24:17 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/16 16:26:09 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0 && str[i] >= 'a' && str[i] <= 'z')
		i++;
	if (str[i] == 0)
		return (1);
	else
		return (0);
}
