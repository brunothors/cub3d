/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:01:34 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/07 13:04:38 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*array;

	total = (nmemb * size);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (total / size != nmemb)
		return (NULL);
	array = malloc(total);
	if (!array)
		return (NULL);
	ft_bzero(array, total);
	return (array);
}
