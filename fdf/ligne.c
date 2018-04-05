/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:09:32 by cbesse            #+#    #+#             */
/*   Updated: 2017/12/13 15:34:49 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_funct(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}

void	ft_line3(t_point point1, t_point point2, t_params param, int *color)
{
	float	a;
	float	b;
	float	d;
	int		i;
	int		n;

	n = nb_couleur(point1, point2);
	i = 0;
	a = (float)(point2.y - point1.y) / (point2.x - point1.x);
	b = point1.y - (float)(a * point1.x);
	while (point1.y < point2.y && fabs(a) >= 1)
	{
		d = (b - point1.y) / -a;
		mlx_pixel_put(param.mlx, param.win, d, point1.y,
			ft_tcouleur(color[1], color[0], param.n, i++));
		point1.y += 1;
	}
	while (point2.y < point1.y && fabs(a) >= 1)
	{
		d = (b - point2.y) / -a;
		mlx_pixel_put(param.mlx, param.win, d, point2.y,
			ft_tcouleur(color[0], color[1], param.n, i++));
		point2.y += 1;
	}
}

void	ft_line2(t_point point1, t_point point2, t_params param, int *color)
{
	int	i;
	int	n;

	n = nb_couleur(point1, point2);
	i = 0;
	if (point1.x == point2.x)
	{
		while (point1.y < point2.y)
		{
			mlx_pixel_put(param.mlx, param.win, point1.x, point1.y,
				ft_tcouleur(color[0], color[1], param.n, i++));
			point1.y++;
		}
		while (point2.y < point1.y)
		{
			mlx_pixel_put(param.mlx, param.win, point1.x, point2.y,
				ft_tcouleur(color[0], color[1], param.n, i++));
			point2.y++;
		}
	}
	if (point1.x == point2.x && point1.y == point2.y)
		mlx_pixel_put(param.mlx, param.win, point1.x, point1.y, color[0]);
}

void	ft_line(t_point point1, t_point point2, t_params param, int *color)
{
	float	a;
	float	b;
	float	d;
	int		i;

	i = 0;
	a = (float)(point2.y - point1.y) / (point2.x - point1.x);
	b = point1.y - (float)(a * point1.x);
	ft_line2(point1, point2, param, color);
	while (point1.x < point2.x && fabs(a) < 1)
	{
		d = a * point1.x + b;
		mlx_pixel_put(param.mlx, param.win, point1.x, d,
			ft_tcouleur(color[0], color[1], param.n, i++));
		point1.x += 1;
	}
	while (point2.x < point1.x && fabs(a) < 1)
	{
		d = a * point2.x + b;
		mlx_pixel_put(param.mlx, param.win, point2.x, d,
			ft_tcouleur(color[0], color[1], param.n, i++));
		point2.x += 1;
	}
	ft_line3(point1, point2, param, color);
}

void	set_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}
