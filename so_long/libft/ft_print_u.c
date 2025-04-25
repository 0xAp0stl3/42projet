/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:34:50 by mrocher           #+#    #+#             */
/*   Updated: 2023/12/08 16:38:47 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_res(unsigned int n, int res)
{
	if (res == 0)
		ft_print_c('0' + n);
	else
	{
		print_res(n / 10, res - 1);
		ft_print_c('0' + (n % 10));
	}
}

int	ft_print_u(unsigned int n)
{
	int				len;
	unsigned int	temp;

	len = 0;
	if (n == 0)
	{
		ft_print_c('0');
		return (1);
	}
	temp = n;
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	print_res(n, len - 1);
	return (len);
}
