#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main(int argc, char *argv[])
{
	char		*str;

	argc--;
	str = ft_strjoin(argc, argv, NULL);
	printf("%s", str);
	free(str);
	return 0;
}
