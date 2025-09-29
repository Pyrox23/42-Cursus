int     ft_atoi_base(char *str, char *base);
void	ft_putnbr(int nbr);

int main(int argc, char *argv[])
{
	ft_putnbr(ft_atoi_base(argv[1], argv[2]));
	return (0);
}
