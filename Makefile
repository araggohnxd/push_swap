NAME				= push_swap
NAME_BONUS			= checker

LIBFT				= ${LIBFT_PATH}/libft.a
LIBFT_PATH			= libft

HEADER_FILES		= push_swap.h checker_bonus.h
HEADER_PATH			= includes
HEADER				= ${addprefix ${HEADER_PATH}/, ${HEADER_FILES}}

SRC_PATH			= sources sources_bonus
SRC					= push_swap.c init_stack.c utils.c \
					sort_large_stack.c sort_tiny_stack.c \
					split_stack.c sorting_utils.c \
					linked_list.c linked_list_utils.c \
					print_operations.c operations.c

SRC_BONUS			= checker_bonus.c init_stack_bonus.c utils_bonus.c \
					linked_list_bonus.c linked_list_utils_bonus.c \
					exec_operations_bonus.c get_operations_bonus.c \
					operations_bonus.c

OBJ_PATH			= objects
OBJ					= ${SRC:%.c=${OBJ_PATH}/%.o}
OBJ_BONUS			= ${SRC_BONUS:%.c=${OBJ_PATH}/%.o}

CC					= cc -g3 -Wall -Wextra -Werror
REMOVE				= rm -rf

vpath %.c 			${SRC_PATH}

all:				${NAME}

${NAME}:			${OBJ} ${LIBFT}
					${CC} ${OBJ} ${LIBFT} -o $@

bonus:				${NAME_BONUS}

${NAME_BONUS}:		${OBJ_BONUS} ${LIBFT}
					${CC} ${OBJ_BONUS} ${LIBFT} -o $@

${OBJ_PATH}:
					mkdir -p $@

${OBJ_PATH}/%.o:	%.c ${HEADER} Makefile | ${OBJ_PATH}
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

.PHONY:				all clean fclean re bonus
