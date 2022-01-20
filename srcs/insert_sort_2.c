#include "../includes/push_swap.h"

static t_stack	*find_elem_min_score(t_stack **b)
{
	t_stack	*tmp;
	int		min;

	tmp = *b;
	min = tmp->score->score_all;
	while (tmp)
	{
		if (min > tmp->score->score_all)
			min = tmp->score->score_all;
		tmp = tmp->next;
	}
	tmp = *b;
	while (tmp && tmp->score->score_all != min)
		tmp = tmp->next;
	return (tmp);
}

static void	insert_elem(t_main *inf, t_stack *elem)
{
	if (elem->score->score_ra <= elem->score->score_rra && elem->score->score_rb <= elem->score->score_rrb)
	{
		while (elem->score->score_ra || elem->score->score_rb)
		{
			if (elem->score->score_ra)
			{
				do_command(inf, "ra");
				elem->score->score_ra--;
			}
			if (elem->score->score_rb)
			{
				do_command(inf, "rb");
				elem->score->score_rb--;
			}
		}
	}
	else if (elem->score->score_ra > elem->score->score_rra && elem->score->score_rb > elem->score->score_rrb)
	{
		while (elem->score->score_rra || elem->score->score_rrb)
		{
			if (elem->score->score_rra)
			{
				do_command(inf, "rra");
				elem->score->score_rra--;
			}
			if (elem->score->score_rrb)
			{
				do_command(inf, "rrb");
				elem->score->score_rrb--;
			}
		}
	}
	if (elem->score->score_ra <= elem->score->score_rra)
		while (elem->score->score_ra--)
			do_command(inf, "ra");
	else
		while (elem->score->score_rra--)
			do_command(inf, "rra");
	if (elem->score->score_rb <= elem->score->score_rrb)
		while (elem->score->score_rb--)
			do_command(inf, "rb");
	else
		while (elem->score->score_rrb--)
			do_command(inf, "rrb");

	do_command(inf, "pa");
}

void	do_insert_sort(t_main *inf)
{
	while (inf->b)
	{
		count_score(inf);
		insert_elem(inf, find_elem_min_score(&(inf->b)));
	}
}
