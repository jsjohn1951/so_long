/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_col.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:26:42 by wismith           #+#    #+#             */
/*   Updated: 2022/04/09 12:29:32 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long.h"

int	num_collectable(t_mlx *mlx)
{
	int	i;
	int	j;
	int	num;

	i = -1;
	num = 0;
	while (mlx->matrix[++i])
	{
		j = 0;
		while (mlx->matrix[i][j])
		{
			if (mlx->matrix[i][j] == 'C')
				num++;
			j++;
		}
	}
	return (num);
}
