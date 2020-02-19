#include <stdio.h>
#include <stdlib.h>

int		ft_len(int value, int base)
{
	int c;

	c = 1;
	if (value < 0)
	{
		value = value * -1;
		c++;
	}
	while (value >= base)
	{
		value = value / base;
		c++;
	}
	return (c);
}

char	*ft_itoa_base(int value, int base)
{
	char *str = NULL;
	int c;

	c = 0;
	if (base != 10)
	{
		int len;

		len = ft_len(value, base);
		if (!(str =(char*)malloc(sizeof(char) * (len + 1))))
			return (0);
		str[len] = '\0';
		len--;
		while (len >= 0)
		{
			str[len] = ((value % base) > 9 ? 'A' + ((value % base) - 10) : '0' + (value % base));
			value = value / base;
			len--;
		}
	}
	if (base == 10)
	{
		int len;
		int sign;

		sign = 0;
		len = ft_len(value, base);
		if (value == (-2147483648))
		{
			if (!(str =(char*)malloc(sizeof(char) * (12))))
				return (0);
			str[0] = '-';
			str[1] = '2';
			str[2] = '1';
			str[3] = '4';
			str[4] = '7';
			str[5] = '4';
			str[6] = '8';
			str[7] = '3';
			str[8] = '6';
			str[9] = '4';
			str[10] = '8';
			return (str);
		}
		if (value < 0)
		{
			value = value * -1;
			sign++;
		}
		if (!(str =(char*)malloc(sizeof(char) * (len + 1))))
			return (0);
		str[len] = '\0';
		len--;
		while (len >= 0)
		{
			str[len] = '0' + (value % base);
			value = value / base;
			len--;
		}
		if (sign != 0)
			str[0] = '-';
	}
	return (str);
}

int		main(int ac, char **av)
{
	int value;
	int base;
	char *str;

	if (ac != 3)
	{
		printf("bad usage");
		return (0);
	}
	value = atoi(av[1]);
	base = atoi(av[2]);
	str = ft_itoa_base(value, base);
	printf("||%s|| \n", str);
	return (0);
}
