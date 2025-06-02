/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:55:43 by vcarrara          #+#    #+#             */
/*   Updated: 2025/06/02 16:56:57 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	rotate_vector(t_vector v, float angle)
{
	t_vector	vector;
	float		radians;

	radians = angle * PI / 180.0;
	vector.x = v.x * cos(radians) - v.y * sin(radians);
	vector.y = v.x * sin(radians) + v.y * cos(radians);
	return (vector);
}

t_vector	mult_vector(t_vector v, double scalar)
{
	t_vector	vector;

	vector.x = v.x * scalar;
	vector.y = v.y * scalar;
	return (vector);
}

float	mag_vector(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}
