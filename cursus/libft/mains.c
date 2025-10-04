#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <strings.h>
#include "libft.h"

/*int	main(void)
{
	int c = 0;
	while (c < 127)
	{
		printf("%c: %d, %d\n", c, ft_isalpha(c), isalpha(c));
		c++;
	}
	return (0);
}*/

/*int	main(void)
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

/*int	main(void)
{
	int c = 0;
	while(c < 127)
	{
		printf("%c: %d, %d\n", c, isdigit(c), ft_isdigit(c));
		c++;
	}
	printf("EOF: %d, %d\n", isdigit(-1), ft_isdigit(-1));
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
    	printf("%s\n%ld, %ld\n", av[1], strlen(NULL), ft_strlen(NULL));
    return (0);
}*/

/*void	prueba(void *(*f)(void *, int, size_t))
{
	int		list[30];
	int		*test;
	int	i;

	i = 0;
	printf("original:\n");
	while (i < 30)
	{
		list[i] = 156;
		printf("%d\n", list[i++]);
	}
	printf("list, size %ld\n", sizeof(list));
	test = f(NULL, -26, sizeof(list));
	i = -1;
	printf("resultado:\n");
	while (++i < 30)
		printf("i%d: %d\n", i, list[i]);
}

int main(void)
{
	prueba(memset);
	prueba(ft_memset);
    return (0);
}*/

/*void	prueba(void (*f)(void *, size_t))
{
	char	list[30];
	int	i;

	i = 0;
	printf("original:\n");
	while (i < 30)
	{
		list[i] = 96;
		printf("%d\n", list[i++]);
	}
	printf("list, size %ld\n", sizeof(list));
	f(list, sizeof(list));
	i = -1;
	printf("resultado:\n");
	while (++i < 30)
		printf("i%d: %d\n", i, list[i]);
}

int main(void)
{
	prueba(bzero);
	prueba(ft_bzero);
    return (0);
}*/

/*void	prueba(void *(*f)(void *, const void *, size_t))
{
	int	list[30];
	int	*test;
	int	i;

	i = 0;
	printf("original:\n");
	while (i < 30)
	{
		list[i] = i;
		printf("%d\n", list[i++]);
	}
	printf("list, size %ld\n", sizeof(list));
	test = f(list, list + 5, 40);
	i = -1;
	printf("resultado:\n");
	while (++i < 25)
		printf("i%d: %d\n", i, test[i]);
}

int main(void)
{
	prueba(memmove); //Memmove y memcpy son intercambiables
	prueba(ft_memmove);//Memcpy fue mejorado para funcionar como memmove en algunas plataformas
    return (0);
}*/

/*void	prueba(const char *str, int (*f)(int))
{
	size_t	i;
	char	*test;

	i = 0;
	printf("input: %s\n", str);
	test = (char *) ft_calloc(ft_strlen(str), sizeof(char));
	if (!test)
		return ;
	while (str[i])
	{
		test[i] = f(str[i]);
		i++;
	}
	printf("resultado: %s\n", test);
	free(test);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	prueba(av[1], toupper);
	prueba(av[1], ft_toupper);
	prueba(av[1], tolower);
	prueba(av[1], ft_tolower);
	return (0);
}*/

/*void	prueba(const char *str, int c, char *(*f)(const char *, int))
{
	char	*test;

	printf("input: %s\n", str);
	test = f(str, c);
	printf("resultado: ");
	if (!test)
		printf("not found\n");
	else
		printf("direccion=%ld, str=%s\n", (size_t) test, test);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	prueba(av[1], av[2][0], strchr);
	prueba(av[1], av[2][0], ft_strchr);
	prueba(av[1], av[2][0], strrchr);
	prueba(av[1], av[2][0], ft_strrchr);
	return (0);
}*/

/*void	prueba(const char *str1, const char *str2, size_t len, int (*f)(const char *, const char *, size_t))
{
	int	test;

	printf("input:\nin1: %s\nin2: %s\nn = %ld\n", str1, str2, len);
	test = f(".", ".", len);
	printf("resultado: %d\n", test);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	prueba(av[1], av[2], ft_strlen(av[1]), strncmp);
	prueba(av[1], av[2], ft_strlen(av[1]), ft_strncmp);
	return (0);
}*/

/*void	prueba(void *str, int c, void *(*f)(const void *, int, size_t))
{
	int	*test;

	//printf("input: %s\n", (char *) str);
	test = (int *) f(str, c, 20 * 4); // *4 si es int, desde el primer bit de 4 mide el valor de int
	printf("resultado: ");
	if (!test)
		printf("not found\n");
	else
		printf("direccion=%ld, ans=%d\n", (size_t) test, *test);
}

int	main(void)
{
	int	lst[20];
	int	c;
	int	i;

	i = -1;
	c = 19;
	while (++i < 20)
	{
		lst[i] = i;
		printf("i%d: %d\n", i, lst[i]);
	}
	prueba(lst, c, memchr);
	prueba(lst, c, ft_memchr);
	return (0);
}*/

/*void	prueba(const void *ls1, const void *ls2, size_t len, int (*f)(const void *, const void *, size_t))
{
	int	test;

	test = f(ls1, ls2, len);
	printf("resultado: %d\n", test);
}

int main(void)
{
	int	ls1[20];
	int	ls2[50];
	int	i;

	i = -1;
	while (++i < 20)
	{
		ls1[i] = i;
		printf("ls1 > i%d: %d\n", i, ls1[i]);
	}
	i = -1;
	while (++i < 50)
	{
		ls2[i] = i;
		printf("ls2 > i%d: %d\n", i, ls2[i]);
	}
	//printf("input:\nin1: %s\nin2: %s\nn = %d\n", av[1], av[2], 20);
	prueba(ls1, ls2, 30 * 4, memcmp);
	prueba(ls1, ls2, 30 * 4, ft_memcmp);
	return (0);
}*/

/*void	prueba(const char *big, const char *little, size_t len, char *(*f)(const char *, const char *, size_t))
{
	char	*test;

	test = f(big, little, len);
	printf("resultado: %s\n", test);
	test = strstr(big, little);
	printf("resultado: %s\n", test);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	prueba(av[1], av[2], 20, ft_strnstr);
	return (0);
}*/

/*void	prueba(const char *av, int (*f)(const char *))
{
	int	test;

	test = f(av);
	printf("input: %s, atoi: %d, itoa: %s\n", av, test, ft_itoa(test));
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	prueba(av[1], atoi);
	prueba(av[1], ft_atoi);
	return (0);
}*/

/*void	prueba(const char *src, size_t (*f)(char *, const char *, size_t))
{
	char	*test;
	size_t	len;

	test = NULL;
	len = f(test, src, 0);
	printf("src len: %ld (add 1 for calloc)\n", len);
	test = ft_calloc(len + 1, sizeof(char));
	if (!test)
	{
		printf("mem failure\n");
		return ;
	}
	len = f(test, src, len + 1);
	printf("src: %s\ndest: %s\n", src, test);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	prueba(av[1], ft_strlcpy);
	return (0);
}*/

/*void	prueba(const char *src, size_t (*f)(char *, const char *, size_t))
{
	char	*test;
	char	*dest;
	size_t	len;

	test = "hola que tal";
	len = f(test, src, ft_strlen(test));
	printf("result of lcat len: %ld (add 1 for calloc)\n", len);
	len++;
	dest = ft_calloc(len, sizeof(char));
	if (!dest)
	{
		printf("mem failure\n");
		return ;
	}
	ft_strlcpy(dest, test, len);
	len = f(dest, src, len);
	printf("src: %s\ndest: %s\n", src, dest);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	prueba(av[1], ft_strlcat);
	return (0);
}*/


/*void	prueba(size_t nmemb, size_t size, void *(*f)(size_t, size_t))
{
	char	*test;
	size_t	i;

	i = 0;
	printf("inputs: %ld, %ld\n", nmemb, size);
	test = f(nmemb, size);
	if (!test)
	{
		printf("failed\n");
		return ;
	}
	while (i < nmemb * size)
	{
		printf("i%ld: %d\n", i, test[i]);
		i++;
	}
	free(test);
	printf("free successful\n");
}

int	main(void)
{
	prueba(0, 0, calloc);
	prueba(0, 0, ft_calloc);
	prueba(__SIZE_MAX__, 2, calloc);
	prueba(__SIZE_MAX__, 2, ft_calloc);
	prueba(__SIZE_MAX__ / 2, 1, calloc);
	prueba(__SIZE_MAX__ / 2, 1, ft_calloc);
	prueba(40, 4, calloc);
	prueba(40, 4, ft_calloc);
	return (0);
}*/

/*void	prueba(const char *src, char *(*f)(const char *))
{
	char	*test;

	printf("input: %s\n", src);
	test = f(src);
	printf("output: %s\n", test);
	if (test)
	{
		free(test);
		printf("free successful\n");
	}
	else
		printf("mem failure\n");
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	prueba(av[1], ft_strdup);
	return (0);
}*/
