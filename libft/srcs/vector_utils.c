/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:55:20 by vcarrara          #+#    #+#             */
/*   Updated: 2025/06/02 16:56:32 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	create_vector(float x, float y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector	add_vector(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1 .x + v2.x;
	vector.y = v1.y + v2.y;
	return (vector);
}

t_vector	copy_vector(t_vector v)
{
	t_vector	vector;

	vector.x = v.x;
	vector.y = v.y;
	return (vector);
}
