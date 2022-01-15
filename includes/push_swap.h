#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				order;
	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data
{
	int	next;
	int	mid;
	int max;
	int flag;
}					t_data;

typedef	struct s_command
{
	char				*command;
	struct s_command	*next;
	struct s_command	*prev;
}					t_command;

typedef struct s_main
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_data		*data;
	t_command	*result;
	char		**arr_char;
}				t_main;

char		**parsing_input_data(int argc, char **argv, t_main *inf);
int			input_validation(int len, char **arr);
t_stack		*create_stack_a(t_main *inf);
t_data		*create_struct_data(t_main *inf);
t_command	*create_new_result(t_main *inf);
void		update_output_result(t_main *inf);
char		*get_result(t_main *inf);
void		free_inf(t_main *inf);
void		free_arr_char(char **arr);
void		free_stack(t_stack **stack);

void		do_command(t_main *inf, char const *str);
void		write_command(t_main *inf, char const *str, int done);
int			sa_sb(t_stack **stack);
int			ss(t_stack **stack_a, t_stack **stack_b);
int			pa_pb(t_stack **stack_from, t_stack **stack_to);
int			ra_rb(t_stack **stack);
int			rr(t_stack **stack_a, t_stack **stack_b);
int			rra_rrb(t_stack **stack);
int			rrr(t_stack **stack_a, t_stack **stack_b);

void		private_sort(t_main *inf);
void		quick_sort(t_main *inf);
void		sort_half_stack_a(t_main *inf);
void		sort_move_b(t_main *inf);
void		update_data(t_data *data, t_stack **stack);

int			len_stack(t_stack **stack);
int			find_min_value_order(t_stack **stack);
int			find_max_value_order(t_stack **stack);
int			find_order(t_stack **stack, int order);
t_stack		*end_stack(t_stack **stack);
int			check_sort_stack(t_stack **stack);
int			count_unsort_stack_a(t_stack **stack);

int			check_sort_input_data(char **arr);
int			len_arr_str(char **arr);
int			error_mess(char	*mess, t_main *inf, int num_error);
void		print_result(char *res);

#endif