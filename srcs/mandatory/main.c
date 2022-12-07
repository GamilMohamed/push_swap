/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/08 00:24:28 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkacav(int ac, char **av)
{
	int	i;
	int	k;

	i = 0;
	while (++i < ac)
	{
		k = 0;
		while (av[i][k] == ' ' && av[i][k] != '\0')
			k++;
		if (av[i][k] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_pile	pile_a;
	t_pile	pile_b;
	int		size;

	if (ac < 2)
		return (1);
	if (ft_checkacav(ac, av))
		return (1);
	pile_a.tab = parse_args(ac, av, &size);
	if (!pile_a.tab)
		return (0);
	pile_a.total = size;
	pile_a.size = size;
	ft_checksortav(&pile_a, size);
	pile_b.tab = malloc(sizeof(int) * pile_a.total);
	if (!pile_b.tab)
	{
		free(pile_a.tab);
		exit(EXIT_FAILURE);
	}
	pile_b.size = 0;
	ft_algo(&pile_a, &pile_b);
	return (0);
}
