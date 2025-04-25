/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:22:34 by mrocher           #+#    #+#             */
/*   Updated: 2023/10/11 12:22:36 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		ca;

	s = (const unsigned char *)str;
	ca = (unsigned char)c;
	i = 0;
	while (n != i)
	{
		if (s[i] == ca)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
