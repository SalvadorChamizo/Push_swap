/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:23:07 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/16 15:22:15 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	while_rrr(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost_a < 0 && temp->cost_b < 0)
	{
		rrr(stack_a, stack_b);
		temp->cost_a++;
		temp->cost_b++;
	}
	if (temp->cost_a == 0 && temp->cost_b != 0)
		rrb(stack_b);
	else
		rra(stack_a);
}

void	while_rra_2(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost_a < 0)
	{
		rra(stack_a);
		temp->cost_a++;
	}
	while_rb(stack_a, stack_b, temp);
}

void	while_rrb_2(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost_b < 0)
	{
		rrb(stack_b);
		temp->cost_b++;
	}
	while_ra(stack_a, stack_b, temp);
}

void	sort_current_node(t_stack **stack_a, t_stack **stack_b, t_stack *cur)
{
	t_stack	*temp;

	temp = *stack_b;
	while (temp != cur)
		temp = temp->next;
	if (temp->cost_a == 0 && temp->cost_b == 0)
		pa(stack_a, stack_b);
	else if (temp->cost_a > 0 && temp->cost_b == 0)
		while_ra(stack_a, stack_b, temp);
	else if (temp->cost_a < 0 && temp->cost_b == 0)
		while_rra(stack_a, stack_b, temp);
	else if (temp->cost_a == 0 && temp->cost_b > 0)
		while_rb(stack_a, stack_b, temp);
	else if (temp->cost_a == 0 && temp->cost_b < 0)
		while_rrb(stack_a, stack_b, temp);
	else if (temp->cost_a > 0 && temp->cost_b > 0)
		while_rr(stack_a, stack_b, temp);
	else if (temp->cost_a < 0 && temp->cost_b < 0)
		while_rrr(stack_a, stack_b, temp);
	else if (temp->cost_a < 0 && temp->cost_b > 0)
		while_rra_2(stack_a, stack_b, temp);
	else if (temp->cost_a > 0 && temp->cost_b < 0)
		while_rrb_2(stack_a, stack_b, temp);
}
