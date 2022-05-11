/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:33:40 by wismith           #+#    #+#             */
/*   Updated: 2022/04/21 16:48:25 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long.h"

/*	1st if statement:
		checks whether or not the next char is an exit, and whether
		there are coins left within the matrix. Move will only
		commence if coins left within matrix == 0.

	2nd if statement:
		checks that the next char is not an exit or a wall. If either
		condition is true the move will not commence, and will not
		be counted
*/

int	up(t_mlx *mlx)
{
	if (mlx->matrix[mlx->y - 1][mlx->x] == 'E' && mlx->cflag == 0)
	{
		mlx->matrix[mlx->y][mlx->x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.f, mlx->x * 50, mlx->y * 50);
		mlx->y--;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.e, mlx->x * 50, mlx->y * 50);
		return (1);
	}
	if (mlx->matrix[mlx->y - 1][mlx->x] != '1' &&
		mlx->matrix[mlx->y - 1][mlx->x] != 'E')
	{
		mlx->matrix[mlx->y][mlx->x] = '0';
		mlx->matrix[mlx->y - 1][mlx->x] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.f, mlx->x * 50, mlx->y * 50);
		mlx->y--;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.p, mlx->x * 50, mlx->y * 50);
		return (1);
	}
	return (0);
}

int	down(t_mlx *mlx)
{
	if (mlx->matrix[mlx->y + 1][mlx->x] == 'E' && mlx->cflag == 0)
	{
		mlx->matrix[mlx->y][mlx->x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.f, mlx->x * 50, mlx->y * 50);
		mlx->y++;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.e, mlx->x * 50, mlx->y * 50);
		return (1);
	}
	if (mlx->matrix[mlx->y + 1][mlx->x] != '1' &&
		mlx->matrix[mlx->y + 1][mlx->x] != 'E')
	{
		mlx->matrix[mlx->y][mlx->x] = '0';
		mlx->matrix[mlx->y + 1][mlx->x] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.f, mlx->x * 50, mlx->y * 50);
		mlx->y++;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.p, mlx->x * 50, mlx->y * 50);
		return (1);
	}
	return (0);
}

int	right(t_mlx *mlx)
{
	if (mlx->matrix[mlx->y][mlx->x + 1] == 'E' && mlx->cflag == 0)
	{
		mlx->matrix[mlx->y][mlx->x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.f, mlx->x * 50, mlx->y * 50);
		mlx->x++;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.e, mlx->x * 50, mlx->y * 50);
		return (1);
	}
	if (mlx->matrix[mlx->y][mlx->x + 1] != '1' &&
		mlx->matrix[mlx->y][mlx->x + 1] != 'E')
	{
		mlx->matrix[mlx->y][mlx->x] = '0';
		mlx->matrix[mlx->y][mlx->x + 1] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.f, mlx->x * 50, mlx->y * 50);
		mlx->x++;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.p, mlx->x * 50, mlx->y * 50);
		return (1);
	}
	return (0);
}

int	left(t_mlx *mlx)
{
	if (mlx->matrix[mlx->y][mlx->x - 1] == 'E' && mlx->cflag == 0)
	{
		mlx->matrix[mlx->y][mlx->x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.f, mlx->x * 50, mlx->y * 50);
		mlx->x--;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.e, mlx->x * 50, mlx->y * 50);
		return (1);
	}
	if (mlx->matrix[mlx->y][mlx->x - 1] != '1' &&
		mlx->matrix[mlx->y][mlx->x - 1] != 'E')
	{
		mlx->matrix[mlx->y][mlx->x] = '0';
		mlx->matrix[mlx->y][mlx->x - 1] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.f, mlx->x * 50, mlx->y * 50);
		mlx->x--;
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img.p, mlx->x * 50, mlx->y * 50);
		return (1);
	}
	return (0);
}
