/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:01:08 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/28 22:33:29 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_free_join(char *dest, char *src)
{
	char	*tmp;

	tmp = ft_strjoin(dest, src);
	free(dest);
	return (tmp);
}

int	ft_int_tab_size(char *s)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (s[i] != ' ')
		counter++;
	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] && s[i + 1] != ' ')
			counter++;
		i++;
	}
	return (counter);
}

void	ft_good_order(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}

int	*process_verif(char **verif, t_stack *a)
{
	long	nbr;
	int		i;
	int		j;
	int		*tab;

	tab = ft_calloc((a->size + 1), sizeof(int));
	if (!tab)
		return (NULL);
	i = a->size - 1;
	j = 0;
	while (i >= 0)
	{
		nbr = ft_atol(verif[j++]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error(verif, a, tab);
		tab[i--] = (int) nbr;
	}
	if (ft_dup(tab, a))
		ft_error(verif, a, tab);
	i = 0;
	while (verif[i])
		free(verif[i++]);
	free(verif);
	ft_good_order(tab, a->size);
	return (tab);
}

char	**process_args(int ac, char **av, t_stack *stack)
{
	char	**verif;
	char	*s;
	int		i;

	i = 1;
	s = ft_calloc(1, sizeof(char));
	if (!s)
		return (NULL);
	while (i < ac)
	{
		s = ft_free_join(s, av[i]);
		if (i < ac - 1)
			s = ft_free_join(s, " ");
		i++;
	}
	stack->size = ft_int_tab_size(s);
	stack->max = ft_int_tab_size(s);
	verif = ft_split(s, ' ');
	free(s);
	return (verif);
}
