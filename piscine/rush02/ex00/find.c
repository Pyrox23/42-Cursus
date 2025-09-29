/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:58:48 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/29 22:42:51 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lib.h"

char	*case_long(char **dict, char *input, char *ans, char *length)
{
	char	*nbr;
	int		digits;
	int		i;

	i = -1;
	length = NULL;
	if (ft_strlen(input) % 3 != 0)
		digits = ft_strlen(input) % 3;
	else
		digits = 3;
	nbr = (char *) malloc(sizeof(char) * digits + 1);
	while (++i < digits)
		nbr[i] = input[i];
	nbr[i] = 0;
	length = allocate_length(input, digits, ft_strlen(input));
	ans = find_name(dict, nbr, ans, 0);
	free(nbr);
	if (ans && find_key(dict, length))
	{
		ans = ft_append(ans, find_key(dict, length));
		free(length);
		return (ans);
	}
	free(length);
	return (NULL);
}

char	*case_short(char **dict, char *input, char *ans)
{
	char	*nbr;
	char	*length;

	length = NULL;
	nbr = (char *) malloc(sizeof(char) * 2);
	nbr[0] = input[0];
	nbr[1] = 0;
	length = allocate_length(input, 1, ft_strlen(input));
	if (find_key(dict, nbr) && find_key(dict, length))
	{
		ans = ft_append(ans, find_key(dict, nbr));
		ans = ft_append(ans, find_key(dict, length));
		free(length);
		free(nbr);
		return (ans);
	}
	free(length);
	free(nbr);
	return (NULL);
}

char	*last_resort(char **dict, char *input, char *ans)
{
	if (ft_strlen(input) > 4)
		return (case_long(dict, input, ans, NULL));
	else
		return (case_short(dict, input, ans));
}

char	*find_name_v2(char **dict, int *depth, char *ans, char **input)
{
	char	*interpret;

	interpret = make_number(*depth, *input);
	if (find_key(dict, interpret))
	{
		if (*interpret == '1' && ft_strlen(*input) > 2)
			ans = ft_append(ans, find_key(dict, "1"));
		if (*interpret != '0')
			ans = ft_append(ans, find_key(dict, interpret));
		else if (*ans == 0)
			ans = ft_append(ans, find_key(dict, interpret));
		*input += ft_strlen(*input) - *depth;
		*depth = 0;
	}
	else
		*depth = *depth + 1;
	if (*(*input + 1) && **input == '0' && *depth == ft_strlen(*input))
	{
		*depth = 0;
		*input = *input + 1;
	}
	free(interpret);
	return (ans);
}

char	*find_name(char **dict, char *in, char *ans, int depth)
{
	char		*interpret;

	depth = 0;
	while (depth < ft_strlen(in) && ans)
	{
		interpret = make_number(depth, in);
		if (ft_strlen(in) > 2 && depth == ft_strlen(in) - 1 && *in != '0')
		{
			ans = last_resort(dict, in, ans);
			if (ft_strlen(in) > 4)
			{
				if (ft_strlen(in) % 3 != 0)
					in += ft_strlen(in) % 3;
				else
					in += 3;
			}
			else
				in++;
			depth = 0;
		}
		else
			ans = find_name_v2(dict, &depth, ans, &in);
		free(interpret);
	}
	return (ans);
}
