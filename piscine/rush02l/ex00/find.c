/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:58:48 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/29 20:20:26 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_strlen(char *str);
char    *ft_append(char *m1, char *m2);
char    *find_key(char **dict, char *str);
char    *find_name(char **dict, char *input, char *ans);

char	*make_number(int depth, char *input)
{
	char		*nbr;
	int			size;
	int			i;

	i = 0;
	size = ft_strlen(input);
	nbr = (char *) malloc(sizeof(char) * size + 1);
	while (i < size)
	{
		nbr[i] = input[i];
		i++;
	}
	nbr[i] = 0;
	i = 0;
	while (i < depth)
		nbr[size - 1 - i++] = '0';
	return (nbr);
}

char	*last_resort(char **dict, char *input, char *ans)
{
	char		*nbr;
	char		*length;
	int			digits;
	int			size;
	int			i;

	if (ft_strlen(input) > 4)
	{
		i = -1;
		if (ft_strlen(input) % 3 != 0)
			digits = ft_strlen(input) % 3;
		else
			digits = 3;
		nbr = (char *) malloc(sizeof(char) * digits + 1);
		while (++i < digits)
			nbr[i] = input[i];
		nbr[i] = 0;
		input = input + digits - 1;
		size = ft_strlen(input);
                length = (char *) malloc(sizeof(char) * size + 1);
                length[0] = '1';
		i = 1;
                while (i < size)
                        length[i++] = '0';
                length[i] = 0;
		ans = find_name(dict, nbr, ans);
		if(ans && find_key(dict, length))
		{
			ans = ft_append(ans, find_key(dict, length));
			free(length);
			return (ans);
		}
	}
	else
	{
		nbr = (char *) malloc(sizeof(char) * 2);
		nbr[0] = input[0];
		nbr[1] = 0;
		i = 1;
		size = ft_strlen(input);
		length = (char *) malloc(sizeof(char) * size + 1);
		length[0] = '1';
		while (i < size)
			length[i++] = '0';
		length[i] = 0;
		if(find_key(dict, nbr) && find_key(dict, length))
		{
			ans = ft_append(ans, find_key(dict, nbr));
			ans = ft_append(ans, find_key(dict, length));
			free(length);
			return (ans);
		}
	}
	return (NULL);
}

char	*find_name(char **dict, char *input, char *ans)
{
	char		*interpret;
	int		depth;

	depth = 0;
	while (depth < ft_strlen(input) && ans)
	{
		interpret = make_number(depth, input);
		if (ft_strlen(input) > 2 && depth == ft_strlen(input) - 1 && *input != '0')
		{
			ans = last_resort(dict, input, ans);
			if (ft_strlen(input) > 4)
			{
				if (ft_strlen(input) % 3 != 0)
					input += ft_strlen(input) % 3;
				else
					input += 3;
			}
			else
				input++;
			depth = 0;
		}
		else if (find_key(dict, interpret))
		{
			if (*interpret == '1' && ft_strlen(input) > 2)
				ans = ft_append(ans, find_key(dict, "1"));
			if (*interpret != '0')
				ans = ft_append(ans, find_key(dict, interpret));
			else if (*ans == 0)
				ans = ft_append(ans, find_key(dict, interpret));
			input += ft_strlen(input) - depth;
			depth = 0;
		}
		else
			depth++;
		if (*(input + 1) && *input == '0' && depth == ft_strlen(input))
		{
			depth = 0;
			input++;
		}
		free(interpret);
	}
	return (ans);
}
