/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:00:07 by khuynh            #+#    #+#             */
/*   Updated: 2022/10/16 13:37:58 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_xmp
{
	void	*c;
	void	*e;
	void	*p;
	void	*w;
	void	*f;
	int		width;
	int		height;
}	t_xmp;

// x = column, y = row

typedef struct s_game
{
	t_xmp	img;
	char	**map;
	char	**mapcopy;
	int		x;
	int		y;
	int		collect;
	int		copycollect;
	int		player;
	int		posy;
	int		posx;
	int		exit;
	int		moves;
	int		complete;
	void	*mlxptr;
	void	*mlxwin;
}	t_game;

// map functions

int		map_open(char *av, t_game *game, int fd);
void	freemaps(t_game *game);
void	char_mapcheck(t_game *game, char c, int x, int y);
void	charerror_map(t_game *game);
void	walls_mapcheck(t_game *game);
void	rectangular_mapcheck(t_game *game);

// render xpm

void	xpmtoimage(t_game *game);
void	imgtowin(t_game *game, int x, int y);
int		displaygame(t_game *game);
int		freefinal(t_game *game);
int		freeallexit(char *error, t_game *game);
int		freeallexit2(char *error, t_game *game);
int		freeallexit3(char *error, t_game *game);

// moves

int		moveok(t_game *game, int x, int y, int key);
void	movereset(t_game *game, int x, int y, int key);
int		keyactions(int key, t_game *game);

// miscellaneous 

void	init_struct(t_game *game);

//path check

void	argcheck(int ac, char **av);
void	aroundplayer(t_game *game, int x, int y);
int		exitcheck(t_game *game);
int		path_ok(t_game *game);
int		mapcopy(t_game *game);

#endif