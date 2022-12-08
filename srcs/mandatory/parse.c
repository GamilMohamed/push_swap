/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:34:30 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/08 19:49:06 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_double(int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (tab[i] == tab[j])
				return (0);
	}
	return (1);
}

int	ft_freetab(char **tab, int boolean)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	if (boolean)
		return (0);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	*ft_duptab(int *tab, int size)
{
	int	*new;
	int	i;

	if (!ft_double(tab, size))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	new = malloc(sizeof(int) * size);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < size)
		new[i] = tab[i];
	return (new);
}

void	ft_whileresij(char **res, int i)
{
	int	j;

	j = 0;
	while (res[i][j])
	{
		while (res[i][j] == ' ')
			j++;
		if (res[i][j] == '-' || res[i][j] == '+')
			j++;
		if (res[i][j] == '-' || res[i][j] == '+')
			ft_freetab(res, 0);
		while (ft_isdigit(res[i][j]))
			j++;
		if (res[i][j] != '\0')
			ft_freetab(res, 0);
	}
}

int	*parse_args(int ac, char **av, int *size)
{
	int		tab[10000];
	int		index[3];
	char	**res;

	index[0] = 0;
	index[1] = 0;
	while (++index[0] < ac)
	{
		res = ft_split(av[index[0]], ' ');
		if (!res)
			exit(1);
		index[2] = -1;
		while (res[++index[2]])
		{
			if (!ft_isdigit(res[index[2]][0]) && res[index[2]][1] == '\0')
				ft_freetab(res, 0);
			ft_whileresij(res, index[2]);
			if (ft_atoi(res[index[2]]) > 2147483647 || ft_atoi(res[index[2]])
				< -2147483648)
				ft_freetab(res, 0);
			tab[index[1]++] = ft_atoi(res[index[2]]);
		}
		ft_freetab(res, 1);
	}
	return (ft_duptab(tab, *size = index[1]));
}
