S = srcs/


NAME = push_swap

SRCS =  $Spush_swap.c\
		$Sft_quick_sort.c\
		$Sft_control_sort.c $Sft_sort_a.c $Sft_sort_b.c $Sft_treat_three_case.c\
		$Sft_check_args.c $Sft_check_list.c $Sft_check_sorted.c $Sft_check_sorted_b.c\
		$Sft_push.c $Sft_rotate.c $S$Mft_reverse_rotate.c $Sft_swap.c\
		$Sft_listlen.c $Sft_insert_nbr.c $Sft_insert_empty.c $Sft_insert_end.c $Sft_insert_begin.c $Sft_copy_list.c $Sft_free_list.c\
		$Sft_digit_str.c $Sft_isdigit.c  $Sft_split.c $Sft_strlen.c $Sft_atoi.c $Sft_free_args.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS =  -Wall -Werror -Wextra #-fsanitize=address -g3

RM = -rm -rf

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re