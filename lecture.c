/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:16:18 by cbesse            #+#    #+#             */
/*   Updated: 2017/12/22 17:59:21 by cbesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_taille(char **av, t_params *param)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		i++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	param->nline = i;
	close(fd);
}

char	**mise_en_tab(char *str, t_params *param)
{
	int			i;
	static int	flags = 0;
	char		**tab;

	i = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[i])
		(i)++;
	if (i != param->ncolone && flags == 1)
		ft_usage();
	flags = 1;
	param->ncolone = i;
	return (tab);
}

t_tab	*ft_remplisage(char **tab, t_params *param)
{
	t_tab	*tabi;
	int		i;
	int		j;

	i = 0;
	if (!(tabi = (t_tab *)ft_memalloc(sizeof(t_tab) * param->ncolone)))
		return (NULL);
	while (i < param->ncolone)
	{
		tabi[i].z = ft_atoi(tab[i]);
		tabi[i].color = 0xFFFFFF;
		j = -1;
		while (tab[i][++j])
			if (tab[i][j] == ',')
			{
				tabi[i].color = ft_convert(tab[i] + j + 1);
				break ;
			}
		i++;
	}
	return (tabi);
}

t_tab	**ft_lecture(char **av, t_params *param, int i)
{
	char	*line;
	char	**tab;
	t_tab	**tab2;
	int		fd;
	int		j;

	j = 0;
	get_taille(av, param);
	fd = open(av[1], O_RDONLY);
	if (!(tab2 = (t_tab **)ft_memalloc(sizeof(t_tab *) * param->nline)))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		if (!(tab = mise_en_tab(line, param)))
			return (NULL);
		tab2[j++] = ft_remplisage(tab, param);
		i = 0;
		while (tab[i])
			ft_strdel(&tab[i++]);
		ft_memdel((void **)&tab);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (tab2);
}
