/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:30:46 by wismith           #+#    #+#             */
/*   Updated: 2022/04/18 00:44:14 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long.h"

int	freedom(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (!mlx->matrix)
		return (1);
	while (mlx->matrix[i])
	{
		free(mlx->matrix[i]);
		i++;
	}
	free(mlx->matrix);
	return (1);
}
