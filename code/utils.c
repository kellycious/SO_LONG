/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:38:28 by khuynh            #+#    #+#             */
/*   Updated: 2022/10/16 13:52:05 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"
#include <stdio.h>

void	init_struct(t_game *game)
{
	game->map = NULL;
	game->mapcopy = NULL;
	game->x = 0;
	game->y = 0;
	game->collect = 0;
	game->copycollect = 0;
	game->player = 0;
	game->posy = 0;
	game->posx = 0;
	game->moves = 1;
	game->exit = 0;
	game->complete = 0;
	game->mlxptr = mlx_init();
	if (!game->mlxptr)
		freeallexit2("\033[0;31mCould not connect to mlxptr\e[0m", game);
	ft_bzero(&(game->img), sizeof(t_xmp));
}

int	checkplayer(t_game *game, int x, int y)
{
	if (game->mapcopy[x][y] == 'P' &&
	(game->mapcopy[x][y + 1] == 'C'
	|| game->mapcopy[x][y + 1] == '0'
	|| game->mapcopy[x - 1][y] == 'C'
	|| game->mapcopy[x - 1][y] == '0'
	|| game->mapcopy[x][y - 1] == 'C'
	|| game->mapcopy[x][y - 1] == '0'
	|| game->mapcopy[x + 1][y] == 'C'
	|| game->mapcopy[x + 1][y] == '0'))
		return (1);
	return (0);
}

void	aroundplayer(t_game *game, int x, int y)
{
	if (game->mapcopy[x][y] == 'C' || game->mapcopy[x][y] == '0')
	{
		if (game->mapcopy[x][y] == 'C')
			game->copycollect--;
		game->mapcopy[x][y] = 'P';
	}
}

int	exitcheck(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->mapcopy[x])
	{
		y = 0;
		while (game->mapcopy[x][y])
		{
			if ((game->mapcopy[x][y] == 'E' && game->mapcopy[x][y + 1] == 'P')
			|| (game->mapcopy[x][y] == 'E' && game->mapcopy[x][y - 1] == 'P')
			|| (game->mapcopy[x][y] == 'E' && game->mapcopy[x - 1][y] == 'P')
			|| (game->mapcopy[x][y] == 'E' && game->mapcopy[x + 1][y] == 'P'))
				return (1);
			y++;
		}
		x++;
	}
	return (freeallexit3("\033[0;31mNo succesfull path found\n\e[0m", game), 0);
}

int	path_ok(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	game->copycollect = game->collect;
	while (x < game->y)
	{
		y = 0;
		while (game->mapcopy[x][y])
		{
			if (checkplayer(game, x, y))
			{
				aroundplayer(game, x + 1, y);
				aroundplayer(game, x - 1, y);
				aroundplayer(game, x, y + 1);
				aroundplayer(game, x, y - 1);
				x = 0;
			}
			y++;
		}
		x++;
	}
	if (game->copycollect == 0 && exitcheck(game))
		return (1);
	return (freeallexit3("\033[0;31mNo succesfull path found\n\e[0m", game), 0);
}

// int	main(int argc, char **argv)
// {
// 	t_game game;

// 	argcheck(argc, argv);
// 	init_struct(&game);
// 	if (!game.mlxptr)
// 		return (1);
// 	map_open(argv[1], &game);
// 	charerror_map(&game);
// 	rectangular_mapcheck(&game);
// 	walls_mapcheck(&game);
// 	for (int i = 0; game.map[i]; i++)
// 		printf("%s\n", game.map[i]);
// 	printf("\n");
// 	path_ok(&game);
// 	for (int i = 0; game.mapcopy[i]; i++)
// 		printf("%s\n", game.mapcopy[i]);
// }
