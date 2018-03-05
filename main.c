/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:25:10 by cbesse            #+#    #+#             */
/*   Updated: 2017/12/22 18:00:16 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_usage(void)
{
	ft_putstr("usage : ./mlx carte_valide [face]\n");
	exit(1);
}

void	verif(int ac, char **av)
{
	int		fd;
	char	c;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			close(fd);
			ft_usage();
		}
		if (read(fd, &c, 0) == -1)
		{
			close(fd);
			ft_usage();
		}
	}
}

int		main(int ac, char **av)
{
	t_params	params;
	t_tab		**tab;

	if (ac == 1)
		ft_usage();
	verif(ac, av);
	tab = ft_lecture(av, &params, 0);
	params.mlx = mlx_init();
	params.win = mlx_new_window(params.mlx, 1024, 1024, "Fdf");
	if (ac == 2)
		ft_grilleiso(params, tab);
	if (ac >= 3)
	{
		if (ft_strcmp(av[2], "face") == 0)
			ft_grilleface(params, tab);
		else
			ft_grilleiso(params, tab);
	}
	mlx_key_hook(params.win, my_key_funct, &params);
	mlx_loop(params.mlx);
	return (0);
}
