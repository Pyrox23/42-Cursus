/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:55:26 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/17 14:16:02 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int		comp;

	comp = 0;
	while (comp == 0 && *s1 != 0 && *s2 != 0 && n > 0)
	{
		comp = *s1 - *s2;
		s1++;
		s2++;
		n--;
	}
	if (comp == 0 && n > 0)
		comp = *s1 - *s2;
	return (comp);
}
