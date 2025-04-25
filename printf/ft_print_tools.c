/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:34:26 by mrocher           #+#    #+#             */
/*   Updated: 2023/10/18 11:24:28 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_percent(void)
{
	ft_print_c('%');
	return (1);
}

void	ft_srchex(unsigned long long n, const char *hexa)
{
	if (n >= 16)
		ft_srchex(n / 16, hexa);
	ft_print_c(hexa[n % 16]);
}
