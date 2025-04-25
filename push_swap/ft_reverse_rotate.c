/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:58:47 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/28 22:32:42 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	else if (stack && stack->size > 1)
	{
		tmp = stack->stack[stack->size - 1];
		ft_memmove(&stack->stack[1], &stack->stack[0],
			(stack->size - 1) * sizeof(int));
		stack->stack[0] = tmp;
	}
}

void	ft_rra(t_stack *stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack *stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
