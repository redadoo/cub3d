/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:01:43 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/26 16:01:44 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector2	vector2_lerp(t_vector2 a, t_vector2 b, float t)
{
	t_vector2	res;

	if (t < 0) 
		t = 0;
	else if (t > 1) 
		t = 1;
	res.x = a.x + (b.x - a.x) * t;
	res.y = a.y + (b.y - a.y) * t;
	return (res);
}

t_vector2	vector2_lerp_unclamped(t_vector2 a, t_vector2 b, float t)
{
	t_vector2	res;

	res.x = a.x + (b.x - a.x) * t;
	res.y = a.y + (b.y - a.y) * t;
	return (res);
}
