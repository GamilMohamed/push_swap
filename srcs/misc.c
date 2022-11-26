/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 05:47:02 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/26 11:36:43 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_aintnumeric(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if ((s[i] < '0' || s[i] > '9') && (s[i] != ' '))
			return (1);
	return (0);
}

int	ft_checkacav(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		return (ft_printf("%m./pushswap $ARGS%0\n"));
	while (av[++i])
		if (ft_aintnumeric(av[i]))
			return (ft_printf("%bone of the args ain't numeric%0\n"));
	i = 0;
	while (av[++i])
	{
		j = i;
		while (av[++j])
			if (ft_strcmp(av[i], av[j]) == 0)
				return (ft_printf("%rfound duplicate%0\n"));
	}
	return (0);
}

int	*ft_argtotab(int ac, char **av)
{
	int	*tab;
	int	i;

	i = -1;
	tab = malloc(sizeof(int) * (ac -1));
	if (!tab)
		return (0);
	while (++i < ac - 1)
		tab[i] = ft_atoi(av[i + 1]);
	return (tab);
}

int	ft_checksort(t_pile pile)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < pile.size)
	{
		j = i + 1;
		while (j < pile.size)
		{
			if (pile.tab[i] < pile.tab[j])
				k++;
			j++;
		}
		i++;
	}
	if (k == pile.size)
		return (1);
	return (0);
}