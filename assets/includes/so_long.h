/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:20:20 by wismith           #+#    #+#             */
/*   Updated: 2022/04/22 19:53:28 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SO_LONG_H
# define SO_LONG_H

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define KCLR  "\e[1;1H\e[2J"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include "../mlx/mlx.h"

typedef struct s_img
{
	void	*p;
	void	*c;
	void	*e;
	void	*f;
	void	*w;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	char	**matrix;
	int		height;
	int		width;
	int		cflag;
	int		p;
	int		e;
	int		x;
	int		y;
}	t_mlx;

//Error management
void	errmsg1(char **argv);
void	errmsg2(char *s);
void	errmsg3(void);
void	errmsg4(t_mlx *mlx);
void	errmsg5(char *str, char *buff);
int		sqrerrmsg(void);
int		wallintegcomp(void);
void	objcheck(t_mlx *mlx);
int		freedom(t_mlx *mlx);
char	*nlcheck(char *str, char *buff);
int		sqrcheck(char **matrix);
void	check_extension(char *s);

//parser
void	parser(char *path, t_mlx *mlx);

//Window Operations
void	set_win(t_mlx mlx);
void	start(t_mlx *mlx);
int		moves(int keycode, t_mlx *mlx);
void	des_imgs(t_mlx *mlx);
int		terminate(t_mlx *mlx);
void	terminate_success(t_mlx *mlx);

//objects
void	*character(t_mlx *mlx);
void	*wall(t_mlx *mlx);
void	*floored(t_mlx *mlx);
void	*collectable(t_mlx *mlx);
void	*exited(t_mlx *mlx);

//moves
int		up(t_mlx *mlx);
int		down(t_mlx *mlx);
int		right(t_mlx *mlx);
int		left(t_mlx *mlx);

//count flag
int		num_collectable(t_mlx *mlx);
#endif
