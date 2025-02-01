int	ft_pow(int num, int power)
{
	
	if (power == 0)
		return (1);
	if (power == 1)
		return (num);
	return (num * ft_pow(num, power - 1));
}
char	decrypt_msg(char *byte)
{
	int	i;
	int	j;
	int	x;
	char	total;
	char	*decrypted_string;
	i = 0;
	x = 0;
	while (byte[i])
	{
		j = 16;
		decrypted_string[x] = 0;
		while(j--)
		{
			if (byte[i] == '1')
				decrypted_string[x] += ft_pow(2, j);
			i++;
		}
		x++;
	}
	decrypted_string[5] = 0;
	printf("%s\n", decrypted_string);
}

int	main()
{
	decrypt_msg("011011000110111");
}