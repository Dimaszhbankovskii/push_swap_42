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

static int	*make_arr(int argc, char **argv)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	array = sort_arr(array, argc - 1);
	return (array);
}

static void	order_stack_a(t_stack **stack, int *arr)
{
	t_stack *tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while(tmp)
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
}

static t_stack	*create_new_nod(void)
{
	t_stack	*new;

	new = (t_stack *)malloc((sizeof(t_stack)));
	if (!new)
		return (NULL);
	new->value = 0;
	new->order = 0;
	new->flag = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*create_stack_a(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	int		*arr;
	int		i;

	arr = make_arr(argc, argv);
	stack_a = create_new_nod();
	tmp = stack_a;
	i = 1;
	while (i < argc)
	{
		tmp->value = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			tmp->next = create_new_nod();
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		i++;
	}
	order_stack_a(&stack_a, arr);
	return (stack_a);
}
