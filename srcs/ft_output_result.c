#include "../includes/push_swap.h"

static int	ft_check_comb_command(t_command *tmp1, t_command *tmp2)
{
	char	*s1;
	char	*s2;

	s1 = tmp1->command;
	s2 = tmp2->command;
	if ((ft_strcmp(s1, "sa") == 0 && ft_strcmp(s2, "sb") == 0) || \
	(ft_strcmp(s1, "sb") == 0 && ft_strcmp(s2, "sa") == 0))
		return (1);
	else if ((ft_strcmp(s1, "ra") == 0 && ft_strcmp(s2, "rb") == 0) || \
	(ft_strcmp(s1, "rb") == 0 && ft_strcmp(s2, "ra") == 0))
		return (2);
	else if ((ft_strcmp(s1, "rra") == 0 && ft_strcmp(s2, "rrb") == 0) || \
	(ft_strcmp(s1, "rrb") == 0 && ft_strcmp(s2, "rra") == 0))
		return (3);
	// удаление команд исключающих друг друга
	else if ((ft_strcmp(s1, "sa") == 0 && ft_strcmp(s2, "sa") == 0) || \
	(ft_strcmp(s1, "sb") == 0 && ft_strcmp(s2, "sb") == 0) || \
	(ft_strcmp(s1, "ss") == 0 && ft_strcmp(s2, "ss") == 0))
		return (4);
	else if ((ft_strcmp(s1, "ra") == 0 && ft_strcmp(s2, "rra") == 0) || \
	(ft_strcmp(s1, "rra") == 0 && ft_strcmp(s2, "ra") == 0))
		return (4);
	else if ((ft_strcmp(s1, "rb") == 0 && ft_strcmp(s2, "rrb") == 0) || \
	(ft_strcmp(s1, "rrb") == 0 && ft_strcmp(s2, "rb") == 0))
		return (4);
	else if ((ft_strcmp(s1, "rr") == 0 && ft_strcmp(s2, "rrr") == 0) || \
	(ft_strcmp(s1, "rrr") == 0 && ft_strcmp(s2, "rr") == 0))
		return (4);

	return (0);
}

static void	ft_del_command(t_command **tmp, char const *str)
{
	t_command	*save;
	t_command	*del;

	save = *tmp;
	del = save->next;
	free(save->command);
	save->command = NULL;
	save->command = ft_strdup(str);
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

static void	ft_del_2_command(t_command **tmp)
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
	del1->command = NULL;
	del1->next = NULL;
	del1->prev = NULL;
	free(del1);
	del1 = NULL;
	
	free(del2->command);
	del2->command = NULL;
	del2->next = NULL;
	del2->prev = NULL;
	free(del2);
	del2 = NULL;

	save1->next = save2;
	save2->prev = save1;

	*tmp = save2;
}

static void	ft_comb_command(t_command **result, int i)
{
	t_command	*tmp;

	tmp = *result;
	if (i == 1)
		ft_del_command(&tmp, "ss");
	else if (i == 2)
		ft_del_command(&tmp, "rr");
	else if (i == 3)
		ft_del_command(&tmp, "rrr");
	else if (i == 4)
		ft_del_2_command(&tmp);
	*result = tmp;
}

void	update_output_result(t_command **result)
{
	t_command	*tmp;

	tmp = *result;
	while (tmp->command && tmp->next->command)
	{
		if (ft_check_comb_command(tmp, tmp->next) > 0)
		{
			ft_comb_command(&tmp, ft_check_comb_command(tmp, tmp->next));
			tmp = *result;
		}
		else
			tmp = tmp->next;
	}
}
