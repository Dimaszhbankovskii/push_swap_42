#include "../includes/push_swap.h"

static int	*sort_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (i < len)
	{
		j = len - 1;
		while (j > i)
		{
			if (arr[j - 1] > arr[j])
			{
				n = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = n;
			}
			j--;
		}
		i++;
	}
	return (arr);
}

static int	*make_arr_int(t_main *inf)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * len_arr_str(inf->arr_char));
	if (!array)
		return (NULL);
	i = 0;
	while (inf->arr_char[i])
	{
		array[i] = ft_atoi(inf->arr_char[i]);
		i++;
	}
	array = sort_arr(array, len_arr_str(inf->arr_char));
	return (array);
}

static t_stack	*order_stack_a(t_stack **stack, int *arr, t_main *inf)
{
	t_stack	*tmp;
	int		i;

	if (!arr)
	{
		free_stack(stack);
		free (arr);
		exit (error_mess("Error: malloc 'stack A'\n", inf, 5));
	}
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (tmp->value == arr[i])
		{
			tmp->order = i + 1;
			tmp = tmp->next;
			i = 0;
		}
		else
			i++;
	}
	free (arr);
	return (*stack);
}

static t_stack	*create_new_nod(t_main *inf)
{
	t_stack	*new;

	new = (t_stack *)malloc((sizeof(t_stack)));
	if (!new)
		exit (error_mess("Error: malloc 'stack A'\n", inf, 5));
	new->value = 0;
	new->order = 0;
	new->flag = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*create_stack_a(t_main *inf)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	int		i;

	stack_a = create_new_nod(inf);
	tmp = stack_a;
	i = 0;
	while (inf->arr_char[i])
	{
		tmp->value = ft_atoi(inf->arr_char[i]);
		if (inf->arr_char[i + 1])
		{
			tmp->next = create_new_nod(inf);
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		i++;
	}
	return (order_stack_a(&stack_a, make_arr_int(inf), inf));
}
