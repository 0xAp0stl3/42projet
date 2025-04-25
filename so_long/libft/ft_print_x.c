/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:35:12 by mrocher           #+#    #+#             */
/*   Updated: 2023/12/08 16:38:54 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_x(unsigned int n, int format)
{
	int		len;
	char	*hexa;

	len = 0;
	if (n == 0)
	{
		ft_print_c('0');
		return (1);
	}
	if (format == 'X')
		hexa = "0123456789ABCDEF";
	if (format == 'x')
		hexa = "0123456789abcdef";
	ft_srchex(n, hexa);
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}
