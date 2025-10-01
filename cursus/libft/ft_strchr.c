/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:31:40 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/09/30 15:31:40 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	char				*occ;
	unsigned long long	i;

	occ = (void *) 0; //Puede que esto no se detecte como NULL
	i = 0;
	while (!occ && s[i])
	{
		if (s[i] == c)
			occ = s[i];
		i++;
	}
	return (occ);
}
