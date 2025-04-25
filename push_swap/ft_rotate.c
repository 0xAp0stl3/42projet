/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:58:44 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/28 22:32:45 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	else if (stack->size > 1)
	{
		tmp = stack->stack[0];
		ft_memmove(&stack->stack[0], &stack->stack[1],
			(stack->size - 1) * sizeof(int));
		stack->stack[stack->size - 1] = tmp;
	}
}

void	ft_ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
