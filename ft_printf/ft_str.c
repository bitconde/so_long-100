/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:12:33 by mconde-s          #+#    #+#             */
/*   Updated: 2025/04/19 12:19:06 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_printf(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_str(va_list arg, int *count)
{
	char	*str;
	int		len;

	str = (char *)va_arg(arg, const char *);
	len = ft_strlen_printf(str);
	if (str)
	{
		ft_putstr(str);
		*count += len;
	}
	else
	{
		write(1, "(null)", 6);
		*count += 6;
	}
}
