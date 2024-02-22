/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_while.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:22:43 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/16 12:23:52 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	while_ra(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost_a > 0)
	{
		ra(stack_a);
		temp->cost_a--;
	}
	pa(stack_a, stack_b);
}

void	while_rb(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost_b > 0)
	{
		rb(stack_b);
		temp->cost_b--;
	}
	pa(stack_a, stack_b);
}

void	while_rra(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost_a < 0)
	{
		rra(stack_a);
		temp->cost_a++;
	}
	pa(stack_a, stack_b);
}

void	while_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost_b < 0)
	{
		rrb(stack_b);
		temp->cost_b++;
	}
	pa(stack_a, stack_b);
}

void	while_rr(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost_a > 0 && temp->cost_b > 0)
	{
		rr(stack_a, stack_b);
		temp->cost_a--;
		temp->cost_b--;
	}
	if (temp->cost_a == 0 && temp->cost_b != 0)
		rb(stack_b);
	else
		ra(stack_a);
}
