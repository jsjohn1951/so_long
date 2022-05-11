/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:19:42 by wismith           #+#    #+#             */
/*   Updated: 2022/04/22 18:59:38 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long_bonus.h"

void	display_moves(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->mlx_win, 5, 10, 0x800080, "Moves: ");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 55, 10, 0x008000, "0");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 2 * 50 - 20, 10,
		0x800080, "Coins Remaining: ");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 4 * 50, 10,
		0x008000, ft_itoa(mlx->cflag));
}

int	height(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	so_long(t_mlx *mlx)
{
	mlx->height = height(mlx->matrix);
	mlx->width = ft_strlen_mod(mlx->matrix[0]);
	mlx->cflag = num_collectable(mlx);
	ft_printf("%sMoves: '%s0%s'\t Coins left: '%s%d%s'\n",
		KCLR, KGRN, KNRM, KGRN, mlx->cflag, KNRM);
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx,
			mlx->width * 50, mlx->height * 50, "so_long");
	start(mlx);
	display_moves(mlx);
	mlx_hook(mlx->mlx_win, 17, 0L, terminate, mlx);
	mlx_key_hook(mlx->mlx_win, moves, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.cflag = 0;
	mlx.p = 0;
	mlx.e = 0;
	if (argc != 2)
		errmsg1(argv);
	check_extension(argv[1]);
	parser(argv[1], &mlx);
	objcheck(&mlx);
	if (sqrcheck(mlx.matrix))
		return (freedom(&mlx));
	so_long(&mlx);
	return (0);
}
