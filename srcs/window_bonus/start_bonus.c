/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:04:37 by wismith           #+#    #+#             */
/*   Updated: 2022/04/22 18:59:21 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long_bonus.h"

void	set(t_mlx *mlx, char c, int x, int y)
{
	if (c == 'P')
	{
		mlx->x = x / 50;
		mlx->y = y / 50;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.p, x, y);
	}
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.w, x, y);
	if (c == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.f, x, y);
	if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.c, x, y);
	if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img.e, x, y);
}

void	setimg(t_mlx *mlx)
{
	mlx->img.c = collectable(mlx);
	mlx->img.e = exited(mlx);
	mlx->img.w = wall(mlx);
	mlx->img.f = floored(mlx);
	mlx->img.p = character(mlx);
}

void	display_bar(t_mlx *mlx, int len)
{
	int	i;
	int	b_w;
	int	b_h;

	b_w = 50;
	b_h = 12;
	i = 0;
	mlx->img.bar = mlx_xpm_file_to_image(
			mlx->mlx, "./assets/pics/bar.xpm", &b_w, &b_h);
	while (i < len)
	{
		mlx_put_image_to_window(
			mlx->mlx, mlx->mlx_win, mlx->img.bar, i * 50, 0);
		i++;
	}
}

void	start(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	setimg(mlx);
	while (mlx->matrix[i])
	{
		j = 0;
		while (mlx->matrix[i][j])
		{
			set(mlx, mlx->matrix[i][j], j * 50, i * 50);
			j++;
		}
		i++;
	}
	display_bar(mlx, mlx->width);
	character_left(mlx);
}
