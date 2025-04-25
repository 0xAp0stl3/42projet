/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:02:54 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/28 22:33:21 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**verif;

	if (ac <= 1)
		return (0);
	ft_check_valid_args(ac, av);
	a = ft_calloc(1, sizeof(t_stack));
	if (!a)
		return (1);
	verif = process_args(ac, av, a);
	a->stack = process_verif(verif, a);
	b = ft_calloc(1, sizeof(t_stack));
	if (!b)
		ft_error(verif, a, a->stack);
	b->stack = ft_calloc(a->size + 1, sizeof(int));
	if (!b->stack)
		return (1);
	b->size = 0;
	if (!ft_sorted(a))
		push_swap(a, b);
	clear_stack(a, b);
	return (0);
}
