/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/02 10:19:29 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_getsup(t_pile pile_a, t_pile pile_b, int index)
{
	int	i;
	int	sup;
	int max;
	
	i = -1;
	sup = 0;
	max = ft_getmax(pile_a);
	if (pile_b.tab[index] > pile_a.tab[ft_getmax(pile_a)])
		return (sup = ft_getmin(pile_a));
	while (++i < pile_a.size)
		if (pile_a.tab[i] > pile_b.tab[index] && pile_a.tab[max] > pile_a.tab[i])
			max = i;
	return (max);
}

int	ft_rotateprice(t_pile *pile, int index)
{
	int price;

	if (index > pile->size / 2)
		price = pile->size - index;
	else
		price = index;
	return (price);
}

void	ft_pricecalculator(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	j;

	/*cost of b to top*/
	i = ft_getmin((*pile_a));
	j = ft_getmin((*pile_b));
	ft_printf("min->\ta[%i]=%i, b[%i]:%i\n", i, pile_a->tab[i], j,
			pile_b->tab[j]);
	i = ft_getmax((*pile_a));
	j = ft_getmax((*pile_b));
	ft_printf("max->\ta[%i]=%i, b[%i]:%i\n", i, pile_a->tab[i], j,
			pile_b->tab[j]);
	for (int j = 0; j < pile_b->size; j++)
	{
		i = ft_getsup((*pile_a), (*pile_b), j);
		ft_printf("sup of b[%i]=%i is %i\n", j, pile_b->tab[j], pile_a->tab[i]);
	}
	i = 0;
	while (i < pile_a->size)
	{
		j = ft_rotateprice(pile_a, i);
		ft_printf("a->tab[j]:%i(%ie)\n", pile_a->tab[i], j);
		
		i++;
	}
	ft_printf("-----\n");
	i = 0;
	while (i < pile_b->size)
	{
		j = ft_rotateprice(pile_b, i);
		ft_printf("b->tab[j]:%i(%ie)\n", pile_b->tab[i], j);
		
		i++;
	}
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
	ft_algo(&pile_a, &pile_b);
	ft_lis(&pile_a, &pile_b);
	// ft_pushmin(&pile_a, 'a');
	ft_printab(pile_a, pile_b);
	ft_pricecalculator(&pile_a, &pile_b);
	ft_checksort(&pile_a, &pile_b, pile_a.total);
	return (0);
}
