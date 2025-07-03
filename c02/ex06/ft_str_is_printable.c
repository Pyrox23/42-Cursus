/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:13:43 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/16 19:03:53 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0 && str[i] >= 32 && str[i] <= 126)
		i++;
	if (str[i] == 0)
		return (1);
	else
		return (0);
}
