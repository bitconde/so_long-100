/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:47:21 by mconde-s          #+#    #+#             */
/*   Updated: 2024/11/12 15:40:36 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(int n)
{
	size_t	len;
	char	c;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
		return (len);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	if ((n > 9))
		len += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	len++;
	write(1, &c, 1);
	return (len);
}

void	ft_num(va_list arg, int *count)
{
	int	n;
	int	len;

	n = va_arg(arg, int);
	len = ft_putnbr(n);
	*count += len;
}
