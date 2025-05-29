/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:17:04 by bnespoli          #+#    #+#             */
/*   Updated: 2023/10/23 20:32:55 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*alts;

	alts = (char *)s;
	i = ft_strlen(s);
	if (c == '\0')
		return (&alts[i]);
	while (i != 0)
	{
		if (alts[i] == (char)c)
			return (&alts[i]);
		i--;
	}
	if (s[0] == (char)c)
		return (alts);
	return (0);
}
