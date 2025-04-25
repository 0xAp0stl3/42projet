/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:29:50 by mrocher           #+#    #+#             */
/*   Updated: 2023/10/11 10:02:37 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search_char(char str, char const *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == str)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*result;

	start = 0;
	while (s1[start] && search_char(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while ((end > start && search_char(s1[end - 1], set)))
		end--;
	result = malloc(sizeof(char) * (end - start + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		result[i] = s1[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
