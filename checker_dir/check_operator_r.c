/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:43:24 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/22 18:26:57 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rr_check(t_stack **stack_a, t_stack **stack_b)
{
	rotate_check(stack_a);
	rotate_check(stack_b);
}

void	rotate_check(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (ft_stack_size(*stack) > 1)
	{
		temp = *stack;
		temp2 = temp;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = temp;
		*stack = (*stack)->next;
		temp->next = NULL;
	}
}

void	rrr_check(t_stack **stack_a, t_stack **stack_b)
{
	rotate_reverse_check(stack_a);
	rotate_reverse_check(stack_b);
}

void	rotate_reverse_check(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack;
	if (ft_stack_size(*stack) > 1)
	{
		while (temp->next->next != NULL)
			temp = temp->next;
		last = temp->next;
		last->next = *stack;
		temp->next = NULL;
		*stack = last;
		last = NULL;
		temp = NULL;
	}
}
