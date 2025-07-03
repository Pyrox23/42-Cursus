/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:40:50 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/17 14:11:17 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int		comp;

	comp = 0;
	while (comp == 0 && *s1 != 0 && *s2 != 0)
	{
		comp = *s1 - *s2;
		s1++;
		s2++;
	}
	if (comp == 0)
		comp = *s1 - *s2;
	return (comp);
}
