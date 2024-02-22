/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:46:03 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/22 16:43:11 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../src/push_swap.h"

/* Checker utils */

t_stack	*build_stack_a(char *str, int len);
void	*free_all(char **str, int cont);
int		is_sorted(t_stack **stack);

/* Checker list */

void	ft_stack_add_back(t_stack **lst, t_stack *new);
t_stack	*ft_stack_new_a(int value);
int		ft_stack_size(t_stack *lst);
void	ft_stack_clear(t_stack **stack);

/* Check operator ps */

void	pa_check(t_stack **a, t_stack **b);
void	pb_check(t_stack **b, t_stack **a);
void	sa_check(t_stack **stack);
void	sb_check(t_stack **stack);
void	ss_check(t_stack **stack_a, t_stack **stack_b);

/* Check operator r */

void	rr_check(t_stack **stack_a, t_stack **stack_b);
void	rotate_check(t_stack **stack);
void	rrr_check(t_stack **stack_a, t_stack **stack_b);
void	rotate_reverse_check(t_stack **stack);

#endif