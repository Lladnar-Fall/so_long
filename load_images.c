/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 03:45:29 by rlutucir          #+#    #+#             */
/*   Updated: 2026/01/08 03:45:32 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    load_image(t_game *g, t_img *img, char *path)
{
    img->img = mlx_xpm_file_to_image(g->mlx, path, &img->w, &img->h);
    if (!img->h)
        error_exit("Image load failed");
}

void    load_images(t_game *g)
{
    load_image(g, &g->wall, "textures/wall.xpm");
    load_image(g, &g->floor, "textures/floor.xpm");
    load_image(g, &g->player, "textures/player.xpm");
    load_image(g, &g->exit, "textures/exit.xpm");
    load_image(g, &g->collect, "textures/collect.xpm");
}