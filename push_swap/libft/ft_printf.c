/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:35:36 by mrocher           #+#    #+#             */
/*   Updated: 2023/12/08 16:38:59 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_search_format(va_list args, const char *format)
{
	int	ptr;

	ptr = 0;
	if (*format == 'c')
		ptr += ft_print_c(va_arg(args, int));
	else if (*format == 's')
		ptr += ft_print_s(va_arg(args, char *));
	else if (*format == 'p')
		ptr += ft_print_p(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		ptr += ft_print_nbr(va_arg(args, int));
	else if (*format == 'u')
		ptr += ft_print_u(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
	{
		if (*format == 'x')
			ptr += ft_print_x(va_arg(args, unsigned int), 'x');
		if (*format == 'X')
			ptr += ft_print_x(va_arg(args, unsigned int), 'X');
	}
	else if (*format == '%')
		ptr += ft_print_percent();
	return (ptr);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ptr;

	ptr = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ptr += ft_search_format(args, format);
		}
		else
		{
			ft_print_c(*format);
			ptr++;
		}
		format++;
	}
	va_end(args);
	return (ptr);
}
