#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

int ft_isascii(int c);
int	ft_isalnum(int c);
int ft_isprint(int c);
size_t  ft_strlen(const char *s);

/*int	main()
{
	int c = 0;
	while(c < 127)
	{
		printf("%c: %d, %d\n", c, isalnum(c), ft_isalnum(c));
		c++;
	}
	printf("EOF: %d, %d\n", isalnum(-1), ft_isalnum(-1));
	return (0);
}*/

/*int	main()
{
	int c = 0;
	while(c <= 127)
	{
		printf("%c: %d, %d\n", c, isascii(c), ft_isascii(c));
		c++;
	}
	printf("EOF: %d, %d\n", isascii(-1), ft_isascii(-1));
	return (0);
}*/

/*int	main()
{
	int c = 0;
	while(c <= 127)
	{
		printf("%c: %d, %d\n", c, isprint(c), ft_isprint(c));
		c++;
	}
	printf("EOF: %d, %d\n", isprint(-1), ft_isprint(-1));
	return (0);
}*/

int main(int ac, char **av)
{
    if (ac > 1)
        printf("%s\n%ld, %ld\n", av[1], strlen(av[1]), ft_strlen(av[1]));
    return (0);
}