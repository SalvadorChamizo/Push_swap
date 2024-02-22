/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:36:32 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/19 15:50:38 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_swap(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (is_sorted(stack_a) == 0)
	{
		if (ft_stack_size(*stack_a) == 2)
			sa(stack_a);
		else if (ft_stack_size(*stack_a) == 3)
			sort_three(stack_a);
		else
			sort_more(stack_a, &stack_b, ft_stack_size(*stack_a));
	}
	ft_stack_clear(&stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*string;
	t_stack	*stack_a;

	i = 1;
	stack_a = NULL;
	string = NULL;
	if (argc == 2)
		stack_a = build_stack_a(argv[1], count_words(argv[1], ' '));
	else if (argc > 2)
	{
		while (i <= argc)
		{
			string = ft_strjoin_space(string, argv[i]);
			i++;
		}
		stack_a = build_stack_a(string, count_words(string, ' '));
		free(string);
	}
	if (stack_a == NULL && argc != 1)
		write(2, "Error\n", 6);
	else
		push_swap(&stack_a);
	ft_stack_clear(&stack_a);
	return (0);
}
