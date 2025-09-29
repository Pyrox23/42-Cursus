/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:46:50 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/26 17:06:12 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		found;

	found = 0;
	if (*to_find == 0)
		return (str);
	i = 0;
	while (found == 0 && str[i] != 0)
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != 0)
			j++;
		if (to_find[j] == 0)
			found = 1;
		else
			i++;
	}
	if (found == 1)
		return (str + i);
	return (0);
}
