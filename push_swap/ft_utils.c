/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:13 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/28 22:33:08 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	free(stack_a);
	free(stack_b->stack);
	free(stack_b);
}

void	ft_error(char **verif, t_stack *stack, int *tab)
{
	int	i;

	i = 0;
	if (tab)
		free(tab);
	if (verif)
	{
		while (verif[i])
			free(verif[i++]);
		free(verif);
	}
	if (stack)
	{
		free(stack->stack);
		free(stack);
	}
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	ft_get_min_int_index(t_stack *stack, int min)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] <= min)
			break ;
		i++;
	}
	return (i);
}

int	lst_size(t_stack *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (len);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
