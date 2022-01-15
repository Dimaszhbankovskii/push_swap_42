PUSH_SWAP			=	push_swap
CHECKER				=	checker

CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra
LIBRARIES			=	-L./libft -lft
INCLUDES			=	-I./includes

LIBFT				=	./libft/libft.a
HEADER				=	./includes/push_swap.h

SOURCES_DIR			=	srcs/
SOURCES_LIST_PS		=	push_swap.c \
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
SOURCES_CHECKER		=	$(addprefix $(SOURCES_DIR), $(SOURCES_LIST_CHECKER))

OBJECTS_DIR			=	objs/
OBJECTS_LIST_PS		=	${patsubst %.c, %.o, ${SOURCES_LIST_PS}}
OBJECTS_PS			=	$(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST_PS))

OBJECTS_LIST_CHECKER	=	${patsubst %.c, %.o, ${SOURCES_LIST_CHECKER}}
OBJECTS_CHECKER			=	$(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST_CHECKER))

all : ${PUSH_SWAP}

${PUSH_SWAP} : Makefile ${HEADER} ${LIBFT} $(OBJECTS_DIR) $(OBJECTS_PS) $(SOURCES_PS)
	@${CC} ${CFLAGS} ${OBJECTS_PS} -o ${PUSH_SWAP} ${LIBRARIES} ${INCLUDES}
	@echo "'${PUSH_SWAP}' was created"

$(LIBFT) : ./libft/Makefile ./libft/libft.h ./libft/*.c
	@$(MAKE) -C ./libft
	@$(MAKE) bonus -C ./libft
	@echo "libft was created"

$(addprefix $(OBJECTS_DIR), %.o) : $(addprefix $(SOURCES_DIR), %.c) $(OBJECTS_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDES)

$(OBJECTS_DIR) :
	@mkdir -p $@
	@echo "directory '$(OBJECTS_DIR)' was created"

bonus : ${CHECKER}

${CHECKER} : Makefile ${LIBFT} $(OBJECTS_CHECKER)
	@${CC} ${CFLAGS} ${OBJECTS_CHECKER} -o ${CHECKER} ${LIBRARIES} ${INCLUDES}
	@echo "'${CHECKER}' was created"

clean :
	@$(MAKE) fclean -C ./libft
	@rm -rf $(OBJECTS_DIR)
	@echo "command 'clean' was done"

fclean : clean
	@$(MAKE) fclean -C ./libft
	@rm -rf ${PUSH_SWAP} ${CHECKER}
	@echo "command 'fclean' was done"

re : fclean all
	@echo "command 're' was done."

.PHONY: all clean fclean re
