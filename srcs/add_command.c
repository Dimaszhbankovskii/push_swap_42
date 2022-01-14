#include "../includes/push_swap.h"

void	write_command(t_main *inf, char const *str, int done)
{
	t_command	*tmp;

	tmp = inf->result;
	while (tmp->command)
		tmp = tmp->next;
	if (done == 1)
	{
		tmp->command = ft_strdup(str);
		if (!tmp->command)
			exit(error_mess("error: malloc 'str command'\n", inf, 8));
		tmp->next = create_new_result(inf);
		tmp->next->prev = tmp;
	}
}

void	do_command(t_main *inf, char const *str)
{
	if (!ft_strcmp(str, "sa"))
		write_command(inf, str, sa_sb(&(inf->stack_a)));
	else if (!ft_strcmp(str, "sb"))
		write_command(inf, str, sa_sb(&(inf->stack_b)));
	else if (!ft_strcmp(str, "ss"))
		write_command(inf, str, ss(&(inf->stack_a), &(inf->stack_b)));
	else if (!ft_strcmp(str, "pa"))
		write_command(inf, str, pa_pb(&(inf->stack_b), &(inf->stack_a)));
	else if (!ft_strcmp(str, "pb"))
		write_command(inf, str, pa_pb(&(inf->stack_a), &(inf->stack_b)));
	else if (!ft_strcmp(str, "ra"))
		write_command(inf, str, ra_rb(&(inf->stack_a)));
	else if (!ft_strcmp(str, "rb"))
		write_command(inf, str, ra_rb(&(inf->stack_b)));
	else if (!ft_strcmp(str, "rr"))
		write_command(inf, str, rr(&(inf->stack_a), &(inf->stack_b)));
	else if (!ft_strcmp(str, "rra"))
		write_command(inf, str, rra_rrb(&(inf->stack_a)));
	else if (!ft_strcmp(str, "rrb"))
		write_command(inf, str, rra_rrb(&(inf->stack_b)));
	else if (!ft_strcmp(str, "rrr"))
		write_command(inf, str, rrr(&(inf->stack_a), &(inf->stack_b)));
}
