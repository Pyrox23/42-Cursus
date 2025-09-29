/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:57:39 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/20 13:09:06 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_inputs(char **list, int count)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < count)
	{
		while (list[i][j] != 0)
			write(1, &list[i][j++], 1);
		write(1, "\n", 1);
		i++;
		j = 0;
	}
	return ;
}

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

void	swap(char **list, int s1, int s2)
{
	char		*aux;

	aux = list[s1];
	list[s1] = list[s2];
	list[s2] = aux;
	return ;
}

int	main(int argc, char *argv[])
{
	int		i;
	int		ordered;

	i = 1;
	if (argc <= 2)
		ordered = 1;
	else
		ordered = 0;
	while (!ordered)
	{
		ordered = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				swap(argv, i, i + 1);
				ordered = 0;
			}
			i++;
		}
		i = 1;
	}
	print_inputs(argv, argc);
	return (0);
}
