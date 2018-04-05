/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:21:32 by cbesse            #+#    #+#             */
/*   Updated: 2018/03/28 11:58:10 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_horizontal(t_params params, t_tab **tab, int y, int j)
{
	int			i;
	t_point		point1;
	t_point		point2;
	int			x;
	int			*color;

	if (!(color = (int *)ft_memalloc(sizeof(int) * 2)))
		return ;
	x = COEFX;
	i = 0;
	while (i < params.ncolone - 1)
	{
		set_point(&point2, x, y + (-(tab[j][i].z * HAUTEUR)));
		x = x + COEFX;
		set_point(&point1, x, (-(tab[j][i + 1].z * HAUTEUR)) + y);
		color[1] = tab[j][i].color;
		color[0] = tab[j][i + 1].color;
		params.n = nb_couleur(point1, point2);
		ft_line(point1, point2, params, color);
		i++;
	}
	ft_memdel((void **)&color);
}

void	ft_vertical(t_params params, t_tab **tab, int y, int j)
{
	t_point		point1;
	t_point		point2;
	int			i;
	int			x;
	int			*color;

	if (!(color = (int *)ft_memalloc(sizeof(int) * 2)))
		return ;
	i = 0;
	x = COEFX;
	while (i <= params.ncolone - 1)
	{
		set_point(&point2, x, y + (-(tab[j - 1][i].z * HAUTEUR)) - COEFY);
		set_point(&point1, x, (-(tab[j][i].z * HAUTEUR)) + y);
		color[1] = tab[j - 1][i].color;
		color[0] = tab[j][i].color;
		params.n = nb_couleur(point1, point2);
		ft_line(point1, point2, params, color);
		x = x + COEFX;
		i++;
	}
	ft_memdel((void **)&color);
}

void	ft_grilleface(t_params params, t_tab **tab)
{
	int y;
	int j;

	j = 1;
	y = 100;
	ft_horizontal(params, tab, y, 0);
	if (params.nline == 0)
		ft_usage();
	while (j < params.nline)
	{
		y = y + COEFY;
		ft_vertical(params, tab, y, j);
		ft_horizontal(params, tab, y, j);
		j++;
	}
}
