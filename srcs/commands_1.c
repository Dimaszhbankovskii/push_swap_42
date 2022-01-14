#include "../includes/push_swap.h"

int	sa_sb(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *stack;
	if (tmp1 && tmp1->next)
	{
		tmp2 = tmp1->next;
		tmp1->next = tmp2->next;
		if (tmp2->next)
			tmp2->next->prev = tmp1;
		tmp1->prev = tmp2;
		tmp2->next = tmp1;
		tmp2->prev = NULL;
		*stack = tmp2;
		return (1);
	}
	else
		return (0);
}

int	pa_pb(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*from;
	t_stack	*to;

	from = *stack_from;
	to = *stack_to;
	if (!from)
		return (0);
	*stack_from = from->next;
	if (!to)
	{
		to = from;
		from->next->prev = NULL;
		to->next = NULL;
		to->prev = NULL;
		*stack_to = to;
	}
	else
	{
		from->next = to;
		to->prev = from;
		*stack_to = from;
		if (*stack_from)
			(*stack_from)->prev = NULL;
	}
	return (1);
}

int	ra_rb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	tmp = *stack;
	if (!tmp || !tmp->next)
		return (0);
	end = end_stack(stack);
	*stack = tmp->next;
	(*stack)->prev = NULL;
	end->next = tmp;
	tmp->next = NULL;
	tmp->prev = end;
	return (1);
}

int	rra_rrb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*begin;
	t_stack	*end;

	begin = *stack;
	if (!begin || !begin->next)
		return (0);
	end = end_stack(stack);
	tmp = end->prev;
	end->next = begin;
	end->prev = NULL;
	begin->prev = end;
	tmp->next = NULL;
	*stack = end;
	return (1);
}
