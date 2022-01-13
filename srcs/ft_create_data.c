#include "../includes/push_swap.h"

void	update_data(t_data *data, t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp)
	{
		data->max = find_max_value_order(&tmp);
		data->mid = (data->max - data->next) / 2 + data->next;
		data->flag++;
	}
	*stack = tmp;
}

t_data	*create_struct_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->next = 1;
	data->mid = 0;
	data->max = 0;
	data->flag = 0;
	return (data);
}
