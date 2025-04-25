/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:02:34 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/28 22:24:26 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_push(t_stack *a, t_stack *b, int f1, int f2)
{
	ft_move_int_top_b(b, f1);
	ft_pa(a, b);
	ft_move_int_top_b(b, f2);
	ft_pa(a, b);
}

void	push_b_a(t_stack *a, t_stack *b)
{
	int	f1;
	int	f2;
	int	i;
	int	j;

	while (b->size)
	{
		f1 = biggest(b);
		f2 = biggest_next(b, f1);
		i = idx(b, f1);
		j = idx(b, f2);
		if (i > b->size / 2)
			i = b->size - i;
		if (j > b->size / 2)
			j = b->size - j;
		if (i < j)
			ft_move_push(a, b, f1, f2);
		else
			ft_move_push(a, b, f1, f2);
		if (a->stack[0] > a->stack[1])
			ft_sa(a);
	}
}

void	ft_algo(t_stack *a, t_stack *b, int opti)
{
	int	i;
	int	small;
	int	push;

	while (a->size)
	{
		push = 0;
		small = smallest(a);
		while (push++ < opti)
		{
			small = smallest_next(a, small);
			if (push == opti / 2)
				a->mid = small;
		}
		push = 0;
		while (push++ < opti)
		{
			i = ft_get_min_int_index(a, small);
			ft_move_int_top_a(a, a->stack[i]);
			ft_pb(a, b);
			if (b->stack[0] < a->mid)
				ft_rb(b);
		}
	}
	push_b_a(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (!a)
		return ;
	if (!ft_sorted(a) && a->size == 2)
		ft_sa(a);
	else if (a->size == 3)
		ft_sort_3(a);
	else if (a->size <= 5)
		ft_sort_4_5(a, b);
	else if (a->size <= 100)
		ft_algo(a, b, 20);
	else
		ft_algo(a, b, 50);
}
