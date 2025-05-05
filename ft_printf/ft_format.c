/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:12:41 by mconde-s          #+#    #+#             */
/*   Updated: 2024/11/11 19:21:12 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char format, va_list arg, int *count)
{
	if (format == 'd' || format == 'i')
		ft_num(arg, count);
	else if (format == 'c')
		ft_char(arg, count);
	else if (format == 's')
		ft_str(arg, count);
	else if (format == '%')
	{
		ft_putchar(37);
		(*count)++;
	}
	else if (format == 'u')
		ft_unsig_num(arg, count);
	else if (format == 'x')
		ft_hexa_min((unsigned int)va_arg(arg, unsigned int), count);
	else if (format == 'X')
		ft_hexa_max((unsigned int)va_arg(arg, unsigned int), count);
	else if (format == 'p')
		ft_point(arg, count);
}
