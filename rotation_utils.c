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


#include "init.h"


void rotate_z(int *x, int *y, int *z)
{
    float cos_theta = cos(M_PI_4);
    float sin_theta = sin(M_PI_4);

    //i should create tmp variables
    int tmp = *x;
    *x = cos_theta * *x - sin_theta * *y;
    *y = sin_theta * tmp + cos_theta * *y;
    *z = *z;
}

//rotation around x
void rotate_x(int *x, int *y, int *z)
{
    float cos_theta = cos(atan(sqrt(2)));
    float sin_theta = sin(atan(sqrt(2)));

    int tmp = *y;
    *x = *x;
    *y = cos_theta * *y - sin_theta * *z;
    *z = sin_theta * tmp  + cos_theta * *z;
}


//rotation around y
t_vector rotate_y(t_vector v, double degrees)
{
//    double radians = degrees * (M_PI / 180.0);
    (void)degrees;
//    M_PI_4   45deg;
    float cos_theta = cos(M_PI_4);
    float sin_theta = sin(M_PI_4);

    t_vector new_v;
    new_v.x = v.x * cos_theta + v.z * sin_theta;
    new_v.y = v.y;
    new_v.z = -v.x * sin_theta + v.z * cos_theta;

    return new_v;
}