/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:16:20 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/17 15:18:49 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
	{
		i++;
		if (argv[i] == '0' || argv[i] == '\0')
			return (0);
	}
	while (argv[i] >= '0' && argv[i] <= '9')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	check_occurrences_str(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[j])
	{
		while (argv[i])
		{
			if (ft_strcmp(argv[j], argv[i]) == 0)
				return (0);
			i++;
		}
		j++;
		i = j + 1;
	}
	return (1);
}

int	check_occurrences_nbr(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[j])
	{
		while (argv[i])
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (0);
			i++;
		}
		if (ft_atoi(argv[j]) > INT_MAX || ft_atoi(argv[j]) < -2147483648)
			return (0);
		j++;
		i = j + 1;
	}
	return (1);
}

int	check_zeros(char *argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = -1;
	while (argv[i])
	{
		if (argv[i] != '0' && flag == -1)
			flag = 1;
		if (argv[i] == '0' && flag == -1 && argv[i + 1] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	check_error(char **argv)
{
	int	i;

	i = 0;
	if (check_occurrences_str(argv) == 0)
		return (0);
	if (check_occurrences_nbr(argv) == 0)
		return (0);
	while (argv[i])
	{
		if (check_number(argv[i]) == 0)
			return (0);
		if (check_zeros(argv[i]) == 0)
			return (0);
		if (ft_strlen(argv[i]) > 11)
			return (0);
		i++;
	}
	return (1);
}
