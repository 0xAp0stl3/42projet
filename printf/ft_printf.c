/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:35:36 by mrocher           #+#    #+#             */
/*   Updated: 2023/10/18 11:23:58 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/*#include <stdio.h>

int main(void) 
{
    char c = 'd';
    int num = 42;
    char *str = "Hello, World!";
    void *ptr = (void *)0x12345678;
    int i = 0;
    int j = 0;
    
    i = printf("%s\n", "ensknvskvsknvskj");
    printf("Test int: %d\n", num);
    printf("Test str: %s\n", str);
    printf("Test pointeur: %p\n", ptr);
    printf("Test hexadecimal (lowercase): %x\n", num);
    printf("Test hexadecimal (uppercase): %X\n", num);
    printf("Test unsigned: %u\n", num);
    printf("Test pourcentage: %%\n");
    printf("Test Len C %d\n", i);


    j = printf("%s\n", "ensknvskvsknvskj");
    ft_printf("Resultat int: %d\n", num);
    ft_printf("Resultat str: %s\n", str);
    ft_printf("Resulat pointeur: %p\n", ptr);
    ft_printf("Resultat hexadecimal (lowercase): %x\n", num);
    ft_printf("Resultat hexadecimal (uppercase): %X\n", num);
    ft_printf("Resultat unsigned: %u\n", num);
    ft_printf("Resultat pourcentage: %%\n");
    printf("Res Len C %d\n", j);

    return (0);
}*/
