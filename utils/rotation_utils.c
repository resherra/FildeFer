/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:57:00 by recherra          #+#    #+#             */
/*   Updated: 2024/04/12 18:57:02 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

void	rotate_z(float *x, float *y, float *z)
{
	float	cos_theta;
	float	sin_theta;
	float	tmp;


	cos_theta = cos(M_PI_4);
	sin_theta = sin(M_PI_4);
	tmp = *x;
	*x = cos_theta * *x - sin_theta * *y;
	*y = sin_theta * tmp + cos_theta * *y;
    (void)*z;
}

void	rotate_x(float *x, float *y, float *z)
{
	float	cos_theta;
	float	sin_theta;
	float	tmp;


    float deg = 50.264 + 70;
    deg = deg * (M_PI / 180);

//    float s = atan(sqrt(2));

	cos_theta = cos(deg);
	sin_theta = sin(deg);
	tmp = *y;
    (void)*x;
	*y = cos_theta * *y - sin_theta * *z;
	*z = sin_theta * tmp + cos_theta * *z;
}
