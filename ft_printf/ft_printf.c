/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:44:24 by mconde-s          #+#    #+#             */
/*   Updated: 2024/11/12 16:15:57 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	size_t	i;
	int		count;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != 0)
		{
			i++;
			ft_format(str[i], arg, &count);
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
// int main()
// {
// 	int r1;
// 	int r2;
// 	char str[] = "Hello";
// 	char str2[] = "There";
// 	char c;
// 	char c2;
// 	int n;
// 	int n2;

// 	n = 123;
// 	n2 = -13;
// 	c = 'A';
// 	c2 = 'b';

// 	r1 = ft_printf("%d\n",__INT_MAX__);
// 	r2 = printf("%d\n",__INT_MAX__);
// 	printf("%d - %d\n\n",r1,r2);

// 	r1 = ft_printf("%d\n",INT_MIN);
// 	r2 = printf("%d\n",INT_MIN);
// 	printf("%d - %d\n\n",r1,r2);

// 	r1 = ft_printf("%d\n",-42);
// 	r2 = printf("%d\n",-42);
// 	printf("%d - %d\n\n",r1,r2);

// 	printf("%i %d\n", n, n2);
// 	ft_printf("%i %d\n\n", n, n2);

// 	printf("%c\n", c2);
// 	ft_printf("%c\n\n", c2);

// 	printf("%s %s\n", str, str2);
// 	ft_printf("%s %s\n\n", str, str2);

// 	printf("%%\n");
// 	ft_printf("%%\n\n");

// 	printf("%u %u\n", n, n2);
// 	ft_printf("%u %u\n\n", n, n2);

// 	printf("%x %X\n", n, n);
// 	ft_printf("%x %X\n\n", n, n);

// 	printf("%p %p\n", str, str2);
// 	ft_printf("%p %p\n\n", str, str2);

// 	printf("%i %d %u %s %p %x %X\n", -2147483648, 2147483649, -1, 0, 0, 0, 0,
// 		0);
// 	ft_printf("%i %d %u %s %p %x %X\n\n", -2147483648, 2147483649, -1, 0, 0, 0,
// 	0, 0);

// 	return (0);
// }