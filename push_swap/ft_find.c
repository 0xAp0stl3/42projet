/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:40 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/28 22:32:38 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	idx(t_stack *stack, int nbr)
{
	int	index;

	index = 0;
	if (stack == NULL || stack->size == 0)
		return (-1);
	while (index < stack->size)
	{
		if (stack->stack[index] == nbr)
			return (index);
		index++;
	}
	return (-1);
}

int	biggest(t_stack *stack)
{
	int	i;
	int	max;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	max = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

int	smallest(t_stack *stack)
{
	int	i;
	int	min;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	min = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int	biggest_next(t_stack *stack, int big)
{
	int	next;
	int	i;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	next = INT_MIN;
	while (i < stack->size)
	{
		if (stack->stack[i] > next && stack->stack[i] < big)
			next = stack->stack[i];
		i++;
	}
	return (next);
}

int	smallest_next(t_stack *stack, int small)
{
	int	next;
	int	i;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	next = INT_MAX;
	while (i < stack->size)
	{
		if (stack->stack[i] > small && stack->stack[i] < next)
			next = stack->stack[i];
		i++;
	}
	return (next);
}
