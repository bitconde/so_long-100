/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsig_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:06:04 by mconde-s          #+#    #+#             */
/*   Updated: 2024/11/12 15:40:02 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr_unsig(unsigned int n)
{
	int				len;
	unsigned int	c;

	len = 0;
	if ((n > 9))
		len += ft_putnbr_unsig(n / 10);
	c = (n % 10) + '0';
	len++;
	write(1, &c, 1);
	return (len);
}

void	ft_unsig_num(va_list arg, int *count)
{
	unsigned int	n;
	int				len;

	n = va_arg(arg, unsigned int);
	len = ft_putnbr_unsig(n);
	*count += len;
}
