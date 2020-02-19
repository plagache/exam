#include <stdio.h>
#include <stdlib.h>

int		isprime(int c)
{
	int div;

	div = 3;
	if (c == 1)
		return (0);
	if (c == 2 || c == 3)
		return (1);
	if ((c % 2) == 0)
		return (0);
	while ((c % div) != 0)
	{
		div += 2;
		if (c == div)
			return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int div;

	div = 2;
	if (ac != 2)
	{
		printf("\n");
		return (0);
	}
	if (ac == 2)
	{
		int c;

		c = atoi(av[1]);
		if (isprime(c) == 1)
		{
			printf("%i\n", c);
			return (0);
		}
		while (isprime(c) != 0)
		{
			while ((c % div) == 0)
			{
				printf("%i*", div);
				div++;
				c = c / div;
			}
			if (isprime(c) == 1)
				printf("%i\n", c);
		}
	}
	return(0);
}
