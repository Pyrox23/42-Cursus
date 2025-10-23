#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int retft, ret;

	retft = ft_printf("%d, %d\n", -500, 500);
	ret = printf("%d, %d\n", -500, 500);
	printf("\nmine= %d\noriginal= %d\n", retft, ret);
	retft = ft_printf("%r");
	ret = printf("%r");
	printf("\nmine= %d\noriginal= %d\n", retft, ret);
	retft = ft_printf("%");
	ret = printf("%");
	printf("\nmine= %d\noriginal= %d\n", retft, ret);
	return (0);
}
