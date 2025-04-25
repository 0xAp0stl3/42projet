/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:55:30 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/16 17:14:45 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		src_len;
	int		i;
	char	*src_cpy;

	src_len = ft_strlen(src);
	src_cpy = malloc(sizeof(char) * src_len + 1);
	if (!src_cpy)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		src_cpy[i] = src[i];
		i++;
	}
	src_cpy[i] = '\0';
	return (src_cpy);
}
