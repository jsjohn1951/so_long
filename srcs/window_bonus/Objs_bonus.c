/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Objs_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:42:44 by wismith           #+#    #+#             */
/*   Updated: 2022/04/22 18:59:13 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long_bonus.h"

void	*character(t_mlx *mlx)
{
	int		h;
	int		w;

	h = 50;
	w = 50;
	return (mlx_xpm_file_to_image(mlx->mlx,
			"./assets/pics/character.xpm", &w, &h));
}

void	*wall(t_mlx *mlx)
{
	int		h;
	int		w;

	h = 50;
	w = 50;
	return (mlx_xpm_file_to_image(mlx->mlx,
			"./assets/pics/wall.xpm", &w, &h));
}

void	*floored(t_mlx *mlx)
{
	int		h;
	int		w;

	h = 50;
	w = 50;
	return (mlx_xpm_file_to_image(mlx->mlx,
			"./assets/pics/floor.xpm", &w, &h));
}

void	*collectable(t_mlx *mlx)
{
	int		h;
	int		w;

	h = 50;
	w = 50;
	return (mlx_xpm_file_to_image(mlx->mlx,
			"./assets/pics/collectable.xpm", &w, &h));
}

void	*exited(t_mlx *mlx)
{
	int		h;
	int		w;

	h = 50;
	w = 50;
	return (mlx_xpm_file_to_image(mlx->mlx,
			"./assets/pics/exit.xpm", &w, &h));
}
