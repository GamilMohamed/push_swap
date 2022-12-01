/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/01 06:15:34 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	ft_swap(int *a, int *b)
// {
// 	int	temp;

// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

int	ft_lis(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	j;
	int	*index;
	int	*temptab;
	int	max;
	int	r;

	ft_pushmin(pile_a, pile_b);
	ft_printab((*pile_a), (*pile_b));
	max = 0;
	i = 0;
	j = 0;
	(void)pile_b;
	index = malloc(sizeof(int) * pile_a->size);
	while (i < pile_a->size)
		index[i++] = 1;
	for (i = 1; i < pile_a->size; i++)
		for (j = 0; j < i; j++)
			if (pile_a->tab[i] > pile_a->tab[j] && index[i] < index[j] + 1)
				index[i] = index[j] + 1;
	for (i = 0; i < pile_a->size; i++)
	{
		ft_printf(">>>index[%i]=%i\n", i, index[i]);
		if (max < index[i])
			max = index[i];
	}
	i = 0;
	r = 0;
	j = 1;
	temptab = malloc(sizeof(int) * max);
	while (i < pile_a->size)
	{
		if (j == index[i])
		{
			temptab[r++] = pile_a->tab[i];
			j++;
		}
		i++;
	}
	ft_printf("max=%i\n", max);
	free(index);
	free(temptab);
	return (max);
}

int	main(int ac, char **av)
{
	t_pile	pile_a;
	t_pile	pile_b;

	if (ft_checkacav(ac, av))
		return (1);
	pile_a.tab = ft_argtotab(ac, av);
	if (!pile_a.tab)
		return (0);
	pile_a.total = ac - 1;
	pile_a.size = ac - 1;
	pile_b.tab = malloc(sizeof(int) * pile_a.total);
	pile_b.size = 0;
	ft_printab(pile_a, pile_b);
	// ft_algo(&pile_a, &pile_b);
	// ft_lls(&pile_a, &pile_b);
	ft_lis(&pile_a, &pile_b);
	ft_checksort(&pile_a, &pile_b, pile_a.total);
	return (0);
}
