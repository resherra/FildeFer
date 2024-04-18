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
	*z = *z;
}

void	rotate_x(float *x, float *y, float *z)
{
	float	cos_theta;
	float	sin_theta;
	float	tmp;

	cos_theta = cos(atan(sqrt(2)));
	sin_theta = sin(atan(sqrt(2)));
	tmp = *y;
	*x = *x;
	*y = cos_theta * *y - sin_theta * *z;
	*z = sin_theta * tmp + cos_theta * *z;
}
