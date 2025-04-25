/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:46:33 by mrocher           #+#    #+#             */
/*   Updated: 2023/10/11 12:58:02 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *s, char c)
{
	int	word;
	int	count;

	word = 0;
	count = 0;
	while (*s)
	{
		if (*s != 0 && word == '\0')
		{
			count++;
			word = 1;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

static char	*word(const char *s, int start, int end)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**result;
	int		start;
	int		end;

	result = malloc(sizeof(char *) * (count(s, c) + 1));
	if (!s || !result)
		return (NULL);
	i = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] != c)
		{
			start = end;
			while (s[end] && s[end] != c)
				end++;
			result[i++] = word(s, start, end);
		}
		else
			end++;
	}
	result[i] = NULL;
	return (result);
}
