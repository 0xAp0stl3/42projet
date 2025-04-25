/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:14:14 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/28 22:33:56 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_smallest_top(t_stack *a)
{
	int	small;
	int	i;

	if (!a || !a->stack)
		return ;
	i = 0;
	small = smallest(a);
	while (a->stack[i] != small)
		i++;
	if (i <= lst_size(a) / 2)
	{
		while (a->stack[0] != small)
			ft_ra(a);
	}
	else
	{
		while (a->stack[0] != small)
			ft_rra(a);
	}
}

void	ft_move_biggest_top(t_stack *a)
{
	int	big;
	int	i;

	if (!a || !a->stack)
		return ;
	i = 0;
	big = biggest(a);
	while (a->stack[i] != big)
		i++;
	if (i < lst_size(a) / 2)
	{
		while (a->stack[0] != big)
			ft_ra(a);
	}
	else
	{
		while (a->stack[0] != big)
			ft_rra(a);
	}
}

void	ft_move_int_top_a(t_stack *a, int nbr)
{
	int	index;

	index = idx(a, nbr);
	if (index == -1)
		return ;
	if (index <= a->size / 2)
	{
		while (a->stack[0] != nbr)
			ft_ra(a);
	}
	else
	{
		while (a->stack[0] != nbr)
			ft_rra(a);
	}
}

void	ft_move_int_top_b(t_stack *b, int nbr)
{
	int	index;

	index = idx(b, nbr);
	if (index == -1)
		return ;
	if (index <= b->size / 2)
	{
		while (b->stack[0] != nbr)
			ft_rb(b);
	}
	else
	{
		while (b->stack[0] != nbr)
			ft_rrb(b);
	}
}
