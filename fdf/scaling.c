/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:26:39 by cbesse            #+#    #+#             */
/*   Updated: 2018/03/28 16:02:56 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scaleiso(t_params *params)
{
	params->xdebut = 0;
	params->ydebut = 1024;
	params->hauteur = HAUTEUR;
	if (params->ncolone <= 0 || params->nline <= 0)
		ft_usage();
	if ((params->xcoef = 1024 / params->ncolone) % 2 == 1)
		params->xcoef--;
	if ((params->ycoef = 1024 / params->nline) % 2 == 1)
		params->ycoef--;
	if (params->xcoef < params->ycoef)
		params->ycoef = params->xcoef;
	if (params->ycoef < params->xcoef)
		params->xcoef = params->ycoef;
}
