#include "ft_printf.h"
#include <stdio.h>


// TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
// 32:     TEST(8, print(" %p %p ", 18446744073709551615ULL, -18446744073709551615ULL);
// 33:     TEST(9, print(" %p %p ", 0, 0));
int	main(void)
{
	unsigned int retft, ret;

	// retft = ft_printf(" %p %p ", 18446744073709551615ULL, -18446744073709551615ULL);
	// ret = printf(" %p %p ", 18446744073709551615ULL, -18446744073709551615ULL);
	retft = ft_printf("%r");
	ret = printf("%r");
	printf("\nmine= %u\noriginal= %u\n", retft, ret);
	return (0);
}
