/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:44:58 by cbesse            #+#    #+#             */
/*   Updated: 2017/12/22 18:02:51 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <math.h>
# include "libft/includes/libft.h"
# define HAUTEUR 2
# define COEFX 5
# define COEFY 8

typedef struct	s_point
{
	float x;
	float y;
}				t_point;
typedef struct	s_tab
{
	int	z;
	int	color;
}				t_tab;
typedef	struct	s_params
{
	void	*mlx;
	void	*win;
	int		nline;
	int		ncolone;
	int		n;
	int		xdebut;
	int		ydebut;
	int		xcoef;
	int		ycoef;
	int		hauteur;
}				t_params;
t_tab			**ft_lecture(char **av, t_params *param, int i);
void			ft_grilleface(t_params params, t_tab **tab);
void			ft_line(t_point point1, t_point point2,
	t_params param, int *color);
void			set_point(t_point *point, int x, int y);
int				ft_convert(char *str);
int				*ft_color(int color1, int color2, int n);
int				nb_couleur(t_point point1, t_point point2);
int				ft_tcouleur(int color1, int color2, int n, int i);
void			ft_grilleiso(t_params params, t_tab **tab);
void			ft_scaleiso(t_params *params);
int				my_key_funct(int keycode);
void			ft_usage(void);
#endif
