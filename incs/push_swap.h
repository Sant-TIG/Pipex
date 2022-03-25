/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:49:13 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/24 16:02:53 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pushswap
{
	int	stacka_len;
	int	stackb_len;
}	t_pushswap;

typedef struct s_stacks
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*pivot_index;
	t_stack		*pivot_nbr;
	t_stack		*nbrtmp;
	t_pushswap	*utils;
}	t_stacks;

/* CHECK FUNCTIONS */

int		ft_check_list(t_stack *stack_a, t_pushswap *utils);
int		ft_check_sorted(t_stack *stack_a);
int		ft_check_args(char **args);
int		ft_check_sorted_b(t_stack *stack_b);

/* MOVEMENTS FUNCTIONS */

void	ft_push_a(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate_a(t_stack **stack_a);
void	ft_reverse_rotate_b(t_stack **stack_b);
void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_swap_a(t_stack **stack_a);
void	ft_swap_b(t_stack **stack_b);
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b);

/* LINKED FUNCTIONS */

void	ft_copy_list(t_stack **tmp, t_stack *stack, int len);
void	ft_free_list(t_stack **stack, int len);
int		ft_quick_sort(t_stack **stack_a, int start, int end, t_stacks *stacks);
int		ft_listlen(t_stack *stack_a);
void	ft_insert_begin(int nbr, t_stack **stack);
void	ft_insert_empty(int nbr, t_stack **stack);
void	ft_insert_end(int nbr, t_stack **stack);
void	ft_insert_nbr(int nbr, int pos, t_stack **stack, int stack_len);

/* PRINT FUNCTIONS */

void	ft_print_args(char **args);
void	ft_print_list(t_stack *stack_a);

/* SORT FUNCTIONS */

void	ft_control_sort(t_stacks *stacks);
void	ft_sort_a(t_stacks *stacks, int len);
void	ft_sort_b(t_stacks *stacks, int len);
void	ft_treat_three_case(t_stack **stack_a);

/* UTILS FUNCTIONS */

int		ft_atoi(const char *str);
char	**ft_split(const char *str, char c);
size_t	ft_strlen(const char *str);
int		ft_digit_str(char *str);
int		ft_isdigit(int c);
void	ft_free_args(char **args);

#endif
