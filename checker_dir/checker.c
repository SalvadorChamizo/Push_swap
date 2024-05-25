/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:11:57 by schamizo          #+#    #+#             */
/*   Updated: 2024/05/25 18:18:10 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	do_operator(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		pa_check(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb_check(stack_b, stack_a);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa_check(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb_check(stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss_check(stack_a, stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate_check(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate_check(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr_check(stack_a, stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rotate_reverse_check(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rotate_reverse_check(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr_check(stack_a, stack_b);
	else
		error_exit();
	free(str);
}

t_stack	*build_stack_checker(int argc, char **argv, t_stack *stack_a)
{
	char	*string;
	int		i;

	string = NULL;
	i = 1;
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
	return (stack_a);
}

t_stack	*do_checker(t_stack **stack_a, t_stack **stack_b, char *operator)
{
	while (operator)
	{
		do_operator(stack_a, stack_b, operator);
		operator = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(stack_a) == 1 && ft_stack_size(*stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stack_clear(stack_b);
	ft_stack_clear(stack_a);
	return (*stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*operator;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		stack_a = build_stack_checker(argc, argv, stack_a);
		if (stack_a == NULL)
		{
			write(2, "Error\n", 6);
			ft_stack_clear(&stack_a);
			return (0);
		}
		operator = get_next_line(STDIN_FILENO);
		stack_a = do_checker(&stack_a, &stack_b, operator);
	}
	ft_stack_clear(&stack_a);
	return (0);
}
