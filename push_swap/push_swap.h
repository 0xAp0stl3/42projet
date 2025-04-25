/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:55:58 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/25 15:12:52 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

typedef struct s_stack
{
	int				*stack;
	int				size;
	int				max;
	int				mid;
	struct s_stack	*next;
}	t_stack;

/* Commands */
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_b);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);
void	ft_ra(t_stack *stack_a);
void	ft_rb(t_stack *stack_b);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_rra(t_stack *stack_a);
void	ft_rrb(t_stack *stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

/* Algo */
void	reduceprint(char *a);
void	ft_move_push(t_stack *a, t_stack *b, int f1, int f2);
void	push_b_a(t_stack *a, t_stack *b);
void	ft_algo(t_stack *a, t_stack *b, int opti);
void	push_swap(t_stack *a, t_stack *b);

/* Check */
int		ft_sorted(t_stack *stack);
int		ft_dup(int *tab, t_stack *a);
int		ft_check_valid_args(int ac, char **av);

/* Find */
int		idx(t_stack *stack, int nbr);
int		biggest(t_stack *stack);
int		smallest(t_stack *stack);
int		biggest_next(t_stack *stack, int big);
int		smallest_next(t_stack *stack, int small);

/* Part */
char	*ft_free_join(char *dest, char *src);
int		ft_int_tab_size(char *s);
void	ft_good_order(int *tab, int len);
int		*process_verif(char **verif, t_stack *a);
char	**process_args(int ac, char **av, t_stack *stack);

/* Small */
void	ft_sort_3(t_stack *a);
void	ft_sort_4_5(t_stack *a, t_stack *b);

/* Utils */
void	clear_stack(t_stack *stack_a, t_stack *stack_b);
void	ft_error(char **verif, t_stack *stack, int *tab);
long	ft_atol(const char *str);
int		ft_get_min_int_index(t_stack *stack, int min);
int		lst_size(t_stack *stack);
void	cleanup_last(void);

/* Move */
void	ft_move_smallest_top(t_stack *a);
void	ft_move_biggest_top(t_stack *a);
void	ft_move_int_top_a(t_stack *a, int nbr);
void	ft_move_int_top_b(t_stack *b, int nbr);

#endif