/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:37:45 by wismith           #+#    #+#             */
/*   Updated: 2022/04/22 19:52:29 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long_bonus.h"

char	**freedyou(char *buff, char *string)
{
	if (buff)
	{
		free (buff);
		buff = NULL;
	}
	if (string)
	{
		free (string);
		string = NULL;
	}
	return (NULL);
}

void	parser(char *path, t_mlx *mlx)
{
	int		fd;
	char	*str;
	char	*buff;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		errmsg3();
	str = (char *)ft_calloc(2, sizeof (char));
	buff = (char *)ft_calloc(2, sizeof (char));
	if (!str || !buff)
		freedyou(buff, str);
	while (read(fd, buff, 1) > 0 && str && buff)
		str = ft_strjoin_mod(str, buff, 1);
	close(fd);
	if (!ft_strlen_mod(str))
		mlx->matrix = NULL;
	else
		mlx->matrix = ft_split_mod(nlcheck(str, buff), '\n');
	freedyou(buff, str);
	if (mlx->matrix == NULL)
		errmsg3();
}
