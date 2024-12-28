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

char	*decrypt_msg(char *bits_str)
{
	
}

int	main()
{
	char	*enc_msg;
	enc_msg = enc_str("hello");
	printf("%s", enc_msg);
}
