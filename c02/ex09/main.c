#include <unistd.h>

char *ft_strcapitalize(char *str);

void ft_putstr(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
}

int main(int argc, char *argv[])
{
	ft_putstr(ft_strcapitalize(argv[1]));
	return 0;
}
