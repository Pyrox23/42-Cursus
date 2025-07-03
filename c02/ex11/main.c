void ft_putstr_non_printable(char *str);

int main(int argc, char *argv[])
{
	char	str[] = "Hola\nbuenos\x80\tprobançing.";
	ft_putstr_non_printable(str);
	return 0;
}
