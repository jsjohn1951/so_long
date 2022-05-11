/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:16:09 by wismith           #+#    #+#             */
/*   Updated: 2022/04/21 16:20:04 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long.h"

void	des_imgs(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.c);
	mlx_destroy_image(mlx->mlx, mlx->img.e);
	mlx_destroy_image(mlx->mlx, mlx->img.f);
	mlx_destroy_image(mlx->mlx, mlx->img.w);
	mlx_destroy_image(mlx->mlx, mlx->img.p);
}

int	terminate(t_mlx *mlx)
{
	freedom(mlx);
	des_imgs(mlx);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	ft_printf("\nYou %slost%s this round %s:(%s\n\n", KRED, KNRM, KRED, KNRM);
	exit(0);
}

void	terminate_success(t_mlx *mlx)
{
	freedom(mlx);
	des_imgs(mlx);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	ft_printf("\nYou %sfinished%s this round %s:)%s\n\n",
		KGRN, KNRM, KGRN, KNRM);
	exit(0);
}
