/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:11:26 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/18 19:06:54 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

int	check_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		convert;

	i = 0;
	convert = 'a' - 'A';
	while (check_letter(str[i]) == 1)
		i++;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - convert;
	i++;
	while (str[i] != 0)
	{
		if (check_letter(str[i]) != 0)
		{
			i++;
			while (check_letter(str[i]) == 1)
				i++;
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - convert;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + convert;
		i++;
	}
	return (str);
}
