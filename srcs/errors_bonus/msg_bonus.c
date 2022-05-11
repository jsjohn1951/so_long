/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:42:50 by wismith           #+#    #+#             */
/*   Updated: 2022/04/22 18:58:52 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/so_long_bonus.h"

void	errmsg1(char **argv)
{
	int	i;

	i = 0;
	ft_putstr_fd("Error\n", 2);
	ft_printf("\tIncorrect %snum arguments%s present!\n", KRED, KNRM);
	while (argv[++i])
		ft_printf("'%s%s%s' ", KRED, argv[i], KNRM);
	ft_printf("\tPlz have %s'1'%s argument\n\n", KGRN, KNRM);
	exit (1);
}

void	errmsg2(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	ft_putstr_fd("Error\n", 2);
	while (s[i] != '.' && i-- >= 0)
		;
	if (i >= 0)
	{
		ft_printf("\tIncorrect File Extension: '%s", KRED);
		while (i >= 0 && s[i])
		{
			ft_printf("%c", s[i]);
			i++;
		}
		ft_printf("%s'\n", KNRM);
	}
	ft_printf("\tPlz only use '%s.ber%s' files\n\n", KGRN, KNRM);
	exit(1);
}

void	errmsg3(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_printf("\t%sNo content to parse!%s\n", KRED, KNRM);
	exit (1);
}
