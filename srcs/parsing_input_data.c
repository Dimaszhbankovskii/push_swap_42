#include "../includes/push_swap.h"

int	len_arr_str(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static char	**dup_arr(char **arr, int len)
{
	char	**out;
	int		i;

	out = (char **)malloc(sizeof(char *) * (len + 1));
	if (!out)
        return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = ft_strdup(arr[i + 1]);
		if (!out[i])
		{
			free_arr_char(out);
			return (NULL);
		}
		i++;
	}
	out[i] = NULL;
	return (out);
}

char	**parsing_input_data(int argc, char **argv, t_main *inf)
{
	char	**arr;

	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = dup_arr(argv, argc - 1);
	if (!arr)
		exit(error_mess("Error: malloc 'inf->arr_char'\n", inf, 2));
	return (arr);
}
