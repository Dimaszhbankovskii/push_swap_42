PUSH_SWAP			=	push_swap
CHECKER				=	checker

CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra
LIBRARIES			=	-L./libft -lft
INCLUDES			=	-I./includes

LIBFT				=	libft.a

SOURCES_DIR			=	srcs/
SOURCES_LIST		=	ft_push_swap.c \
						ft_input_validation.c \
						ft_create_stack_a.c \
						ft_create_data.c \
						ft_create_result.c \
						ft_add_command.c \
						ft_commands_1.c \
						ft_commands_2.c \
						ft_utils_stack.c \
						ft_private_sort.c \
						ft_big_sort.c \
						ft_big_sort_block_1.c \
						ft_big_sort_block_2.c \
						ft_special_sort.c \
						ft_output_result.c \
						ft_sort_3_b.c \
						ft_print_result.c \
						ft_free.c
SOURCES				=	$(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_DIR			=	objs/
OBJECTS_LIST		=	${patsubst %.c, %.o, ${SOURCES_LIST}}
OBJECTS				=	$(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

all : ${PUSH_SWAP}

${PUSH_SWAP} : Makefile $(LIBFT) $(OBJECTS)
	${CC} ${CFLAGS} ${OBJECTS} -o ${PUSH_SWAP} ${INCLUDES} ${LIBRARIES}
	@echo "'${PUSH_SWAP}' was created"

$(LIBFT) :
	@$(MAKE) -C ./libft
	@$(MAKE) bonus -C ./libft
	@echo "libft was created"

$(addprefix $(OBJECTS_DIR), %.o) : $(addprefix $(SOURCES_DIR), %.c) $(OBJECTS_DIR)
	$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDES)

$(OBJECTS_DIR) :
	@mkdir -p $@
	@echo "directory '$(OBJECTS_DIR)' was created"

clean :
	@$(MAKE) fclean -C ./libft
	rm -rf $(OBJECTS_DIR)
	@echo "command 'clean' was done"

fclean : clean
	@$(MAKE) fclean -C ./libft
	@rm -rf ${PUSH_SWAP}
	@echo "command 'fclean' was done"

re : fclean all
	@echo "command 're' was done."

.PHONY: all clean fclean re
