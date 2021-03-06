#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*stack)
	{
		tmp1 = *stack;
		tmp2 = tmp1->next;
		while (tmp1)
		{
			tmp1->next = NULL;
			tmp1->prev = NULL;
			free(tmp1->score);
			free(tmp1);
			tmp1 = tmp2;
			if (tmp2)
				tmp2 = tmp2->next;
		}
		*stack = NULL;
	}
}

static void	free_result(t_command **res)
{
	t_command	*tmp1;
	t_command	*tmp2;

	if (*res)
	{
		tmp1 = *res;
		tmp2 = tmp1->next;
		while (tmp1)
		{
			free(tmp1->command);
			tmp1->command = NULL;
			tmp1->next = NULL;
			tmp1->prev = NULL;
			free(tmp1);
			tmp1 = tmp2;
			if (tmp2)
				tmp2 = tmp2->next;
		}
		*res = NULL;
	}
}

void	free_arr_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		arr[i] = NULL;
		i++;
	}
	free (arr);
	arr = NULL;
}

void	free_inf(t_main *inf)
{
	if (inf)
	{
		free_stack(&(inf->a));
		free_stack(&(inf->b));
		free_result(&(inf->res));
		free(inf->data);
		inf->data = NULL;
		free(inf->insert);
		inf->insert = NULL;
		free_arr_char(inf->arr_char);
		free(inf);
		inf = NULL;
	}
}
