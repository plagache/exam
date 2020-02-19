#include <stdio.h>
#include <stdlib.h>
#include "t_point.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char c;
	int pos;

	pos = 0;
	c = tab[begin.x][begin.y];
	while (pos < size.x)
	{

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

char	**make_area(char *zone[], int c)
{
	int d;
	int len;
	int pos;
	char **str;

	d = 0;
	len = 0;
	if (!(str =(char**)malloc(sizeof(char*) * (c + 1))))
		return (0);
	str[c] = NULL;
	while (c > d)
	{
		len = ft_strlen(zone[d]);
		if (!(str[d] =(char*)malloc(sizeof(char) * (len + 1))))
			return (0);
		pos = 0;
		while(pos < len)
		{
			str[d][pos] = zone[d][pos];
			pos++;
		}
		d++;
	}
	return (str);
}

int		print_tab(char **area)
{
	int c;

	c = 0;
	while (area[c] != NULL)
	{
		printf("%s\n", area[c]);
		c++;
	}
	return (0);
}

int main(void)
{
	char **area;
	t_point size = { 8, 5 };
	t_point begin = { 2, 2 };
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	int c;

	c = sizeof(zone) / sizeof(char*);
	area = make_area(zone, c);
	print_tab(area);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area);
	return (0);
}
