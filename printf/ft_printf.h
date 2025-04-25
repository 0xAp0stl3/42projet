/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:35:56 by mrocher           #+#    #+#             */
/*   Updated: 2023/10/18 11:21:35 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_print_c(char c);
int		ft_print_percent(void);
void	ft_srchex(unsigned long long n, const char *hexa);
int		ft_print_p(void *ptr);
int		ft_print_u(unsigned int n);
int		ft_print_nbr(int n);
int		ft_print_x(unsigned int n, int format);
int		ft_printf(const char *format, ...);
int		ft_print_s(char *str);

#endif