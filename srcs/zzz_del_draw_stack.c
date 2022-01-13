#include "../includes/push_swap.h"

static void	ft_draw(int len)
{
	int	i;

	if (len < 10)
	{
		ft_putnbr_fd(len, 1);	// 1 символ
		ft_putstr_fd("   ", 1);	// 3 символа
	}
	else if (len >= 10 && len <= 99)
	{
		ft_putnbr_fd(len, 1);	// 2 символ
		ft_putstr_fd("  ", 1);	// 3 символа
	}
	else if (len >= 100 && len <= 999)
	{
		ft_putnbr_fd(len, 1);	// 3 символ
		ft_putstr_fd(" ", 1);	// 1 символа
	}
	i = 0;
	while (i < len)
	{
		ft_putchar_fd('-', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	ft_draw_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_draw(tmp->order);
		tmp = tmp->next;
	}
}
