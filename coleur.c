/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coleur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:21:31 by cbesse            #+#    #+#             */
/*   Updated: 2017/12/18 15:21:27 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	nb_couleur(t_point point1, t_point point2)
{
	float a;

	a = (float)(point2.y - point1.y) / (point2.x - point1.x);
	if (point1.x < point2.x && fabs(a) < 1)
		return (fabsf(point2.x - point1.x));
	if (point2.x < point1.x && fabs(a) < 1)
		return (fabsf(point1.x - point2.x));
	if (point1.y < point2.y && fabs(a) >= 1)
		return (fabsf(point2.y - point1.y));
	if (point2.y < point1.y && fabs(a) >= 1)
		return (fabsf(point1.y - point2.y));
	return (0);
}

int	ft_tcouleur(int color1, int color2, int n, int i)
{
	int c1[3];
	int c2[3];
	int r;
	int v;
	int b;

	c1[0] = (color1 & 0xFF0000) / (256 * 256);
	c2[0] = (color2 & 0xFF0000) / (256 * 256);
	c1[1] = (color1 & 0x00FF00) / 256;
	c2[1] = (color2 & 0x00FF00) / 256;
	c1[2] = color1 & 0x0000FF;
	c2[2] = color2 & 0x0000FF;
	r = ((c1[0] - c2[0]) / n) * i + c2[0];
	v = ((c1[1] - c2[1]) / n) * i + c2[1];
	b = ((c1[2] - c2[2]) / n) * i + c2[2];
	return (r * 256 * 256 + v * 256 + b);
}
