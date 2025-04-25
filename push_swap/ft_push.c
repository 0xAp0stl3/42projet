/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:58:02 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/28 22:30:24 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack *src, t_stack *dest)
{
	if (!src)
		return ;
	else if (src && src->size > 0)
	{
		ft_memmove(&dest->stack[1], &dest->stack[0],
			dest->size * sizeof(int));
		dest->stack[0] = src->stack[0];
		dest->size++;
		ft_memmove(&src->stack[0], &src->stack[1],
			(src->size - 1) * sizeof(int));
		src->size--;
	}
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
