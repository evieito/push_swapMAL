#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_number(const char *s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol_error(const char *s)
{
	long	sign = 1;
	long	res = 0;
	int		i = 0;

	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		if (sign == 1 && res > INT_MAX)
			print_error();
		if (sign == -1 && -res < INT_MIN)
			print_error();
		i++;
	}
	return (res * sign);
}

int	has_duplicates(char **tokens)
{
	int	i, j;

	for (i = 0; tokens[i]; i++)
	{
		for (j = i + 1; tokens[j]; j++)
		{
			long a = ft_atol_error(tokens[i]);
			long b = ft_atol_error(tokens[j]);
			if (a == b)
				return (1);
		}
	}
	return (0);
}