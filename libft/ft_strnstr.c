/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:03:09 by bnespoli          #+#    #+#             */
/*   Updated: 2023/10/24 15:11:32 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	if (*little == '\0')
		return ((char *)big);
	n = ft_strlen(little);
	while (*big && n <= len)
	{
		if (ft_strncmp(big, little, n) == 0)
			return ((char *)big);
		++big;
		--len;
	}
	return (NULL);
}
