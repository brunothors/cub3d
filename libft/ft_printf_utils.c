/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:58:11 by bnespoli          #+#    #+#             */
/*   Updated: 2024/09/02 20:53:59 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putdigit(long long n, int base, int key)
{
	int	len;

	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putdigit(-n, base, key) + 1);
	}
	else if (n < base)
	{
		if (key == 1)
			return (ft_putchar(HEX_UP[n]));
		return (ft_putchar(HEX_LOW[n]));
	}
	else
	{
		len = ft_putdigit(n / base, base, key);
		return (len + ft_putdigit(n % base, base, key));
	}
}

int	ft_put_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr < 16)
		return (ft_putchar(HEX_LOW[ptr]));
	else
	{
		len = ft_put_ptr(ptr / 16);
		return (len + ft_put_ptr(ptr % 16));
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	else
	{
		len += write(1, "0x", 2);
		len += ft_put_ptr(ptr);
	}
	return (len);
}
