/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:09 by wismith           #+#    #+#             */
/*   Updated: 2022/04/21 16:02:30 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long.h"

int	character_check(char **matrix)
{
	int	i;
	int	j;

	i = -1;
	while (matrix[++i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] != '0' && matrix[i][j] != '1'
				&& matrix[i][j] != 'P' && matrix[i][j] != 'C'
					&& matrix[i][j] != 'E')
				return (1);
			j++;
		}
	}
	return (0);
}

int	wallcheck(char **matrix)
{
	int	i;
	int	j;
	int	last;

	i = -1;
	j = -1;
	while (matrix[0][++j])
	{
		if (matrix[0][j] != '1')
			return (wallintegcomp());
	}
	while (matrix[++i])
	{
		last = ft_strlen_mod(matrix[i]) - 1;
		if (matrix[i][0] != '1' || matrix[i][last] != '1')
			return (wallintegcomp());
	}
	j = -1;
	i -= 1;
	while (matrix[i][++j])
	{
		if (matrix[i][j] != '1')
			return (wallintegcomp());
	}
	return (0);
}

int	sqrcheck(char **matrix)
{
	int	i;
	int	size;

	i = 1;
	size = ft_strlen_mod(matrix[0]);
	while (matrix[i])
	{
		if (size != ft_strlen_mod(matrix[i]))
			return (sqrerrmsg());
		i++;
	}
	if (character_check(matrix))
	{
		ft_putstr_fd("Error\n", 2);
		ft_printf("\t%sWrong%s Characters Detected!\n", KRED, KNRM);
		return (1);
	}
	return (wallcheck(matrix));
}
