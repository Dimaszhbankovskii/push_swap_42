#include "../includes/push_swap.h"

static int	type_3_numbers(int a, int b, int c)
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

static void	private_sort_3(t_stack **stack, t_command **result)
{
	t_stack	*p;
	int		type;

	p = *stack;
	type = type_3_numbers(p->order, p->next->order, p->next->next->order);
	if (type == 1)
	{
		do_command(&p, NULL, result, "sa");
		do_command(&p, NULL, result, "rra");
	}
	else if (type == 2)
		do_command(&p, NULL, result, "ra");
	else if (type == 3)
	{
		do_command(&p, NULL, result, "sa");
		do_command(&p, NULL, result, "ra");
	}
	else if (type == 4)
		do_command(&p, NULL, result, "sa");
	else if (type == 5)
		do_command(&p, NULL, result, "rra");
	*stack = p;
}

static void	private_sort_4(t_stack **stack_a, t_stack **stack_b, \
t_command **result)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a->order != find_min_value_order(&tmp_a))
	{
		if (find_order(&tmp_a, find_min_value_order(&tmp_a)) <= 2)
			do_command(&tmp_a, NULL, result, "sa");
		else if (find_order(&tmp_a, find_min_value_order(&tmp_a)) > 2)
			do_command(&tmp_a, NULL, result, "rra");
	}
	do_command(&tmp_a, &tmp_b, result, "pb");
	private_sort_3(&tmp_a, result);
	do_command(&tmp_a, &tmp_b, result, "pa");
	*stack_a = tmp_a;
	*stack_b = tmp_b;
}

static void	private_sort_5(t_stack **stack_a, t_stack **stack_b, \
t_command **result)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a->order != find_min_value_order(&tmp_a))
	{
		if (find_order(&tmp_a, find_min_value_order(&tmp_a)) <= 2)
			do_command(&tmp_a, NULL, result, "sa");
		else if (find_order(&tmp_a, find_min_value_order(&tmp_a)) == 3)
			do_command(&tmp_a, NULL, result, "ra");
		else if (find_order(&tmp_a, find_min_value_order(&tmp_a)) >= 4)
			do_command(&tmp_a, NULL, result, "rra");
	}
	do_command(&tmp_a, &tmp_b, result, "pb");
	private_sort_4(&tmp_a, &tmp_b, result);
	do_command(&tmp_a, &tmp_b, result, "pa");
	*stack_a = tmp_a;
	*stack_b = tmp_b;
}

void	private_sort(t_main *inf)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = inf->stack_a;
	tmp_b = inf->stack_b;
	if (len_stack(&tmp_a) == 2)
	{
		if (tmp_a->order > tmp_a->next->order)
			do_command(&tmp_a, NULL, &(inf->result), "sa");
	}
	else if (len_stack(&tmp_a) == 3)
		private_sort_3(&tmp_a, &(inf->result));
	else if (len_stack(&tmp_a) == 4)
		private_sort_4(&tmp_a, &tmp_b, &(inf->result));
	else if (len_stack(&tmp_a) == 5)
		private_sort_5(&tmp_a, &tmp_b, &(inf->result));
	inf->stack_a = tmp_a;
	inf->stack_b = tmp_b;
}

// void	private_sort(t_stack **stack_a, t_stack **stack_b, t_command **result)
// {
// 	t_stack	*tmp_a;
// 	t_stack	*tmp_b;

// 	tmp_a = *stack_a;
// 	tmp_b = *stack_b;
// 	if (len_stack(&tmp_a) == 2)
// 	{
// 		if (tmp_a->order > tmp_a->next->order)
// 			do_command(&tmp_a, NULL, result, "sa");
// 	}
// 	else if (len_stack(&tmp_a) == 3)
// 		ft_sort_3(&tmp_a, result);
// 	else if (len_stack(&tmp_a) == 4)
// 		ft_sort_4(&tmp_a, &tmp_b, result);
// 	else if (len_stack(&tmp_a) == 5)
// 		ft_sort_5(&tmp_a, &tmp_b, result);
// 	*stack_a = tmp_a;
// 	*stack_b = tmp_b;
// }
