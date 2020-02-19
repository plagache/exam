#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int c;

	c = 0;
	while (str[c])
	{
		ft_putchar(str[c]);
		c++;
	}
}

void	print_pal(char *str, int strt, int end)
{
	while (end >= strt)
	{
		ft_putchar(str[strt]);
		strt++;
	}
}

int		ft_strlen(char *str)
{
	int c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int		is_pal(char *str, int start, int end)
{
	int lenght;

	lenght = end - start;
	while (str[start] == str[end] && end >= 0)
	{
		start++;
		end--;
	}
	if (str[start] != str[end])
		return (0);
	return (lenght);
}

void	test_str(char *str)
{
	int c;
	int len;
	int lenght;
	int d;
	int j;
	int strt;

	d = 1;
	len = ft_strlen(str);
	c = 0;
	while (str[c])
	{
		while (lenght >= j && (lenght = is_pal(str, c, d)) != 0)
		{
			d++;
		}
		j = lenght;
		strt = c;
		c++;
	}
	printf("len : %i\n", lenght);
	print_pal(str, strt, strt + lenght);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		test_str(av[1]);
	ft_putchar('\n');
	return (0);
}
