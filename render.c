/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 03:45:46 by rlutucir          #+#    #+#             */
/*   Updated: 2026/01/08 03:45:58 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    draw_tile(t_game *g, char tile, int x, int y)
{
    mlx_put_image_to_window(
        g->mlx, g->win, g->floor.img,
        x * 64, y * 64
    );

    if (tile == '1')
        mlx_put_image_to_window(g->mlx, g->win, g->wall.img, x * 64, y * 64);
    else if (tile == 'P')
        mlx_put_image_to_window(g->mlx, g->win, g->player.img, x * 64, y * 64);
    else if (tile == 'E')
        mlx_put_image_to_window(g->mlx, g->win, g->exit.img, x * 64, y * 64);
    else if (tile == 'P')
        mlx_put_image_to_window(g->mlx, g->win, g->exit.img, x * 64, y * 64);
}

void    render_map(t_game *g)
{
    int x;
    int y;

    y = 0;
    while (g->map[y])
    {
        x = 0;
        while (g->map[y][x])
        {
            draw_tile(g, g->map[y][x], x, y);
            x++;
        }
        y++;
    }
}