/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manage_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:20:49 by wismith           #+#    #+#             */
/*   Updated: 2022/04/22 18:59:08 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long_bonus.h"

void	pcheck(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->matrix[++i])
	{
		j = 0;
		while (mlx->matrix[i][j])
		{
			if (mlx->matrix[i][j] == 'P')
				return ;
			j++;
		}
	}
	terminate_success(mlx);
}

void	display_move(t_mlx *mlx, int move)
{
	display_bar(mlx, mlx->width);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 5, 10, 0x800080, "Moves: ");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 55, 10, 0x008000, ft_itoa(move));
	mlx_string_put(
		mlx->mlx, mlx->mlx_win, 2 * 50 - 20, 10, 0x800080, "Coins Remaining: ");
	mlx_string_put(
		mlx->mlx, mlx->mlx_win, 4 * 50, 10, 0x008000, ft_itoa(mlx->cflag));
}

int	moves(int keycode, t_mlx *mlx)
{
	static int	move;

	if (keycode != 13 && keycode != 0 && keycode != 2 && keycode != 1
		&& keycode != 53)
		return (0);
	if (keycode == 53)
		terminate(mlx);
	if (keycode == 13)
		move += up(mlx);
	if (keycode == 0)
		move += left(mlx);
	if (keycode == 2)
		move += right(mlx);
	if (keycode == 1)
		move += down(mlx);
	mlx->cflag = num_collectable(mlx);
	display_move(mlx, move);
	ft_printf("%sMoves: '%s%d%s'\t Coins left: '%s%d%s'\n",
		KCLR, KGRN, move, KNRM, KGRN, mlx->cflag, KNRM);
	pcheck(mlx);
	return (0);
}
