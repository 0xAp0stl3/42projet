/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:03:29 by mrocher           #+#    #+#             */
/*   Updated: 2023/10/11 12:18:55 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	itoa_nbr(int nbr)
{
	long	size;

	size = 0;
	if (nbr == 0)
		return (1);
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		size++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		size++;
		nbr /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str_nbr;
	long	len;
	long	i;

	len = itoa_nbr(n);
	str_nbr = malloc(sizeof(char) * (len + 1));
	if (str_nbr == NULL)
		return (NULL);
	str_nbr[len] = '\0';
	i = n;
	if (i < 0)
	{
		str_nbr[0] = '-';
		i = -i;
	}
	if (i == 0)
		str_nbr[--len] = '0';
	while (i > 0)
	{
		str_nbr[--len] = (i % 10) + '0';
		i /= 10;
	}
	return (str_nbr);
}
