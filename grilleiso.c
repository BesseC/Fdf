/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grilleiso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:31:47 by cbesse            #+#    #+#             */
/*   Updated: 2017/12/14 16:16:07 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_horizontaliso(t_params params, t_tab **tab, int j,
	t_point coords)
{
	int			i;
	t_point		point1;
	t_point		point2;
	int			*color;

	if (!(color = (int *)ft_memalloc(sizeof(int) * 2)))
		return ;
	i = 0;
	while (i < params.ncolone - 1)
	{
		set_point(&point1, coords.x, coords.y / 2 +
			(-(tab[j][i].z * params.hauteur)));
		coords.x += params.xcoef / 2;
		coords.y -= params.ycoef / 2;
		set_point(&point2, coords.x, coords.y / 2 +
			(-(tab[j][i + 1].z * params.hauteur)));
		color[0] = tab[j][i].color;
		color[1] = tab[j][i + 1].color;
		params.n = nb_couleur(point1, point2);
		ft_line(point1, point2, params, color);
		i++;
	}
	ft_memdel((void **)&color);
}

static void	ft_verticaliso(t_params params, t_tab **tab, int j, t_point coords)
{
	t_point		point1;
	t_point		point2;
	int			i;
	int			*color;

	if (!(color = (int *)ft_memalloc(sizeof(int) * 2)))
		return ;
	i = 0;
	while (i <= params.ncolone - 1)
	{
		set_point(&point2, coords.x, coords.y / 2 +
			(-(tab[j][i].z * params.hauteur)));
		coords.x -= params.xcoef / 2;
		coords.y -= params.ycoef / 2;
		set_point(&point1, coords.x, coords.y / 2 +
			(-(tab[j - 1][i].z * params.hauteur)));
		color[0] = tab[j - 1][i].color;
		color[1] = tab[j][i].color;
		params.n = nb_couleur(point1, point2);
		ft_line(point1, point2, params, color);
		coords.x += params.xcoef;
		i++;
	}
	ft_memdel((void **)&color);
}

void		ft_grilleiso(t_params params, t_tab **tab)
{
	t_point	coords;
	int		j;

	ft_scaleiso(&params);
	coords.x = params.xdebut;
	j = 1;
	coords.y = params.ydebut;
	ft_horizontaliso(params, tab, 0, coords);
	while (j < params.nline)
	{
		coords.y += params.xcoef / 2;
		coords.x += params.ycoef / 2;
		ft_verticaliso(params, tab, j, coords);
		ft_horizontaliso(params, tab, j, coords);
		j++;
	}
}
