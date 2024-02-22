/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:14:29 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/16 11:40:39 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	t_stack		*temp;
	t_stack		*ret;
	int			i;
	int			len;

	len = 0;
	i = 1;
	temp = stack;
	ret = temp;
	if (!stack)
		return ;
	len = ft_stack_size(temp);
	while (i <= len)
	{
		while (temp != NULL)
		{
			if ((temp->value < ret->value && temp->index == 0)
				|| (temp->index == 0 && ret->index != 0))
				ret = temp;
			temp = temp->next;
		}
		ret->index = i++;
		temp = stack;
		ret = temp;
	}
}

void	set_position(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	temp = stack;
	i = 1;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

int	find_target(t_stack *stack_a, int b_index, int target_index, int target_pos)
{
	t_stack	*temp_a;

	temp_a = stack_a;
	while (temp_a)
	{
		if (temp_a->index > b_index && temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	temp_a = stack_a;
	while (temp_a)
	{
		if (temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

void	set_target_position(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp_b;
	int		target_pos;
	int		i;

	temp_b = stack_b;
	i = 0;
	set_position(stack_a);
	set_position(stack_b);
	target_pos = 0;
	while (temp_b != NULL)
	{
		target_pos = find_target(stack_a, temp_b->index, INT_MAX, target_pos);
		temp_b->target_pos = target_pos;
		temp_b = temp_b->next;
	}
}

t_stack	*lower_index(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (stack)
	{
		if (stack->index < temp->index)
			temp = stack;
		stack = stack->next;
	}
	return (temp);
}
