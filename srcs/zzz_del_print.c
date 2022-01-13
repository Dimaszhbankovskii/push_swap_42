#include "../includes/push_swap.h"
#include <stdio.h>

void	print_struct_stack(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		printf("value = %d\n", tmp->value);
		printf("order = %d\n", tmp->order);
		printf("flag = %d\n", tmp->flag);
		printf("prev = %p\n", tmp->prev);
		printf("tmp = %p\n", tmp);
		printf("next = %p\n", tmp->next);
		printf("----------------------------------------\n");
		tmp = tmp->next;
	}
}

void	print_stack_A_B(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = *stack_a;
	printf("----------------- A: -------------------\n");
	while (tmp_a)
	{
		printf("%3d    order = %3d    flag = %3d\n", tmp_a->value, tmp_a->order, tmp_a->flag);
		tmp_a = tmp_a->next;
	}
	tmp_b = *stack_b;
	printf("----------------- B: -------------------\n");
	while (tmp_b)
	{
		printf("%3d    order = %3d    flag = %3d\n", tmp_b->value, tmp_b->order, tmp_b->flag);
		tmp_b = tmp_b->next;
	}
}

void	print_stack(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	printf("----------------- A: -------------------\n");
	while (tmp)
	{
		printf("%3d    order = %3d    flag = %3d\n", tmp->value, tmp->order, tmp->flag);
		tmp = tmp->next;
	}
}

void	print_struct_data(t_data *data)
{
	if (data)
	{
		printf("----------------  data  ----------------\n");
		printf("next = %d\n", data->next);
		printf("mid = %d\n", data->mid);
		printf("max = %d\n", data->max);
		printf("flag = %d\n", data->flag);
		printf("----------------------------------------\n");
	}
}

void	print_result(t_command **result)
{
	t_command	*tmp;

	tmp = *result;
	// printf("commands:\n");
	while (tmp)
	{
		if (tmp->command)
			printf("%s\n", tmp->command);
		tmp = tmp->next;
	}
}

void	print_struct_result(t_command **result)
{
	t_command	*tmp;

	tmp = *result;
	printf("commands:\n");
	while (tmp)
	{
		printf("command = ");
		if (tmp->command)
			printf("%s", tmp->command);
		printf("\nnext = %p\n", tmp->next);
		printf("tmp = %p\n", tmp);
		printf("prev = %p\n", tmp->prev);
		tmp = tmp->next;
	}
}
