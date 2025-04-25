/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:45:59 by mrocher           #+#    #+#             */
/*   Updated: 2023/10/03 14:18:32 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*str_d;
	size_t	i;

	i = 0;
	str_d = (char *)str;
	while (i < n)
	{
		str_d[i] = c;
		i++;
	}
	return (str);
}
