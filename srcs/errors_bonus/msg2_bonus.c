/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:01:47 by wismith           #+#    #+#             */
/*   Updated: 2022/04/22 19:19:16 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long_bonus.h"

void	errmsg4(t_mlx *mlx)
{
	ft_putstr_fd("Error\n", 2);
	if (mlx->e < 1 || mlx->p < 1 || mlx->cflag < 1)
	{
		ft_printf("\tMust contain at least %sone%s of the following:\n",
			KRED, KNRM);
		ft_printf("\t'%sP%s', '%sC%s', '%sE%s'\n",
			KGRN, KNRM, KGRN, KNRM, KGRN, KNRM);
	}
	else if (mlx->p > 1)
		ft_printf("\tOnly one '%sP%s' character allowed!\n", KGRN, KNRM);
	exit (freedom(mlx));
}

void	errmsg5(char *str, char *buff)
{
	ft_putstr_fd("Error\n", 2);
	ft_printf("\t'%sNewline%s' found at start, or within Map!\n", KRED, KNRM);
	free (str);
	free (buff);
	exit (1);
}

int	sqrerrmsg(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_printf("\tMap is %sNOT%s a rectangle!\n", KRED, KNRM);
	return (1);
}

int	wallintegcomp(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_printf("\tWall integrity %sCOMPROMISED%s!\n", KRED, KNRM);
	return (1);
}
