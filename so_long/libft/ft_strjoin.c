/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:36:29 by mrocher           #+#    #+#             */
/*   Updated: 2023/10/03 16:26:38 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	if (result != NULL)
	{
		while (*s1 != '\0')
		{
			result[i] = *s1;
			i++;
			s1++;
		}
		while (*s2 != '\0')
		{
			result[i] = *s2;
			i++;
			s2++;
		}
		result[i] = '\0';
	}
	return (result);
}
