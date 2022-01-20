#include "../includes/push_swap.h"

static void	find_min_max_median(t_main *inf)
{
	inf->insert->min = find_min_value_order(&(inf->a));
	inf->insert->max = find_max_value_order(&(inf->a));
	inf->insert->median = (inf->insert->max + inf->insert->min) / 2;
}

static void	make_circle_sort(t_main *inf)
{
	int	a;
	int	b;
	int	c;

	a = inf->a->order;
	b = inf->a->next->order;
	c = inf->a->next->next->order;
	if (a < b && b > c && a < c)
		do_command(inf, "sa");
	else if (a > b && b > c && a > c)
	{
		do_command(inf, "ra");
		do_command(inf, "sa");
	}
	else if (a > b && b < c && a < c)
		do_command(inf, "sa");
}

static void	init_score(t_main *inf)
{
	t_stack	*tmp;

	tmp = inf->a;
	while (tmp)
	{
		tmp->score = (t_score *)malloc(sizeof(t_score));
		if (!tmp->score)
			exit(end_program(inf, 13));
		tmp->score->score_ra = 0;
		tmp->score->score_rra = 0;
		tmp->score->score_rb = 0;
		tmp->score->score_rrb = 0;
		tmp->score->score_all = 0;
		tmp = tmp->next;
	}
}

void	insert_sort(t_main *inf)
{
	inf->insert = (t_insert *)malloc(sizeof(t_insert));
	if (!inf->insert)
		exit(end_program(inf, 14));
	init_score(inf);
	find_min_max_median(inf);
	while (len_stack(&(inf->a)) > 3)
	{
		if (inf->a->order == inf->insert->min || \
		inf->a->order == inf->insert->max || \
		inf->a->order == inf->insert->median)
			do_command(inf, "ra");
		else
			do_command(inf, "pb");
	}
	make_circle_sort(inf);
	do_insert_sort(inf);
	while (!check_sort_stack(&(inf->a)))
	{
		if (find_order(&(inf->a), find_min_value_order(&(inf->a))) < len_stack(&(inf->a)) / 2)
			do_command(inf, "ra");
		else
			do_command(inf, "rra");
	}
}
