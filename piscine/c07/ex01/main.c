#include <stdio.h>

int     *ft_range(int min, int max);
int	atoi(char *str);

int main(int argc, char *argv[])
{
	int *arr = ft_range(atoi(argv[1]), atoi(argv[2]));
	long size = atoi(argv[2]) - atoi(argv[1]);
	long i = 0;
	while (i < size && arr != NULL)
		printf("%d ", arr[i++]);
	return argc - argc;
}
