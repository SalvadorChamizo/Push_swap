/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:52:33 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/12 16:24:28 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current;
	int		len;

	current = stack;
	len = 0;
	while (current != NULL)
	{
		ft_printf("Valor: %d ", current->value);
		ft_printf("Índice: %d ", current->index);
		ft_printf("Posición: %d ", current->pos);
		ft_printf("Target: %d ", current->target_pos);
		ft_printf("Coste A: %d ", current->cost_a);
		ft_printf("Coste B: %d\n", current->cost_b);
		len++;
		current = current->next;
	}
	ft_printf("Tamaño del stack: %d\n", len);
}
