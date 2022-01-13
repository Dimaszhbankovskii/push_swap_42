#include "../includes/push_swap.h"

int	len_stack(t_stack **stack)
{
	t_stack	*tmp;
	int	i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	find_min_value_order(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack;
	min = 0;
	if (tmp)
	{
		min = tmp->order;
		while (tmp)
		{
			if (tmp->order < min)
				min = tmp->order;
			tmp = tmp->next;
		}
	}
	return (min);
}

int	find_max_value_order(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = 0;
	if (tmp)
	{
		max = tmp->order;
		while (tmp)
		{
			if (tmp->order > max)
				max = tmp->order;
			tmp = tmp->next;
		}
	}
	return (max);
}

int	find_order(t_stack **stack, int order)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 1;
	while (tmp->order != order)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*end_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	check_sort_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->order > tmp->next->order)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_count_unsort_big(t_stack **stack)
{
	t_stack	*tmp;
	int		count;

	tmp = *stack;
	count = 0;
	while (tmp->flag == 0)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
