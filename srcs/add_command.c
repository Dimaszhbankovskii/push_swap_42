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
	int	i;

	i = 0;
	if (ft_strcmp(str, "sa") == 0)
		i = ft_sa_sb(&(inf->stack_a));
	else if (ft_strcmp(str, "sb") == 0)
		i = ft_sa_sb(&(inf->stack_b));
	else if (ft_strcmp(str, "ss") == 0)
		i = ft_ss(&(inf->stack_a), &(inf->stack_b));
	else if (ft_strcmp(str, "pa") == 0)
		i = ft_pa_pb(&(inf->stack_b), &(inf->stack_a));
	else if (ft_strcmp(str, "pb") == 0)
		i = ft_pa_pb(&(inf->stack_a), &(inf->stack_b));
	else if (ft_strcmp(str, "ra") == 0)
		i = ft_ra_rb(&(inf->stack_a));
	else if (ft_strcmp(str, "rb") == 0)
		i = ft_ra_rb(&(inf->stack_b));
	else if (ft_strcmp(str, "rr") == 0)
		i = ft_rr(&(inf->stack_a), &(inf->stack_b));
	else if (ft_strcmp(str, "rra") == 0)
		i = ft_rra_rrb(&(inf->stack_a));
	else if (ft_strcmp(str, "rrb") == 0)
		i = ft_rra_rrb(&(inf->stack_b));
	else if (ft_strcmp(str, "rrr") == 0)
		i = ft_rrr(&(inf->stack_a), &(inf->stack_b));
	write_command(inf, str, i);
}
