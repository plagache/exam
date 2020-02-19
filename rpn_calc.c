#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int			is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			is_operateur(char c)
{
	if (c == '-' || c == '+' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

int			ft_strlen(char *str)
{
	int c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

long		*rpn_calc(char *str)
{
	int c;
	long *tab;
	int		j;

	c = 0;
	j = 0;
	if (!(tab = (long*)malloc(sizeof(long) * (ft_strlen(str)))))
		return (0);
	while (str[c])
	{
		while (is_operateur(str[c]) == 0)
		{
			tab[j] = atoi(str + c);
			j++;
			while (str[c] && str[c] != ' ')
				c++;
			if (str[c] == '\0')
			{
				printf("Error");
				return (0);
			}
			while (str[c] && str[c] == ' ')
				c++;
		}
		if (j < 2)
		{
			printf("Error");
			return (0);
		}
		if (str[c] == '/')
		{
			if (tab[j - 1] == 0)
			{
				printf("Error");
				return (0);
			}
			tab[j - 2] = tab[j - 2] / tab[j - 1];
		}
		else if (str[c] == '%')
		{
			if (tab[j - 1] == 0)
			{
				printf("Error");
				return (0);
			}
			tab[j - 2] = tab[j - 2] % tab[j - 1];
		}
		else if (str[c] == '-')
			tab[j - 2] = tab[j - 2] - tab[j - 1];
		else if (str[c] == '+')
			tab[j - 2] = tab[j - 2] + tab[j - 1];
		else if (str[c] == '*')
			tab[j - 2] = tab[j - 2] * tab[j - 1];
		j--;
		c++;
		while (str[c] == ' ')
			c++;
	}
	if (j > 1)
	{
		printf("Error");
		return (0);
	}
	return (tab);
}

int			main(int ac, char **av)
{
	long *tab;
	if (ac == 2)
	{
		tab = rpn_calc(av[1]);
		if (tab != NULL)
			printf("%ld\n", tab[0]);
	}
	else
		printf("Error");
	return (0);
}
