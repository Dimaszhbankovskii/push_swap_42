#include "../includes/push_swap.h"

int	check_sort_input_data(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

static t_main	*init_inf(void)
{
	t_main	*inf;

	inf = (t_main *)malloc(sizeof(t_main));
	if (!inf)
		return (NULL);
	inf->stack_a = NULL;
	inf->stack_b = NULL;
	inf->data = NULL;
	inf->result = NULL;
	return (inf);
}

static void	start_program(t_main *inf, int argc, char **argv)
{
	inf->stack_a = create_stack_a(argc, argv);
	inf->stack_b = NULL;	// можно удалить
	inf->data = create_struct_data();
	inf->result = create_new_result();
	if (argc < 7)
		private_sort(inf);
		// private_sort(&(inf->stack_a), &(inf->stack_b), &(inf->result));
	else
		ft_big_sort(&(inf->stack_a), &(inf->stack_b), \
		inf->data, &(inf->result));
}

char	*push_swap(int argc, char **argv)
{
	char	*res;
	t_main	*inf;

	inf = init_inf();
	if (inf)
	{
		start_program(inf, argc, argv);
		update_output_result(&(inf->result));
	}
	else
		return (NULL);
	res = list_to_str(&(inf->result));
	inf = free_all(inf);
	return (res);
}

int	main(int argc, char **argv)
{
	int		check;
	char	*res;

	check = input_validation(argc, argv);
	if (check == 0)
		ft_putstr_fd("No data enter! Start program and enter data againg!\n", 1);
	if (check == -1)
		ft_putstr_fd("Error\n", 1);
	if (check == 1 && check_sort_input_data(argc, argv))
		return (0);
	if (check == 1)
	{
		res = push_swap(argc, argv);
		ft_putstr_fd(res, 1);
		ft_putchar_fd('\n', 1);
		free (res);
		res = NULL;
	}
	return (0);
}
