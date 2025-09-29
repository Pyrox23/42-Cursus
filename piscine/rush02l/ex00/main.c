/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:47:23 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/29 18:40:08 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char	**ft_split(char *str, char *charset);
int     translate(char **dict, char *input);

char	*format_number(char *str)
{
	int		digits;
	int		nbr;

	digits = 0;
	nbr = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
		return (NULL);
	else if (*str == '+')
		str++;
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	while (str[digits] <= '9' && str[digits] >= '0')
		digits++;
	if(str[digits] != 0)
		return (NULL);
	return (str);
}

unsigned long long	get_size(int file)
{
	long long		size;
	char				buffer[100];
	int					checking;

	size = 0;
	checking = 1;
	while (checking > 0)
	{
		checking = read(file, buffer, sizeof(buffer));
		size += checking;
	}
	return (size);
}

char	*create_dict(int *file, char *name)
{
	long long		size;
	char				*dict;

	dict = NULL;
	size = get_size(*file);
	close(*file);
	if (size == -1)
	{
		write (2, "Dict Error\n", 11);
		*file = -1;
	}
	else
	{
		*file = open(name, O_RDONLY);
		dict = (char *) malloc(sizeof(char) * size);
		read(*file, dict, size);
		close(*file);
	}
	return (dict);
}

int	main(int ac, char *av[])
{
	char	*name;
	char	*dict;
	int		aux;
	int		input;

	aux = 1;
	if (ac == 2 || ac == 3)
	{
		input = 1;
		name = "numbers.dict";
		if (ac == 3)
			name = av[input++];
		aux = open(name, O_RDONLY);
		if (aux == -1)
			write (2, "Dict Error\n", 11);
		else
		{
			dict = create_dict(&aux, name);
			if (dict)
			{
				aux = translate(ft_split(dict, "\n"), format_number(av[input]));
				free(dict);
			}
		}
	}
	return (aux);
}
