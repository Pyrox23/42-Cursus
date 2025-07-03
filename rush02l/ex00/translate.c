/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:01:19 by pablomar          #+#    #+#             */
/*   Updated: 2025/06/29 18:06:33 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char    *find_name(char **dict, char *input, char *ans);

void	free_memory(char **memory)
{
	int	pos;

	pos = 0;
	while (memory[pos] != NULL)
		free(memory[pos++]);
	free(memory);
}

void	print_name_nb(char *name)
{
	while (*name != '\0')
	{
		write(1, name, 1);
		name++;
	}
	write(1, "\n", 1);
}

int	translate(char **dict, char *input)
{
	int		exit;
	char	*name_nb;

	exit = 0;
	name_nb = (char *) malloc(sizeof(char));
	name_nb[0] = 0;
	if (input == NULL)
	{
		write(2, "Error\n", 6);
		exit = 1;
	}
	else
	{
		name_nb = find_name(dict, input, name_nb);
		if (name_nb == NULL)
		{
			write(2, "Dict Error\n", 12);
			exit = 1;
		}
		else
			print_name_nb(name_nb);
	}
	free_memory(dict);
	return (exit);
}
