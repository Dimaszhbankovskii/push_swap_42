#include "../includes/push_swap.h"

static void	free_stack(t_stack **stack)
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
			free(tmp1);
			tmp1 = tmp2;
			if (tmp2)
				tmp2 = tmp2->next;
		}
		*stack = NULL;
	}
}

static void	free_result(t_command **result)
{
	t_command	*tmp1;
	t_command	*tmp2;

	if (*result)
	{
		tmp1 = *result;
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
		*result = NULL;
	}
}

t_main	*free_all(t_main *inf)
{
	free_stack(&(inf->stack_a));
	free_stack(&(inf->stack_b));
	free_result(&(inf->result));
	free(inf->data);
	inf->data = NULL;
	free(inf);
	return (NULL);
}
