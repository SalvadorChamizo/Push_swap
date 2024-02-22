/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:37:32 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/16 18:53:17 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_space(char *s1, char *s2)
{
	char	*s3;
	char	*p;
	size_t	len1;
	size_t	len2;
	int		i;

	len1 = 0;
	len2 = 0;
	i = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	s3 = malloc(len1 + len2 + 2);
	if (s3 == NULL)
		return (NULL);
	p = s3;
	while (len1--)
		*p++ = s1[i++];
	*p++ = ' ';
	while (len2--)
		*p++ = *s2++;
	*p = '\0';
	free(s1);
	return (s3);
}

int	count_words(const char *s, char c)
{
	int	cont;
	int	check;

	cont = 0;
	check = 0;
	while (*s)
	{
		if (*s != c && check == 0)
		{
			cont++;
			check = 1;
		}
		else if (*s == c)
			check = 0;
		s++;
	}
	return (cont);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

t_stack	*check_cheapest(t_stack *stack)
{
	t_stack	*temp;
	int		nb;

	temp = stack;
	nb = ft_abs(stack->cost_a) + ft_abs(stack->cost_b);
	while (stack != NULL)
	{
		if (nb > (ft_abs(stack->cost_a) + ft_abs(stack->cost_b)))
		{
			nb = ft_abs(stack->cost_a) + ft_abs(stack->cost_b);
			temp = stack;
		}
		stack = stack->next;
	}
	return (temp);
}
