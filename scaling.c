/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:26:39 by cbesse            #+#    #+#             */
/*   Updated: 2017/12/22 17:59:01 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scaleiso(t_params *params)
{
	params->xdebut = 0;
	params->ydebut = 1024;
	params->hauteur = HAUTEUR;
	if ((params->xcoef = 1024 / params->ncolone) % 2 == 1)
		params->xcoef--;
	if ((params->ycoef = 1024 / params->nline) % 2 == 1)
		params->ycoef--;
	if (params->xcoef < params->ycoef)
		params->ycoef = params->xcoef;
	if (params->ycoef < params->xcoef)
		params->xcoef = params->ycoef;
}
