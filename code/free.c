/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:06:15 by khuynh            #+#    #+#             */
/*   Updated: 2022/10/16 13:35:30 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	freemaps(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		freeallexit2("\033[0;31mError: Map vide\n\e[0m", game);
	while (game->map[i])
	{
		free(game->map[i]);
		free(game->mapcopy[i]);
		i++;
	}
	free(game->map);
	free(game->mapcopy);
}

int	freefinal(t_game *game)
{	
	if (game->map != NULL)
		freemaps(game);
	if (game->mlxwin != NULL)
		mlx_destroy_window(game->mlxptr, game->mlxwin);
	if (game->img.c != NULL)
		mlx_destroy_image(game->mlxptr, game->img.c);
	if (game->img.p != NULL)
		mlx_destroy_image(game->mlxptr, game->img.p);
	if (game->img.e != NULL)
		mlx_destroy_image(game->mlxptr, game->img.e);
	if (game->img.w != NULL)
		mlx_destroy_image(game->mlxptr, game->img.w);
	if (game->img.f != NULL)
		mlx_destroy_image(game->mlxptr, game->img.f);
	if (game->mlxptr != NULL)
	{
		mlx_destroy_display(game->mlxptr);
		free(game->mlxptr);
	}
	exit (0);
}

int	freeallexit(char *error, t_game *game)
{	
	ft_printf("%s", error);
	if (game->map != NULL)
		freemaps(game);
	if (game->mlxwin != NULL)
		mlx_destroy_window(game->mlxptr, game->mlxwin);
	if (game->img.c != NULL)
		mlx_destroy_image(game->mlxptr, game->img.c);
	if (game->img.p != NULL)
		mlx_destroy_image(game->mlxptr, game->img.p);
	if (game->img.e != NULL)
		mlx_destroy_image(game->mlxptr, game->img.e);
	if (game->img.w != NULL)
		mlx_destroy_image(game->mlxptr, game->img.w);
	if (game->img.f != NULL)
		mlx_destroy_image(game->mlxptr, game->img.f);
	if (game->mlxptr != NULL)
	{
		mlx_destroy_display(game->mlxptr);
		free(game->mlxptr);
	}
	exit (0);
}

int	freeallexit2(char *error, t_game *game)
{	
	ft_printf("%s", error);
	if (game->mlxptr != NULL)
	{
		mlx_destroy_display(game->mlxptr);
		free(game->mlxptr);
	}
	exit (0);
}

int	freeallexit3(char *error, t_game *game)
{	
	ft_printf("%s", error);
	if (game->map != NULL)
		freemaps(game);
	if (game->mlxptr != NULL)
	{
		mlx_destroy_display(game->mlxptr);
		free(game->mlxptr);
	}
	exit (0);
}
