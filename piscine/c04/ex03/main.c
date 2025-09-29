#include <stdio.h>

int	ft_atoi(char *str);
int	atoi(char *str);

int	main(int argc, char *argv[])
{
	printf("%d", atoi(argv[1]));
	printf("%s", "\n");
	printf("%d", ft_atoi(argv[1]));
	return 0;
}
