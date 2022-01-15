#include "../includes/push_swap.h"

static int	check_delete_command(t_command *com1, t_command *com2)
{
	char	*s1;
	char	*s2;

	s1 = com1->command;
	s2 = com2->command;
	if ((!ft_strcmp(s1, "sa") && !ft_strcmp(s2, "sa")) || \
	(!ft_strcmp(s1, "sb") && !ft_strcmp(s2, "sb")) || \
	(!ft_strcmp(s1, "ss") && !ft_strcmp(s2, "ss")))
		return (4);
	else if ((!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rra")) || \
	(!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "ra")))
		return (4);
	else if ((!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "rrb")) || \
	(!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rb")))
		return (4);
	else if ((!ft_strcmp(s1, "rr") && !ft_strcmp(s2, "rrr")) || \
	(!ft_strcmp(s1, "rrr") && !ft_strcmp(s2, "rr")))
		return (4);
	return (0);
}

static int	check_comb_command(t_command *com1, t_command *com2)
{
	char	*s1;
	char	*s2;

	s1 = com1->command;
	s2 = com2->command;
	if ((!ft_strcmp(s1, "sa") && !ft_strcmp(s2, "sb")) || \
	(!ft_strcmp(s1, "sb") && !ft_strcmp(s2, "sa")))
		return (1);
	else if ((!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rb")) || \
	(!ft_strcmp(s1, "rb") && !ft_strcmp(s2, "ra")))
		return (2);
	else if ((!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "rrb")) || \
	(!ft_strcmp(s1, "rrb") && !ft_strcmp(s2, "rra")))
		return (3);
	return (check_delete_command(com1, com2));
}

static void	replace_command(t_command **tmp, char const *str, t_main *inf)
{
	t_command	*save;
	t_command	*del;

	save = *tmp;
	del = save->next;
	free(save->command);
	save->command = NULL;
	save->command = ft_strdup(str);
	if (!save->command)
		exit(error_mess("Error: malloc 'replace_command'\n", inf, 9));
	save->next = del->next;
	if (del->next)
		del->next->prev = save;
	free(del->command);
	del->command = NULL;
	del->next = NULL;
	del->prev = NULL;
	free(del);
	del = NULL;
	*tmp = save;
}

static void	delete_2_commands(t_command **tmp)
{
	t_command	*del1;
	t_command	*del2;
	t_command	*save1;
	t_command	*save2;

	save1 = (*tmp)->prev;
	del1 = *tmp;
	del2 = del1->next;
	save2 = del2->next;
	free(del1->command);
	free(del1);
	del1 = NULL;
	free(del2->command);
	free(del2);
	del2 = NULL;
	save1->next = save2;
	save2->prev = save1;
	*tmp = save2;
}

void	update_output_result(t_main *inf)
{
	t_command	*tmp;

	tmp = inf->res;
	while (tmp->command && tmp->next->command)
	{
		if (check_comb_command(tmp, tmp->next))
		{
			if (check_comb_command(tmp, tmp->next) == 1)
				replace_command(&tmp, "ss", inf);
			else if (check_comb_command(tmp, tmp->next) == 2)
				replace_command(&tmp, "rr", inf);
			else if (check_comb_command(tmp, tmp->next) == 3)
				replace_command(&tmp, "rrr", inf);
			else if (check_comb_command(tmp, tmp->next) == 4)
				delete_2_commands(&tmp);
			tmp = inf->res;
		}
		else
			tmp = tmp->next;
	}
}
