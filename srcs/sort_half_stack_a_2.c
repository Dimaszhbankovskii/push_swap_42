#include "../includes/push_swap.h"

static int	type_sort_b_3(int a, int b, int c)
{
	int	type;

	type = 0;
	if (a < b && b < c && a < c)
		type = 1;
	else if (a < b && b > c && a < c)
		type = 2;
	else if (a > b && b < c && a < c)
		type = 3;
	else if (a < b && b > c && a > c)
		type = 4;
	else if (a > b && b < c && a > c)
		type = 5;
	return (type);
}

static void	private_sort_b_3(t_main *inf)
{
	int	type;

	type = type_sort_b_3(inf->stack_b->order, inf->stack_b->next->order, inf->stack_b->next->next->order);
	if (type == 1)
	{
		do_command(inf, "sb");
		do_command(inf, "rrb");
	}
	else if (type == 2)
		do_command(inf, "rb");
	else if (type == 3)
		do_command(inf, "rrb");
	else if (type == 4)
		do_command(inf, "sb");
	else if (type == 5)
	{
		do_command(inf, "sb");
		do_command(inf, "rb");
	}
}

void	sort_move_b(t_main *inf)
{
	if (len_stack(&(inf->stack_b)) == 2)
	{
		if (inf->stack_b->order < inf->stack_b->next->order)
			do_command(inf, "sb");
	}
    else if (len_stack(&(inf->stack_b)) == 3)
		private_sort_b_3(inf);
	while (len_stack(&(inf->stack_b)))
	{
		inf->stack_b->flag = inf->data->flag;
		do_command(inf, "pa");
	}
}
