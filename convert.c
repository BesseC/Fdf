/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:16:44 by cbesse            #+#    #+#             */
/*   Updated: 2017/12/22 17:58:26 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		find_nbr(char c)
{
	if (c == 'A' || c == 'a')
		return (10);
	if (c == 'B' || c == 'b')
		return (11);
	if (c == 'C' || c == 'c')
		return (12);
	if (c == 'D' || c == 'd')
		return (13);
	if (c == 'E' || c == 'e')
		return (14);
	if (c == 'F' || c == 'f')
		return (15);
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (0);
}

int		ft_convert(char *str)
{
	int	i;
	int	total;
	int	tmp;

	i = 2;
	total = 0;
	if (str[0] != '0' && str[1] != 'x')
		return (0);
	while (str[i] && i != 8)
	{
		tmp = find_nbr(str[i]);
		total = total * 16 + tmp;
		i++;
	}
	return (total);
}
