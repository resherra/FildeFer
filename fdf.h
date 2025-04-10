/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:37:42 by recherra          #+#    #+#             */
/*   Updated: 2025/02/21 17:42:54 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>

#define MODE 0

#if MODE == 0

#define WIDTH 1920
#define HEIGHT 1080
#define ESC 53 // Escape key
#define RA 124 // Right Arrow
#define LA 123 // Left Arrow
#define UA 126 // Up Arrow
#define DA 125 // Down Arrow
#define FK 3   // 'f' key
#define GK 5   // 'g' key
#define XK 7   // 'x' key
#define ZK 6   // 'z' key
#define YK 16  // 'y' key

#else

#include <X11/Xlib.h>
#include <X11/keysym.h>
#define WIDTH 1280
#define HEIGHT 720
#define ESC XK_Escape
#define RA XK_Right
#define LA XK_Left
#define UA XK_Up
#define DA XK_Down
#define FK XK_f
#define GK XK_g
#define XK XK_x
#define ZK XK_z
#define YK XK_y

#endif

typedef struct s_map_size
{
    int x;
    int y;
    float max_x;
    float min_x;
    float max_y;
    float min_y;
    float bounding_w;
    float bounding_h;
    float scale_f;
    float offset_x;
    float offset_y;
} t_map_size;

typedef struct s_pcord
{
    float x;
    float y;
    float z;
    int color;
} t_pcord;

typedef struct s_mlx
{
    void *connection;
    void *window;
} t_mlx;

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

typedef struct s_dda
{
    float steps;
    float dx;
    float dy;
    float x_factor;
    float y_factor;
} t_dda;

typedef struct s_degree
{
    float x_degree;
    float y_degree;
    float z_degree;
    char axis;
} t_degree;

typedef struct s_keys_state
{
    int f;
    int g;
    int x;
    int z;
    int y;
} t_keys_state;

typedef struct s_mouse_state
{
    int left_button;
    int scroll_up;
    int scroll_down;
} t_mouse_state;

typedef struct s_bonus
{
    t_mlx mlx;
    t_map_size *calcs;
    t_pcord **points;
    t_data img;
    t_degree degrees;
    t_keys_state state;
    t_mouse_state mouse_state;
    float prev_x;
    float prev_y;
} t_bonus;

void init_error(void *ptr);
void mlx_initial(t_mlx *mlx, t_data *img);
void cols_rows_count(int fd, t_map_size *plan);
int get_color(char *point);
void map_dots(char *file, t_map_size *plan, t_pcord **points);
void mem_allocation(t_map_size *plan, t_pcord ***points);
t_pcord **map_parse(char *str, t_map_size *plan);
void map_checker(int ac, char *map);
int ft_open(char *str);
void projection(t_pcord **points, t_map_size *plan, t_degree degree);
void translate(t_pcord *point1, t_pcord *point2, t_map_size *plan);
void scale(t_pcord *point1, t_pcord *point2, t_map_size *plan);
void draw(t_pcord **points, t_map_size *plan, t_data *img);
void custom_mlx_pixel_put(t_data *data, int x, int y, int color);
void factor(t_map_size *plan);
void ft_putstr(char *s);
void print_error(char *str);
int close_btn(t_mlx *mlx);
void rotate_z(float *x, float *y, float *z, int degree);
void rotate_x(float *x, float *y, float *z, int degree);
void rotate_y(float *x, float *y, float *z, int degree);
void rebuild(t_bonus *init);
void reproject(int keycode, t_bonus *init);
int readjust(int keycode, t_bonus *init);
int key_hook(int keycode, t_bonus *init);
int key_check(int key);
void re_render(t_bonus *init);

// keys hoo utils
int key_press(int keycode, t_bonus *data);
int key_release(int keycode, t_bonus *data);
void set_state(t_bonus *data, int key_button_code, int state);

// mouse hooks utils
int mouse_press(int button, int x, int y, t_bonus *data);
int mouse_release(int button, int x, int y, t_bonus *data);
int mouse_hook(int x, int y, t_bonus *data);

// ultimate hook
int ultimate_hook(t_bonus *init);

#endif