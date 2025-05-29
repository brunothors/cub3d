/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:57:34 by bnespoli          #+#    #+#             */
/*   Updated: 2024/09/02 20:53:48 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_read_flag(const char format, va_list args)
{
	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_putdigit(va_arg(args, int), 10, 0));
	else if (format == 'u')
		return (ft_putdigit(va_arg(args, unsigned int), 10, 0));
	else if (format == 'x')
		return (ft_putdigit(va_arg(args, unsigned int), 16, 0));
	else if (format == 'X')
		return (ft_putdigit(va_arg(args, unsigned int), 16, 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
			len += ft_read_flag(*(++format), args);
		else
			len += ft_putchar(*format);
		++format;
	}
	va_end(args);
	return (len);
}
