#include <stdlib.h>
#include <stdio.h>

int		countletter(char *str)
{
	int c;

	c = 0;
	while (str[c] != '\n' && str[c] != ' ' && str[c] != '\t' && str[c])
		c++;
	return (c);
}

int		countword(char *str)
{
	int c;
	int j;

	c = 0;
	j = 0;
	while (str[c])
	{
		while (str[c] == '\n' || str[c] == ' ' || str[c] == '\t')
			c++;
		if (str[c] != '\n' && str[c] != ' ' && str[c] != '\t')
		{
			j++;
			while (str[c] != ' ' && str[c] != '\t' && str[c] != '\t' && str[c])
				c++;
		}
	}
	return (j);
}

char	**ft_split(char *str)
{
	int i;
	int c;
	int j;
	int lenw;
	int lens;
	char **split;

	i = 0;
	c = 0;
	lens = countword(str);
	if(!(split=(char**)malloc(sizeof(char*) * (lens + 1))))
		return (NULL);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		i++;
	while (str[i])
	{
		j = 0;
		lenw = countletter(str + i);
		if(!(split[c] =(char*)malloc(sizeof(char) * (lenw + 1))))
			return (NULL);
		while (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i])
		{
			split[c][j] = str[i];
			j++;
			i++;
		}
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && str[i])
			i++;
		split[c][j] = '\0';
		c++;
	}
	split[c] = NULL;
	return (split);
}

int		main(int ac, char **av)
{
	char **split;
	int c;
	int len;

	c = 0;
	len = countword(av[1]);
	if (ac != 2)
		printf("\n");
	if (ac == 2)
	{
		printf("len : %i \n", len);
		split = ft_split(av[1]);
		while (c < len)
		{
			printf("%s ", split[c]);
			c++;
		}
	}
	return (0);
}
