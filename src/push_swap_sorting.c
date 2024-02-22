/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:11:55 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/17 16:10:54 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	if ((temp->index > temp->next->index)
		&& (temp->index > temp->next->next->index))
		ra(stack_a);
	temp = *stack_a;
	if ((temp->next->index > temp->index)
		&& (temp->next->index > temp->next->next->index))
		rra(stack_a);
	temp = *stack_a;
	if (temp->index > temp->next->index)
		sa(stack_a);
}

void	left_three(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	cont;
	int	i;

	i = len / 2;
	if (len == 4)
	{
		while (*stack_a != lower_index(*stack_a))
			ra(stack_a);
		pb(stack_b, stack_a);
		return ;
	}
	while (i)
	{
		if ((*stack_a)->index <= len / 2)
		{
			pb(stack_b, stack_a);
			i--;
		}
		else
			ra(stack_a);
	}
	cont = ft_stack_size(*stack_b);
	while (len - cont++ > 3)
		pb(stack_b, stack_a);
}

void	set_cost_a(t_stack *stack_b, t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack_b;
	temp2 = stack_a;
	while (temp)
	{
		set_position(stack_a);
		set_cost_b(stack_a);
		while (temp->target_pos != (stack_a)->pos)
			stack_a = stack_a->next;
		temp->cost_a = stack_a->cost_b;
		stack_a = temp2;
		temp = temp->next;
	}
}

void	set_cost_b(t_stack *stack)
{
	t_stack	*temp;
	int		middle;
	int		len;
	int		i;

	temp = stack;
	len = ft_stack_size(stack);
	middle = (len / 2) + 1;
	i = 0;
	while (temp)
	{
		if (temp->pos <= middle)
			temp->cost_b = i;
		i++;
		temp = temp->next;
	}
	while (stack)
	{
		if (stack->pos > middle)
		{
			stack->cost_b = middle - len;
			len--;
		}
		stack = stack->next;
	}
}

void	sort_more(t_stack **stack_a, t_stack **stack_b, int len)
{
	left_three(stack_a, stack_b, len);
	sort_three(stack_a);
	while (*stack_b)
	{
		if (ft_stack_size(*stack_b) == 2 && is_sorted(stack_b))
			rb(stack_b);
		set_target_position(*stack_a, *stack_b);
		set_cost_b(*stack_b);
		set_cost_a(*stack_b, *stack_a);
		sort_current_node(stack_a, stack_b, check_cheapest(*stack_b));
	}
	if ((*stack_a)->index != 1)
	{
		set_position(*stack_a);
		set_cost_b(*stack_a);
		rotate_stack(stack_a);
	}
}
