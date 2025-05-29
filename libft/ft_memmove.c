/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:53:06 by bnespoli          #+#    #+#             */
/*   Updated: 2023/10/18 19:41:57 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temps;
	unsigned char	*tempd;

	if (!dest && !src)
		return (dest);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	temps = (unsigned char *)src;
	tempd = (unsigned char *)dest;
	while (n--)
		tempd[n] = temps[n];
	return (dest);
}
