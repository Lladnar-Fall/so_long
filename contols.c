/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 03:37:08 by rlutucir          #+#    #+#             */
/*   Updated: 2026/01/08 03:37:21 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *g, int dx, int dy)
{
	int nx = g->player_x + dx;
	int ny = g->player_y + dy;

	if (g->map[ny][nx] == '1')
		return ;
	if (g->map[ny][nx] == 'c')
		collect_item(g);
	if (g->map[ny][nx] == 'E' && collectibles_left(g))
		return ;
	
	g->map[g->player_y][g->player_x] = '0';
	g->map[ny][nx] = 'P';
	g->player_x = nx;
	g->player_y = ny;
	g->moves++;

	render_map(g);
}

int	key_hook(int keycode, t_game *g)
{
    if (keycode == 65307)
        close_game(g);
    if (keycode == 'w')
        move_player(g, 0, -1);
    if (keycode == 's')
        move_player(g, 0, 1);
	if (keycode == 'a')
        move_player(g, -1, 0);
	if (keycode == 'd')
        move_player(g, 1, 0);
	return (0);
}


int main(int ac, char **av)
{
	t_game g;

	init_game(&g, av[1]);
	init_mlx(&g);
	load_images(&g);
	render_map(&g);

	mlx_key_hook(g.win, key_hook, &g);
	mlx_hook(g.win, 17, 0, close_game, &g);
	
	mlx_loop(g.mlx);
}