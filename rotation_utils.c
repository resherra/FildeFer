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


t_vector rotate_z(t_vector v)
{
    float cos_theta = cos(M_PI_4);
    float sin_theta = sin(M_PI_4);

    t_vector new_v;
    new_v.x = cos_theta * v.x - sin_theta * v.y;
    new_v.y = sin_theta * v.x + cos_theta * v.y;
    new_v.z = v.z;

    return new_v;
}

//rotation around x
t_vector rotate_x(t_vector v)
{
    float cos_theta = cos(atan(sqrt(2)));
    float sin_theta = sin(atan(sqrt(2)));

    t_vector new_v;
    new_v.x = v.x;
    new_v.y = cos_theta * v.y - sin_theta * v.z ;
    new_v.z = sin_theta * v.y  + cos_theta * v.z;

    return new_v;
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