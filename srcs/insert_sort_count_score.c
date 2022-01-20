#include "../includes/push_swap.h"

static void	count_score_ra_rra(t_main *inf, t_stack *b)
{
	t_stack	*tmp;
	int		flag;

	flag = 1;
	tmp = inf->a;
	while (tmp && tmp->next && flag)
	{
		if (b->order > tmp->order && \
		b->order < tmp->next->order)
		{
			b->score->score_ra = find_order(&(inf->a), tmp->order);
			b->score->score_rra = len_stack(&(inf->a)) - \
			find_order(&(inf->a), tmp->next->order) + 1;
			flag = 0;
		}
		tmp = tmp->next;
	}
	if (flag && b->order < inf->a->order && \
	b->order > end_stack(&(inf->a))->order)
	{
		b->score->score_ra = 0;
		b->score->score_rra = 0;	//?
	}
}

static int	count_score_all(t_score *score)
{
	int	count;

	count = 1;
	if (score->score_ra <= score->score_rra)
		count += score->score_ra;
	else
		count += score->score_rra;
	if (score->score_rb <= score->score_rrb)
		count += score->score_rb;
	else
		count += score->score_rrb;
	return (count);
}

void	count_score(t_main *inf)
{
	t_stack	*tmp;

	tmp = inf->b;
	while (tmp)
	{
		count_score_ra_rra(inf, tmp);
		tmp->score->score_rb = find_order(&(inf->b), tmp->order) - 1;
		tmp->score->score_rrb = len_stack(&(inf->b)) - \
		find_order(&(inf->b), tmp->order) + 1;
		tmp->score->score_all = count_score_all(tmp->score);
		tmp = tmp->next;
	}
}
