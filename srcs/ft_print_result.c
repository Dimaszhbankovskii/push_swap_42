#include "../includes/push_swap.h"

void	print_result(t_command **result)
{
	t_command	*tmp;

	tmp = *result;
	while (tmp->command)
	{
		ft_putstr_fd(tmp->command, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}

char	*make_str(char *s1, char *s2)
{
	char	*str1;
	char	*str2;

	if (s1)
	{
		str1 = ft_strjoin(s1, "\n");
		free (s1);
	}
	else
		str1 = s1;
	str2 = ft_strjoin(str1, s2);
	free (str1);
	return (str2);
}

char	*list_to_str(t_command **result)
{
	char		*str;
	t_command	*tmp;

	tmp = *result;
	str = NULL;
	while (tmp->command)
	{
		str = make_str(str, tmp->command);
		tmp = tmp->next;
	}
	return (str);
}
