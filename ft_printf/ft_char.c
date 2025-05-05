/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:39:33 by mconde-s          #+#    #+#             */
/*   Updated: 2024/11/11 18:32:15 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_char(va_list arg, int *count)
{
	unsigned char	c;

	c = (unsigned char)va_arg(arg, int);
	ft_putchar(c);
	(*count)++;
}
