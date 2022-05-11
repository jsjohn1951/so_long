/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Objs2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:56:24 by wismith           #+#    #+#             */
/*   Updated: 2022/04/22 18:59:18 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long_bonus.h"

void	character_left(t_mlx *mlx)
{
	int		h;
	int		w;

	h = 50;
	w = 50;
	mlx->img.p_l = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/pics/char_left.xpm", &w, &h);
}
