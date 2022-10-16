/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:13:22 by khuynh            #+#    #+#             */
/*   Updated: 2022/10/16 13:35:05 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

// check that the map ONLY contains "1C0EP"

void	char_mapcheck(t_game *game, char c, int x, int y)
{
	if (c == 'C')
		game->collect++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->posy = y;
		game->posx = x;
	}
	else if (c == '1' || c == '0')
		return ;
	else
		freeallexit3("\033[0;31mOnly put 1,C,0,E,P in map!\n\e[0m", game);
}

// display error message according to char errors in map

void	charerror_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	if (!game->map)
		freemaps(game);
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			char_mapcheck(game, game->map[x][y], x, y);
			y++;
		}
		x++;
	}
	if (game->collect == 0)
		freeallexit3("\033[0;31mPls input collectible !\n\e[0m", game);
	if (game->player == 0)
		freeallexit3("\033[0;31mPls input one player !\n\e[0m", game);
	if (game->player > 1)
		freeallexit3("\033[0;31mOnly 1 player is allowed\n\e[0m", game);
	if (game->exit == 0 || game->exit > 1)
		freeallexit3("\033[0;31mMissing an exit or too many...\n\e[0m", game);
}

// check if there are walls all around the map

void	walls_mapcheck(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[0][j] != '1' || game->map[game->y - 1][j] != '1')
				freeallexit3("\033[0;31mMissing a wall or two...\n\e[0m", game);
			if (game->map[i][0] != '1' || game->map[i][game->x - 1] != '1')
				freeallexit3("\033[0;31mMissing a wall or two...\n\e[0m", game);
			j++;
		}
		i++;
	}
}

// check if the map is rectangular + display error message for walls

void	rectangular_mapcheck(t_game *game)
{
	int	x;
	int	y;
	int	size;

	size = ft_strlen(game->map[0]);
	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = ft_strlen(game->map[y]);
		if (x != size)
			freeallexit3("\033[0;31mYour map is not rectangular ☹\n\e[0m", game);
		y++;
	}
}
