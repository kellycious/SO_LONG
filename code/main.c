/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:22:43 by khuynh            #+#    #+#             */
/*   Updated: 2022/10/15 20:15:54 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	argcheck(int ac, char **av)
{
	int		i;
	int		j;
	char	*ber;

	i = 0;
	j = 0;
	ber = ".ber";
	if (ac < 2 || ac > 2)
	{
		ft_putstr_fd("Error: Put a map file or remove one extra argument", 2);
		exit (EXIT_FAILURE);
	}
	while (av[1][i])
		i++;
	while (j < 4)
	{
		i--;
		j++;
	}
	j = 0;
	if (av[1][i++] != ber[j++])
	{
		ft_putstr_fd("Error: Please use a .ber file for the map", 2);
		exit (EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	argcheck(ac, av);
	init_struct(&game);
	map_open(av[1], &game, 0);
	charerror_map(&game);
	rectangular_mapcheck(&game);
	walls_mapcheck(&game);
	if (path_ok(&game))
	{
		game.mlxwin = mlx_new_window(game.mlxptr, game.x * 64,
				game.y * 64, "Bbt x Ricard");
		xpmtoimage(&game);
		mlx_loop_hook(game.mlxptr, displaygame, &game);
		mlx_hook(game.mlxwin, 02, 1L << 0, keyactions, &game);
		mlx_hook(game.mlxwin, 33, 0L, freefinal, &game);
		mlx_loop(game.mlxptr);
		free(game.mlxptr);
	}
	return (0);
}
