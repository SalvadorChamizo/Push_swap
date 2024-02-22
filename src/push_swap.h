/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:41:59 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/22 16:36:47 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/src/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Push_swap */

void	*free_all(char **str, int cont);
int		is_sorted(t_stack **stack);
t_stack	*build_stack_a(char *str, int len);
void	push_swap(t_stack **stack_a);

/* Push_swap errors */

int		check_number(char *argv);
int		check_occurrences_str(char **argv);
int		check_occurrences_nbr(char **argv);
int		check_zeros(char *argv);
int		check_error(char **argv);

/* Push_swap_list */

void	ft_stack_add_back(t_stack **lst, t_stack *new);
t_stack	*ft_stack_new_a(int value);
int		ft_stack_size(t_stack *lst);
void	ft_stack_clear(t_stack **stack);
void	rotate_stack(t_stack **stack_a);

/* Push_swap_operators_ps */

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	sa(t_stack **stack);
void	sb(t_stack **stack);

/* Push_swap_operators_rs */

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);

/* Push_swap_operators_rr */

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rotate_reverse(t_stack **stack);

/* Push_swap_stack */

void	set_index(t_stack *stack);
void	set_position(t_stack *stack);
int		find_target(t_stack *stack_a, int b_index, int t_index, int t_pos);
void	set_target_position(t_stack *stack_a, t_stack *stack_b);
t_stack	*lower_index(t_stack *stack);

/* Push_swap_utils */

int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin_space(char *s1, char *s2);
int		count_words(const char *s, char c);
int		ft_abs(int nb);
t_stack	*check_cheapest(t_stack *stack);

/* Push_swap_sorting */

void	sort_three(t_stack **stack_a);
void	left_three(t_stack **stack_a, t_stack **stack_b, int len);
void	set_cost_a(t_stack *stack_b, t_stack *stack_a);
void	set_cost_b(t_stack *stack);
void	sort_more(t_stack **stack_a, t_stack **stack_b, int len);

/* Push_swap_sorting_node */

void	while_rrr(t_stack **stack_a, t_stack **stack_b, t_stack *temp);
void	while_rra_2(t_stack **stack_a, t_stack **stack_b, t_stack *temp);
void	while_rrb_2(t_stack **stack_a, t_stack **stack_b, t_stack *temp);
void	sort_current_node(t_stack **stack_a, t_stack **stack_b, t_stack *cur);

/* push_swap_while */

void	while_ra(t_stack **stack_a, t_stack **stack_b, t_stack *temp);
void	while_rb(t_stack **stack_a, t_stack **stack_b, t_stack *temp);
void	while_rra(t_stack **stack_a, t_stack **stack_b, t_stack *temp);
void	while_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *temp);
void	while_rr(t_stack **stack_a, t_stack **stack_b, t_stack *temp);

/* push_swap_print */

void	print_stack(t_stack *stack);

#endif