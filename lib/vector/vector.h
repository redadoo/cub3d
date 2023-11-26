/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:12:28 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/26 16:48:45 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector2_int {
	int	x;
	int	y;
}				t_vector2_int;

typedef struct s_vector2 {
	double	x;
	double	y;
}				t_vector2;

typedef struct s_vector3 {
	double	x;
	double	y;
	double	z;
}				t_vector3;

t_vector2		vector2_lerp(t_vector2 a, t_vector2 b, float t);
t_vector2		vector2_lerp_unclamped(t_vector2 a, t_vector2 b, float t);

#endif