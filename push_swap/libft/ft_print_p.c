/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:34:02 by mrocher           #+#    #+#             */
/*   Updated: 2023/12/08 16:38:27 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_p(void *ptr)
{
	int					len;
	unsigned long long	n;
	char				*hexa;

	len = 0;
	n = (unsigned long long)ptr;
	hexa = "0123456789abcdef";
	len += 2;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		ft_srchex(n, hexa);
		while (n > 0)
		{
			len++;
			n /= 16;
		}
	}
	return (len);
}
