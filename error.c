#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

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
	long	sign;
	long	res;
	int		i;

	errno = 0;
	sign = 1;
	res = 0;
	i = 0;
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
		{
			errno = ERANGE;
			return (0);
		}
		if (sign == -1 && -res < INT_MIN)
		{
			errno = ERANGE;
			return (0);
		}
		i++;
	}
	return (res * sign);
}

int	has_duplicates(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	while (tokens[i])
	{
		j = i + 1;
		while (tokens[j])
		{
			errno = 0;
			if (ft_atol_error(tokens[i]), errno == ERANGE)
				return (-1);
			if (ft_atol_error(tokens[j]), errno == ERANGE)
				return (-1);
			if (ft_atol_error(tokens[i]) == ft_atol_error(tokens[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}