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

static void	ft_sort_3_b(t_stack **stack, t_command **result)
{
	t_stack	*p;
	int		type;

	p = *stack;
	type = ft_sort_3_b_type(p->order, p->next->order, p->next->next->order);
	if (type == 1)
	{
		do_command(NULL, &p, result, "sb");
		do_command(NULL, &p, result, "rrb");
	}
	else if (type == 2)
		do_command(NULL, &p, result, "rb");
	else if (type == 3)
		do_command(NULL, &p, result, "rrb");
	else if (type == 4)
		do_command(NULL, &p, result, "sb");
	else if (type == 5)
	{
		do_command(NULL, &p, result, "sb");
		do_command(NULL, &p, result, "rb");
	}
	*stack = p;
}

static void	ft_sort_2_b(t_stack **stack, t_command **result)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->order < tmp->next->order)
		do_command(NULL, &tmp, result, "sb");
	*stack = tmp;
}

void    ft_spec_sort_b(t_stack **stack_a, t_stack **stack_b, t_command **result)
{
    t_stack *tmp_a;
    t_stack *tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if (len_stack(&tmp_b) == 2)
		ft_sort_2_b(&tmp_b, result);
    else if (len_stack(&tmp_b) == 3)
		ft_sort_3_b(&tmp_b, result);
	*stack_a = tmp_a;
	*stack_b = tmp_b;
}
