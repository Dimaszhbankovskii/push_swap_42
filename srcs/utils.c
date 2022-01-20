#include "../includes/push_swap.h"

t_main	*init_inf(void)
{
	t_main	*inf;

	inf = (t_main *)malloc(sizeof(t_main));
	if (!inf)
		exit(end_program(NULL, 1));
	inf->a = NULL;
	inf->b = NULL;
	inf->data = NULL;
	inf->insert = NULL;
	inf->res = NULL;
	inf->arr_char = NULL;
	return (inf);
}

int	check_sort_input_data(char **arr)
{
	int	i;
	int	len;

	i = 0;
	len = len_arr_str(arr);
	while (i < len - 1)
	{
		if (ft_atoi(arr[i]) > ft_atoi(arr[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	len_arr_str(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	end_program(t_main *inf, int num_error)
{
	free_inf(inf);
	return (num_error);
}

void	print_result(char *res)
{
	ft_putstr_fd(res, 1);
	ft_putchar_fd('\n', 1);
	free (res);
	res = NULL;
}
