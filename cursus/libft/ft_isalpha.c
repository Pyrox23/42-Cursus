/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:47:21 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/09/29 11:47:41 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c);

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}

/*int	main(int argc, char **argv)
{
	char	c;

	c = 32;
	while (c <= 126)
	{
		printf("%c: %d, %d\n", c, ft_isalpha(c), isalpha(c));
		c++;
	}
	return (0);
}*/
