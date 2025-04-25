/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:45:54 by mrocher           #+#    #+#             */
/*   Updated: 2023/10/03 14:34:36 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (n != i)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
