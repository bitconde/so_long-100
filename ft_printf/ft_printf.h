/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:14:12 by mconde-s          #+#    #+#             */
/*   Updated: 2025/04/19 12:12:53 by mconde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int				ft_printf(char const *str, ...);
void			ft_format(const char format, va_list arg, int *count);
void			ft_char(va_list arg, int *count);
void			ft_str(va_list arg, int *count);
void			ft_unsig_num(va_list arg, int *count);
void			ft_hexa_max(unsigned long n, int *count);
void			ft_hexa_min(unsigned long n, int *count);
void			ft_num(va_list arg, int *count);
void			ft_point(va_list arg, int *count);

void			ft_putchar(int c);
size_t			ft_putnbr(int n);
void			ft_putstr(char *str);
size_t			ft_strlen_printf(char *str);
unsigned int	ft_putnbr_unsig(unsigned int n);

#endif
