/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 03:37:33 by rlutucir          #+#    #+#             */
/*   Updated: 2026/01/08 03:37:40 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_mlx(t_game *g)
{
    g->mlx = mlx_init();
    g->win = mlc_new_window(
        g->mlx,
        g->width * 64,
        g->height * 64,
        "so long"
    );
}
