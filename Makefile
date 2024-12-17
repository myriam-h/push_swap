NAME =      push_swap
INCLUDES =  ./
PRINTF =    ft_printf/libftprintf.a

CC =        gcc
CFLAGS =    -Wall -Wextra -Werror

SRCS = 		algo/ft_clean.c algo/push_swap.c algo/reverse_rotate_push.c algo/rotate_swap.c algo/sa_push_cost.c algo/sorting.c algo/stack_a_suite.c \
	        algo/stack_a.c algo/stack_b.c algo/top_process.c filling_stack/fill_stack.c filling_stack/ft_check.c \
	        libraries/ft_atoi.c libraries/ft_split.c libraries/ft_strjoin.c main.c \

OBJS =      $(SRCS:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS) $(PRINTF)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF)

$(PRINTF):  
			@make -C ./ft_printf

%.o:    	%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@make clean -C ./ft_printf		
			@rm -f $(OBJS)

fclean:     clean
			@make fclean -C ./ft_printf
			@rm -f $(NAME)

re:         fclean all

.PHONY:     all clean fclean re
