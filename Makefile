NAME				= push_swap

LIBFT				= ${LIBFT_PATH}/libft.a
LIBFT_PATH			= libft

HEADER_FILES		= push_swap.h
HEADER_PATH			= includes
HEADER				= ${addprefix ${HEADER_PATH}/, ${HEADER_FILES}}

SRC_FILES			= push_swap.c utils.c operations.c \
					linked_list.c linked_list_utils.c sort_stacks.c \
					lookup_table.c split_stack.c sorting_utils.c \
					init_stack.c print_operations.c
SRC_PATH			= sources
SRC					= ${addprefix ${SRC_PATH}/, ${SRC_FILES}}

OBJ_PATH			= objects
OBJ					= ${SRC_FILES:%.c=${OBJ_PATH}/%.o}

CC					= cc -g3 -Wall -Wextra -Werror
REMOVE				= rm -rf

all:				${NAME}

${NAME}:			${OBJ} ${LIBFT}
					${CC} ${OBJ} ${LIBFT} -o ${NAME}

${OBJ_PATH}:
					mkdir -p $@

${OBJ_PATH}/%.o:	${SRC_PATH}/%.c ${HEADER} Makefile | ${OBJ_PATH}
					${CC} -I ${HEADER_PATH} -c $< -o $@

${LIBFT}:
					${MAKE} -C ${LIBFT_PATH} bonus

clean:
					${REMOVE} ${OBJ_PATH}
					${MAKE} -C ${LIBFT_PATH} clean

fclean:				clean
					${REMOVE} ${NAME}
					${MAKE} -C ${LIBFT_PATH} fclean

re:					fclean all

.PHONY:				all clean fclean re
