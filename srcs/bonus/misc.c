/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 05:47:02 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/08 18:25:32 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ft_checksortav(t_pile *pile_a, int size)
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
				return ;
			j++;
		}
		i++;
	}
	if (i == size)
	{
		free(pile_a->tab);
		exit(1);
	}
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
	if (boolean == 1)
		ft_printf("OK\n");
	else if (boolean == 2)
		ft_printf("%rmalloc failed%0\n");
	else if (boolean == 3)
		ft_putstr_fd("Error\n", 2);
	else
		ft_printf("KO\n");
	exit(EXIT_SUCCESS);
}
