#include "../includes/push_swap.h"

static void	partition_a(t_main *inf)
{
	int		flag;

	flag = inf->a->flag;
	while (inf->a->flag == flag)
	{
		if (inf->a->order == inf->data->next)
		{
			do_command(inf, "ra");
			inf->data->next++;
		}
		else
			do_command(inf, "pb");
	}
}

static void	move_b(t_main *inf)
{
	if (inf->b->order == inf->data->next)
	{
		inf->b->flag = inf->data->flag;
		do_command(inf, "pa");
		do_command(inf, "ra");
		inf->data->next++;
	}
	if (inf->b && inf->b->order >= inf->data->mid)
	{
		inf->b->flag = inf->data->flag;
		do_command(inf, "pa");
	}
	else
		do_command(inf, "rb");
}

static int	check_move_b(t_stack **stack, t_data *data)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->order >= data->mid)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	partition_b(t_main *inf)
{
	while (inf->b && len_stack(&(inf->b)) > 3)
	{
		update_data(inf->data, &(inf->b));
		while (inf->b && check_move_b(&(inf->b), inf->data))
			move_b(inf);
	}
	if (inf->b && len_stack(&(inf->b)) <= 3)
		sort_move_b(inf);
}

void	sort_half_stack_a(t_main *inf)
{
	partition_b(inf);
	while (inf->a->flag)
	{
		partition_a(inf);
		partition_b(inf);
	}
}
