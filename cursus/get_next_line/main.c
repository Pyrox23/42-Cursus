#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	//int		i = 1;
	int		stop;

	fd = open("test1.txt", O_RDONLY);
	stop = 0;
	while (!stop)
	{
		line = get_next_line(fd);
		if (!line)
		{
			stop = 1;
			//printf("linea %d: EOF\n", i++);
			printf("EOF\n");
		}
		else
		{
			//printf("linea %d: %s", i++, line);
			printf("%s", line);
			free(line);
		}
	}
	close(fd);
	return (0);
}
