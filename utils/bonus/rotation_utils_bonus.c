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

#include "../../fdf_bonus.h"

void	rotate_z(float *x, float *y, float *z, int degree)
{
	float	cos_theta;
	float	sin_theta;
	float	tmp;
	float	radian;

	radian = degree * (M_PI / 180);
	cos_theta = cos(radian);
	sin_theta = sin(radian);
	tmp = *x;
	*x = cos_theta * *x - sin_theta * *y;
	*y = sin_theta * tmp + cos_theta * *y;
	(void)*z;
}

void	rotate_x(float *x, float *y, float *z, int degree)
{
	float	cos_theta;
	float	sin_theta;
	float	tmp;
	float	radian;

	radian = degree * (M_PI / 180);
	cos_theta = cos(radian);
	sin_theta = sin(radian);
	tmp = *y;
	(void)*x;
	*y = cos_theta * *y - sin_theta * *z;
	*z = sin_theta * tmp + cos_theta * *z;
}

void	rotate_y(float *x, float *y, float *z, int degree)
{
	float	cos_theta;
	float	sin_theta;
	float	tmp;
	float	radian;

	radian = degree * (M_PI / 180);
	cos_theta = cos(radian);
	sin_theta = sin(radian);
	tmp = *x;
	(void)*y;
	*x = cos_theta * *x + sin_theta * *z;
	*z = -sin_theta * tmp + cos_theta * *z;
}
