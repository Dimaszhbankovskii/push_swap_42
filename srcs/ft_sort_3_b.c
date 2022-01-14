#include "../includes/push_swap.h"

static int	ft_sort_3_b_type(int a, int b, int c)
{
	int	type;

	type = 0;
	if (a < b && b < c && a < c) // 1 2 3
		type = 1;
	else if (a < b && b > c && a < c) // 1 3 2
		type = 2;
	else if (a > b && b < c && a < c) // 2 1 3
		type = 3;
	else if (a < b && b > c && a > c) // 2 3 1
		type = 4;
	else if (a > b && b < c && a > c) // 3 1 2
		type = 5;
	return (type);
}

static void	ft_sort_3_b(t_main *inf)
{
	int		type;

	type = ft_sort_3_b_type(inf->stack_b->order, inf->stack_b->next->order, inf->stack_b->next->next->order);
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

void    ft_spec_sort_b(t_main *inf)
{
	if (len_stack(&(inf->stack_b)) == 2)
	{
		if (inf->stack_b->order < inf->stack_b->next->order)
			do_command(inf, "sb");
	}
    else if (len_stack(&(inf->stack_b)) == 3)
		ft_sort_3_b(inf);
}
