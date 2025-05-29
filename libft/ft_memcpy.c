/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:05:41 by bnespoli          #+#    #+#             */
/*   Updated: 2023/10/18 19:42:26 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*altd;
	unsigned char	*alts;

	if (!dest && !src)
		return (dest);
	altd = (unsigned char *)dest;
	alts = (unsigned char *)src;
	while (n > 0)
	{
		*altd++ = *alts++;
		n--;
	}
	return (dest);
}
