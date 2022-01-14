#include "../includes/push_swap.h"

static int	sort_3_type(int a, int b, int c)
{
	int	type;

	type = 0;
	if (a > b && b > c && a > c)
		type = 1;
	else if (a > b && b < c && a > c)
		type = 2;
	else if (a < b && b > c && a < c)
		type = 3;
	else if (a > b && b < c && a < c)
		type = 4;
	else if (a < b && b > c && a > c)
		type = 5;
	return (type);
}

static void	private_sort_3(t_main *inf)
{
	int		type;

	type = sort_3_type(inf->stack_a->order, inf->stack_a->next->order, inf->stack_a->next->next->order);
	if (type == 1)
	{
		do_command(inf, "sa");
		do_command(inf, "rra");
	}
	else if (type == 2)
		do_command(inf, "ra");
	else if (type == 3)
	{
		do_command(inf, "sa");
		do_command(inf, "ra");
	}
	else if (type == 4)
		do_command(inf, "sa");
	else if (type == 5)
		do_command(inf, "rra");
}

static void	private_sort_4(t_main *inf)
{
	while (inf->stack_a->order != find_min_value_order(&(inf->stack_a)))
	{
		if (find_order(&(inf->stack_a), find_min_value_order(&(inf->stack_a))) <= 2)
			do_command(inf, "sa");
		else if (find_order(&(inf->stack_a), find_min_value_order(&(inf->stack_a))) > 2)
			do_command(inf, "rra");
	}
	do_command(inf, "pb");
	private_sort_3(inf);
	do_command(inf, "pa");
}

static void	private_sort_5(t_main *inf)
{
	while (inf->stack_a->order != find_min_value_order(&(inf->stack_a)))
	{
		if (find_order(&(inf->stack_a), find_min_value_order(&(inf->stack_a))) <= 2)
			do_command(inf, "sa");
		else if (find_order(&(inf->stack_a), find_min_value_order(&(inf->stack_a))) == 3)
			do_command(inf, "ra");
		else if (find_order(&(inf->stack_a), find_min_value_order(&(inf->stack_a))) >= 4)
			do_command(inf, "rra");
	}
	do_command(inf, "pb");
	private_sort_4(inf);
	do_command(inf, "pa");
}

void	private_sort(t_main *inf)
{
	if (len_stack(&(inf->stack_a)) == 2)
	{
		if (inf->stack_a->order > inf->stack_a->next->order)
			do_command(inf, "sa");
	}
	else if (len_stack(&(inf->stack_a)) == 3)
		private_sort_3(inf);
	else if (len_stack(&(inf->stack_a)) == 4)
		private_sort_4(inf);
	else if (len_stack(&(inf->stack_a)) == 5)
		private_sort_5(inf);
}
