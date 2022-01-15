#include "../includes/push_swap.h"

static int	do_command_checker(t_main *inf, char const *str)
{
	if (!ft_strcmp(str, "sa"))
		return (sa_sb(&(inf->a)));
	else if (!ft_strcmp(str, "sb"))
		return (sa_sb(&(inf->b)));
	else if (!ft_strcmp(str, "ss"))
		return (ss(&(inf->a), &(inf->b)));
	else if (!ft_strcmp(str, "pa"))
		return (pa_pb(&(inf->b), &(inf->a)));
	else if (!ft_strcmp(str, "pb"))
		return (pa_pb(&(inf->a), &(inf->b)));
	else if (!ft_strcmp(str, "ra"))
		return (ra_rb(&(inf->a)));
	else if (!ft_strcmp(str, "rb"))
		return (ra_rb(&(inf->b)));
	else if (!ft_strcmp(str, "rr"))
		return (rr(&(inf->a), &(inf->b)));
	else if (!ft_strcmp(str, "rra"))
		return (rra_rrb(&(inf->a)));
	else if (!ft_strcmp(str, "rrb"))
		return (rra_rrb(&(inf->b)));
	else if (!ft_strcmp(str, "rrr"))
		return (rrr(&(inf->a), &(inf->b)));
	return (0);
}

static char	*valid_command(char *str, t_main *inf)
{
	char	*out;
	int		i;

	i = 0;
	while (str && str[i] != '\n' && str[i])
		i++;
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		exit(error_mess("Error: malloc 'checker'\n", inf, 11));
	i = 0;
	while (str && str[i] != '\n' && str[i])
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	free (str);
	return (out);
}

static void	checker(t_main *inf)
{
	char	*line;

	inf->a = create_stack_a(inf);
	while (get_next_line(0, &line) > 0)
	{
		line = valid_command(line, inf);
		if (!(do_command_checker(inf, line)))
		{
			free (line);
			exit(error_mess("error\n", inf, 12));
		}
		free (line);
		line = NULL;
	}
	if (check_sort_stack(&(inf->a)) && !inf->b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_main	*inf;
	int		check;

	inf = init_inf();
	inf->arr_char = parsing_input_data(argc, argv, inf);
	check = input_validation(len_arr_str(inf->arr_char), inf->arr_char);
	if (check == 0)
		exit(error_mess("No data enter!\n", inf, 3));
	if (check == -1)
		exit(error_mess("Error\n", inf, 4));
	if (check == 1 && check_sort_input_data(inf->arr_char))
		exit(error_mess(NULL, inf, 0));
	if (check == 1)
	{
		checker(inf);
		free_inf(inf);
	}
	return (0);
}
