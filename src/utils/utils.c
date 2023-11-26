/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:17:47 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/26 13:11:24 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_dir(char ch)
{
	if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
		return (1);
	return (0);
}

void	print_matrix(char **matrix)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == '1')
				printf("\033[0;36m%c", matrix[i][j]);
			else if (matrix[i][j] == '0')
				printf("\033[0;37m%c", matrix[i][j]);
			else if (check_dir(matrix[i][j]) == 1)
				printf("\033[0;33m%c", matrix[i][j]);
			else if (matrix[i][j] != '\n')
				printf("%c", matrix[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

void	print_vector3(t_vector3 v)
{
	printf("x : %.2f ", v.x);
	printf("z : %.2f ", v.z);
	printf("y : %.2f \n", v.y);
}

t_vector3	set_vector3(float x, float y, float z)
{
	t_vector3	v;

	v.x = x;
	v.z = z;
	v.y = y;
	return (v);
}

t_vector2	set_vector2(float x, float y)
{
	t_vector2	v;

	v.x = x;
	v.y = y;
	return (v);
}
