#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	if (atoi(av[1]) == ft_atoi(av[1]))
		write(1, "OK!\n", 4);
	else
		write(1, "KO!\n", 4);
	return (0);
}
