/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:17:47 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/24 20:28:22 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void print_matrix(char **matrix)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    j = 0;
    while (matrix[i])
    {
        str = matrix[i];
        while (str[j])
        {
            if (str[j] == '1')
                printf("\033[0;36m%c",str[j]);
            if (str[j] == '0')
                printf("\033[0;37m%c",str[j]);            
            if (str[j] == 'N' || str[j] == 'W' || str[j] == 'S' || str[j] == 'E')
                printf("\033[0;33m%c",str[j]);
            else if(str[j] != '\n')
                printf("%c",str[j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
    
}