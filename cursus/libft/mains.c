#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

/*int	main(int argc, char **argv)
{
	char	c;

	c = 32;
	while (c <= 126)
	{
		printf("%c: %d, %d\n", c, ft_isalpha(c), isalpha(c));
		c++;
	}
	return (0);
}*/

/*int	main(int argc, char **argv)
{
	char	c;

	c = 32;
	while (c <= 126)
	{
		printf("%c: %d, %d\n", c, ft_isalpha(c), isalpha(c));
		c++;
	}
	return (0);
}*/

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

/*int main(int ac, char **av)
{
    if (ac > 1)
        printf("%s\n%ld, %ld\n", av[1], strlen(av[1]), ft_strlen(av[1]));
    return (0);
}*/

/*int main(int ac, char **av)
{
	char	list[20];
	int	i;

	i = 0;
	while (i < 18)
	{
		list[i] = 'a';
		printf("%d\n", list[i++]);
	}
	list[18] = 0;
	list[19] = 0;
	printf("list, size %ld\n", sizeof(list));
	ft_memset(list, 254, sizeof(list));
	i = 0;
	while (i < 20)
		printf("%d\n", list[i++]);
    return (0);
}//Prueba si memset mira caracteres nulos para detenerse*/


/*int	main(int ac, char **av)
{
	int	nbr;

	if (ac > 1)
	{
		nbr = ft_atoi(av[1]);
		printf("input: %d, output: %s\n", nbr, ft_itoa(nbr));
	}
	else
		printf("input: %d, output: %s\n", 15195151951, ft_itoa(15195151951));
	return (0);
}*/
