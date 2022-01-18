#include "../includes/push_swap.h"

static char	*push_swap(t_main *inf)
{
	inf->a = create_stack_a(inf);
	inf->data = create_struct_data(inf);
	inf->res = create_new_result(inf);
	if (len_arr_str(inf->arr_char) < 6)
		private_sort(inf);
	else if (len_arr_str(inf->arr_char) >= 6 && \
	len_arr_str(inf->arr_char) <= 200)
		insert_sort(inf);
	else
		quick_sort(inf);
	update_output_result(inf);
	return (get_result(inf));
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
		print_result(push_swap(inf));
		free_inf(inf);
	}
	return (0);
}
