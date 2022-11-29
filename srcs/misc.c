/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 05:47:02 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/29 04:14:37 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_aintnumeric(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if ((s[i] < '0' || s[i] > '9') && ((s[i] != ' ') && (s[i] != '-')
				&& (s[i] != '+')))
			return (1);
	}
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
			return (ft_printf("%bOne of the args ain't numeric%0\n"));
	i = 0;
	while (av[++i])
	{
		j = i;
		while (av[++j])
			if (ft_strcmp(av[i], av[j]) == 0)
				return (ft_printf("%rFound duplicate%0\n"));
	}
	return (0);
}

int	*ft_argtotab(int ac, char **av)
{
	int	*tab;
	int	i;

	i = -1;
	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	while (++i < ac - 1)
		tab[i] = ft_atoi(av[i + 1]);
	return (tab);
}

void	ft_checksort(t_pile *pile_a, t_pile *pile_b, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < pile_a->size)
	{
		j = i + 1;
		while (j < pile_a->size)
		{
			if (pile_a->tab[i] > pile_a->tab[j])
				ft_exit(pile_a, pile_b, 0);
			j++;
		}
		i++;
	}
	if (i == size)
		ft_exit(pile_a, pile_b, 1);
	ft_exit(pile_a, pile_b, 0);
}

void	ft_exit(t_pile *pile_a, t_pile *pile_b, int boolean)
{
	free(pile_a->tab);
	free(pile_b->tab);
	if (boolean)
		ft_printf("%gSuccessfully sorted%0\n");
	else
		ft_printf("%rSort failed%0\n");
	exit(EXIT_SUCCESS);
}
