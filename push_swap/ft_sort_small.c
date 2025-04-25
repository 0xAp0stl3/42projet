/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:01:35 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/28 22:33:17 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	if (a == NULL)
		return ;
	top = a->stack[0];
	mid = a->stack[1];
	bottom = a->stack[2];
	if (top > mid && bottom > mid && bottom > top)
		ft_sa(a);
	else if (top > mid && mid > bottom && top > bottom)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (top > mid && bottom > mid && top > bottom)
		ft_ra(a);
	else if (mid > top && mid > bottom && bottom > top)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (mid > top && mid > bottom && bottom < top)
		ft_rra(a);
}

void	ft_sort_4_5(t_stack *a, t_stack *b)
{
	if (ft_sorted(a))
		return ;
	while (a->size > 3)
	{
		ft_move_smallest_top(a);
		ft_pb(a, b);
	}
	ft_sort_3(a);
	while (b->size > 0)
		ft_pa(a, b);
}
