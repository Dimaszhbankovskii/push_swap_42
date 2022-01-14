#include "../includes/push_swap.h"

int	error_mess(char	*mess, t_main *inf, int num_error)
{
	ft_putstr_fd(mess, 1);
	free_inf(inf);
	return (num_error);
}
