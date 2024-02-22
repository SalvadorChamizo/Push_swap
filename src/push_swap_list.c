/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:02:30 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/16 18:46:07 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = *lst;
	if (!last)
		*lst = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

t_stack	*ft_stack_new_a(int value)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	if (new)
	{
		new->value = value;
		new->next = NULL;
		new->index = 0;
	}
	return (new);
}

int	ft_stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	rotate_stack(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp->index != 1)
		temp = temp->next;
	if (temp->cost_b > 0)
	{
		while (temp->cost_b > 0)
		{
			ra(stack_a);
			temp->cost_b--;
		}
	}
	if (temp->cost_b < 0)
	{
		while (temp->cost_b < 0)
		{
			rra(stack_a);
			temp->cost_b++;
		}
	}
}
