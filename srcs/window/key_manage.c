/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:20:49 by wismith           #+#    #+#             */
/*   Updated: 2022/04/21 16:16:36 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long.h"

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
	ft_printf("%sMoves: '%s%d%s'\t Coins left: '%s%d%s'\n",
		KCLR, KGRN, move, KNRM, KGRN, mlx->cflag, KNRM);
	pcheck(mlx);
	return (0);
}
