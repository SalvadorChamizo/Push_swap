/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operators_ps.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:49 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/17 16:06:08 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *b;
	temp2 = temp->next;
	temp->next = *a;
	*a = temp;
	*b = temp2;
	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *a;
	temp2 = temp->next;
	temp->next = *b;
	*b = temp;
	*a = temp2;
	ft_printf("pb\n");
}

void	sa(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack;
	temp2 = temp->next;
	temp->next = temp2->next;
	temp2->next = temp;
	*stack = temp2;
	ft_printf("sa\n");
}

void	sb(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack;
	temp2 = temp->next;
	temp->next = temp2->next;
	temp2->next = temp;
	*stack = temp2;
	ft_printf("sb\n");
}
