/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:03:43 by mrocher           #+#    #+#             */
/*   Updated: 2023/10/11 17:01:46 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
		ft_putchar_fd('0', fd);
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (nb < 0 && nb != -2147483648)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb <= 9 && nb > 0)
		ft_putchar_fd(nb + '0', fd);
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
}
