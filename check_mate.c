#include <unistd.h>

void	check_mate(char **plateau, int taille)
{
	int		i;

	i = 0;
	while (i < taille)
	{
		write(1, plateau[i], taille);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac > 2)
	{
		check_mate(++av, ac - 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
