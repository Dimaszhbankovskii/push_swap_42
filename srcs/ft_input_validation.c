#include "../includes/push_swap.h"

static int	str_is_digit(char const *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static long long int	ft_ll_atoi(char const *str)
{
	long long int	num;
	int				i;
	int				sign;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

static int	check_int(int argc, char **argv)
{
	int				i;

	i = 1;
	while (i < argc)
	{
		if (ft_ll_atoi(argv[i]) < -2147483648 || \
		ft_ll_atoi(argv[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	input_validation(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!str_is_digit(argv[i++]))
			return (-1);
	}
	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j++]) == 0)
				return (-1);
		}
		i++;
	}
	if (!check_int(argc, argv))
		return (-1);
	return (1);
}
