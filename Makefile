PUSH_SWAP				=	push_swap
CHECKER					=	checker

CC						=	gcc
CFLAGS					=	-Wall -Werror -Wextra
LIBRARIES				=	-L./libft -lft
INCLUDES				=	-I./includes

LIBFT					=	./libft/libft.a
HEADER					=	./includes/push_swap.h

SOURCES_DIR				=	srcs/
SOURCES_LIST_PS			=	push_swap.c \
							parsing_input_data.c \
							input_validation.c \
							create_stack_a.c \
							create_data.c \
							create_result.c \
							add_command.c \
							commands_1.c \
							commands_2.c \
							utils.c \
							utils_stack_1.c \
							utils_stack_2.c \
							private_sort.c \
							insert_sort_1.c \
							insert_sort_2.c \
							insert_sort_count_score.c \
							quick_sort.c \
							sort_half_stack_a_1.c \
							sort_half_stack_a_2.c \
							output_result.c \
							get_result.c \
							free_all.c
SOURCES_PS				=	$(addprefix $(SOURCES_DIR), $(SOURCES_LIST_PS))

SOURCES_LIST_CHECKER	=	checker.c \
							parsing_input_data.c \
							input_validation.c \
							create_stack_a.c \
							commands_1.c \
							commands_2.c \
							utils_stack_1.c \
							utils_stack_2.c \
							utils.c \
							free_all.c
SOURCES_CHECKER			=	$(addprefix $(SOURCES_DIR), $(SOURCES_LIST_CHECKER))

OBJECTS_LIST_PS			=	${patsubst %.c, %.o, ${SOURCES_LIST_PS}}

OBJECTS_LIST_CHECKER	=	${patsubst %.c, %.o, ${SOURCES_LIST_CHECKER}}

all : ${PUSH_SWAP}

${PUSH_SWAP} : Makefile $(HEADER) $(LIBFT) $(OBJECTS_LIST_PS)
	@${CC} ${CFLAGS} -o $@ ${OBJECTS_LIST_PS} ${LIBRARIES} ${INCLUDES}
	@printf "'${PUSH_SWAP}' was compiled\n"

$(LIBFT) : ./libft/Makefile ./libft/libft.h ./libft/*.c
	@make -C ./libft
	@make bonus -C ./libft
	@printf "libft was compiled\n"

%.o : $(addprefix $(SOURCES_DIR), %.c)
	$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDES)

bonus : ${CHECKER}

${CHECKER} : Makefile $(HEADER) ${LIBFT} $(OBJECTS_LIST_CHECKER)
	@${CC} ${CFLAGS} ${OBJECTS_LIST_CHECKER} -o ${CHECKER} ${LIBRARIES} ${INCLUDES}
	@printf "'${CHECKER}' was compiled\n"

clean :
	@make clean -C ./libft
	@rm -rf $(OBJECTS_LIST_PS) $(OBJECTS_LIST_CHECKER)
	@printf "command 'clean' was done\n"

fclean : clean
	@make fclean -C ./libft
	@rm -rf ${PUSH_SWAP} ${CHECKER}
	@printf "command 'fclean' was done\n"

re : fclean all
	@printf "command 're' was done\n"

.PHONY: all clean fclean re
