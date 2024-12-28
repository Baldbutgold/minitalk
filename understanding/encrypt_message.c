#include "../minitalk.h"

char	*enc_str(char* message)
{
	int	i;
	int	j;
	int	x;
	char	*string_bits;

	j = 0;
	x = 0;
	string_bits = malloc(5 * 8 + 1);
	if (!string_bits)
		return (NULL);
	while (message[x])	
	{
		i = 8;
		while (i--)
			string_bits[j++] = (message[x] >> i & 1) + '0';
		x++;
	}
	string_bits[j] = 0;
	return (string_bits);
}

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
		j = 8;
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
	char	*enc_msg;
	enc_msg = enc_str("hello");
	decrypt_msg(enc_msg); // should be transformed to h
}
