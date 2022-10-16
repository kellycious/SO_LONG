/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:38:33 by khuynh            #+#    #+#             */
/*   Updated: 2022/10/15 18:47:02 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	xpmtoimage(t_game *game)
{
	game->img.c = mlx_xpm_file_to_image(
			game->mlxptr, "../xpm/c.xpm", &game->img.width, &game->img.height);
	game->img.e = mlx_xpm_file_to_image(
			game->mlxptr, "../xpm/e.xpm", &game->img.width, &game->img.height);
	game->img.p = mlx_xpm_file_to_image(
			game->mlxptr, "../xpm/p.xpm", &game->img.width, &game->img.height);
	game->img.w = mlx_xpm_file_to_image(
			game->mlxptr, "../xpm/w.xpm", &game->img.width, &game->img.height);
	game->img.f = mlx_xpm_file_to_image(
			game->mlxptr, "../xpm/f.xpm", &game->img.width, &game->img.height);
	if (!game->img.c || !game->img.e || !game->img.p || !game->img.w
		|| !game->img.f)
		freeallexit("xpm couldn't convert to image\n", game);
}

void	imgtowin(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(
			game->mlxptr, game->mlxwin, game->img.c, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(
			game->mlxptr, game->mlxwin, game->img.p, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(
			game->mlxptr, game->mlxwin, game->img.e, x * 64, y * 64);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(
			game->mlxptr, game->mlxwin, game->img.w, x * 64, y * 64);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(
			game->mlxptr, game->mlxwin, game->img.f, x * 64, y * 64);
}

int	displaygame(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	if (game->mlxwin)
	{
		while (game->map[++x])
		{
			y = 0;
			while (game->map[x][y])
			{
				imgtowin(game, x, y);
				y++;
			}
		}
	}
	return (0);
}
