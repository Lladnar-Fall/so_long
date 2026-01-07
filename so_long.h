/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 03:46:19 by rlutucir          #+#    #+#             */
/*   Updated: 2026/01/08 03:46:27 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_img
{
    void    *img;
    int     w;
    int     h;
} t_img;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    
    int     width;
    int     height;
    int     moves;
    
    int     player_x;
    int     player_y;
    
    t_img   wall;
    t_img   floor;
    t_img   player;
    t_img   exit;
    t_img   collect;
} t_game;

void	move_player(t_game *g, int dx, int dy);
int		key_hook(int keycode, t_game *g);
void	init_mlx(t_game *g);
void    load_image(t_game *g, t_img *img, char *path);
void    load_images(t_game *g);
void    draw_tile(t_game *g, char tile, int x, int y);
void    render_map(t_game *g);  



#endif