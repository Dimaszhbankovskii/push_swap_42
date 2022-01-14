#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

//delete
// # include <stdio.h>

typedef struct		s_stack
{
	int				value;  // значение элемента в стеке
	int				order;  // порядок элемента в отсортированном стеке
	int				flag;	// флаг, что элемент был в стеке В, увеличивается на 1, изначально 0
	struct s_stack	*next;  // следующий элемент связанного списка
	struct s_stack	*prev;  // предыдущий элемент связанного списка
}					t_stack;

typedef struct		s_data
{
	int	next;	// порядок элемента, который надо отсортировать (сначала 1)
	int	mid;
	int max;
	int flag;
}					t_data;

typedef	struct		s_command
{
	char				*command;	// название команды
	struct s_command	*next;		// следующая команда
	struct s_command	*prev;		// предыдущая команда
}					t_command;

typedef struct s_main
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_data		*data;
	t_command	*result;
	char		**arr_char;
}				t_main;

char		**parsing_input_data(int argc, char **argv, t_main *inf);	// +

int			input_validation(int len, char **arr); // +

t_stack		*create_stack_a(t_main *inf);	// +

t_data		*create_struct_data(t_main *inf);

t_command	*create_new_result(t_main *inf);

void		update_data(t_data *data, t_stack **stack);
void		update_output_result(t_command **result);
void		print_result(t_command **result);
t_main		*free_all(t_main *inf);

void		free_inf(t_main *inf); // +
void		free_arr_char(char **arr);
void		free_stack(t_stack **stack);
int			error_mess(char	*mess, t_main *inf, int num_error); // +

int			check_sort_input_data(char **arr); // +

//--------- commands ----------------------
void		do_command(t_main *inf, char const *str);
void		write_command(t_main *inf, char const *str, int done);
int			sa_sb(t_stack **stack);
int			ss(t_stack **stack_a, t_stack **stack_b);
int			pa_pb(t_stack **stack_from, t_stack **stack_to);
int			ra_rb(t_stack **stack);
int			rr(t_stack **stack_a, t_stack **stack_b);
int			rra_rrb(t_stack **stack);
int			rrr(t_stack **stack_a, t_stack **stack_b);
//-----------------------------------------
//--------- quick sort --------------------


void		private_sort(t_main *inf);


//-----------------------------------------
//--------- quick sort ----------------------
void		quick_sort(t_main *inf);
void		sort_half_stack_a(t_main *inf);
void		sort_move_b(t_main *inf);

//---------- utils stack -------------------
int			len_stack(t_stack **stack);
int			find_min_value_order(t_stack **stack);
int			find_max_value_order(t_stack **stack);
int			find_order(t_stack **stack, int order);
t_stack		*end_stack(t_stack **stack);
int			check_sort_stack(t_stack **stack);
int			count_unsort_stack_a(t_stack **stack);



int			len_arr_str(char **arr); // +


int			ft_count_commands(t_command **result);

//-----------------------------------------
int			ft_strcmp(char const *str1, char const *str2);
void		print_result(t_command **result);

char		*list_to_str(t_command **result);


//---------------------
void	print_struct_stack(t_stack **stack);	// печать структуры стека
void	print_struct_data(t_data *data);	// печать структуры данных
void	print_stack_A_B(t_stack **stack_a, t_stack **stack_b);
void	print_stack(t_stack **stack);
void	print_struct_result(t_command **result);
//---------------------
void	ft_draw_stack(t_stack **stack);
//---------------------
#endif