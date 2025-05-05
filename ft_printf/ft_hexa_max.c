/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:56:26 by mconde-s          #+#    #+#             */
/*   Updated: 2024/11/11 19:11:14 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_max(unsigned long n, int *count)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (n >= 16)
		ft_hexa_max(n / 16, count);
	ft_putchar(hexa[n % 16]);
	(*count)++;
}
