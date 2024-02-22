/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operators_rr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:57:16 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/17 16:07:17 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	rotate_reverse(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	rotate_reverse(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
	ft_printf("rrr\n");
}

void	rotate_reverse(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	last = temp->next;
	last->next = *stack;
	temp->next = NULL;
	*stack = last;
	last = NULL;
	temp = NULL;
}
