#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	char	*line;
	int		*fd;
	int		stop;
	int		i;

	fd = malloc(ac * sizeof(int));
	if (!fd)
	{
		printf("malloc failed in main\n");
		return (1);
	}
	i = 0;
	if (ac > 1)
	{
		while (i < ac)
		{
			fd[i] = open(av[i + 1], O_RDONLY);
			i++;
		}
	}
	else
		*fd = open("test.txt", O_RDONLY);
	stop = 0;
	while (stop != ac - 1)
	{
		i = 0;
		while (i < ac)
		{
			if (fd[i] >= 0)
			{
				line = get_next_line(fd[i]);
				if (!line)
				{
					stop += 1;
					if (ac > 1)
						printf("From file %d: ", fd[i]);
					printf("EOF\n");
					close(fd[i]);
					fd[i] = -1;
				}
				else
				{
					if (ac > 1)
						printf("From file %d: ", fd[i]);
					printf("%s", line);
					free(line);
				}
			}
			i++;
		}
	}
	free(fd);
	return (0);
}
