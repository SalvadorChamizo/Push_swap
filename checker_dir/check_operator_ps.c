/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator_ps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:41:17 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/22 18:27:14 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa_check(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (ft_stack_size(*b) >= 1)
	{
		temp = *b;
		temp2 = temp->next;
		temp->next = *a;
		*a = temp;
		*b = temp2;
	}
}

void	pb_check(t_stack **b, t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (ft_stack_size(*a) >= 1)
	{
		temp = *a;
		temp2 = temp->next;
		temp->next = *b;
		*b = temp;
		*a = temp2;
	}
}

void	sa_check(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (ft_stack_size(*stack) > 1)
	{
		temp = *stack;
		temp2 = temp->next;
		temp->next = temp2->next;
		temp2->next = temp;
		*stack = temp2;
	}
}

void	sb_check(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (ft_stack_size(*stack) > 1)
	{
		temp = *stack;
		temp2 = temp->next;
		temp->next = temp2->next;
		temp2->next = temp;
		*stack = temp2;
	}
}

void	ss_check(t_stack **stack_a, t_stack **stack_b)
{
	sb_check(stack_b);
	sa_check(stack_a);
}
