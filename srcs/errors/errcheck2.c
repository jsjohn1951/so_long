/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcheck2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:56:20 by wismith           #+#    #+#             */
/*   Updated: 2022/04/22 19:15:07 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long.h"

char	*nlcheck(char *str, char *buff)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	if (str[0] == '\n')
		errmsg5(str, buff);
	while (str[++i])
	{
		if (str[i] != '\n')
			flag++;
		if (str[i] && str[i + 1] && str[i] == '\n'
			&& str[i + 1] == '\n' && flag > 0)
			errmsg5(str, buff);
	}
	return (str);
}

void	objcheck(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->matrix[++i])
	{
		j = -1;
		while (mlx->matrix[i][++j])
		{
			if (mlx->matrix[i][j] == 'P')
				mlx->p++;
			else if (mlx->matrix[i][j] == 'E')
				mlx->e++;
			else if (mlx->matrix[i][j] == 'C')
				mlx->cflag++;
		}
	}
	if (mlx->p != 1 || mlx->cflag < 1 || mlx->e < 1)
		errmsg4(mlx);
}

void	check_extension(char *s)
{
	int		i;
	int		index;
	int		flag;
	char	*p;

	i = ft_strlen(s);
	flag = 0;
	index = 0;
	p = (char []){'.', 'b', 'e', 'r', '\0'};
	while (s[--i] != '.' && i >= 0)
		;
	if (i < 0)
		flag = 1;
	while (s[i])
	{
		if (s[i] != p[index])
			flag = 1;
		i++;
		index++;
	}
	if (flag == 1 || index < 4)
		errmsg2(s);
}
