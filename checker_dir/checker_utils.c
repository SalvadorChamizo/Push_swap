/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:31:18 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/19 18:34:33 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*build_stack_a(char *str, int len)
{
	t_stack	*stack_a;
	t_stack	*temp;
	char	**split;
	int		i;

	stack_a = NULL;
	i = 0;
	split = ft_split(str, ' ');
	if (!split)
		return (NULL);
	if (check_error(split) == 0)
	{
		free_all(split, count_words(str, ' ') + 1);
		return (stack_a);
	}
	while (i < len)
	{
		temp = ft_stack_new_a(ft_atoi(split[i]));
		ft_stack_add_back(&stack_a, temp);
		i++;
	}
	free_all(split, count_words(str, ' ') + 1);
	set_index(stack_a);
	return (stack_a);
}

void	*free_all(char **str, int cont)
{
	int	i;

	i = 0;
	while (i < cont)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp == NULL)
		return (1);
	while (temp->next)
	{
		if (temp->value < temp->next->value)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}
