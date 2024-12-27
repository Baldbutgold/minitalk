#include "../minitalk.h"

char	*ft_print_bits(unsigned char octet)
{
	int	i;
	char	*str_bits;

	str_bits = malloc(9);
	i = 8;
	while (i--)
		str_bits[i] = (octet >> i & 1) + '0';
	str_bits[8] = 0;
	return (str_bits);
}

int	main()
{
	char	*message;
	char	*encrypted_message;
	int	i;

	i = 0;
	message = "hello";
	encrypted_message = malloc(5 * 8 + 1);
	while(message[i])
	{
		printf("%s\n", ft_print_bits(message[i]));
		i++;
	}
	encrypted_message[5 * 8] = 0;
}
