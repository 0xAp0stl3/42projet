/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:58:42 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/28 22:23:08 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	else if (stack && stack->size > 1)
	{
		tmp = stack->stack[0];
		stack->stack[0] = stack->stack[1];
		stack->stack[1] = tmp;
	}
}

void	ft_sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
