/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/04 04:09:07 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rotateprice(t_pile *pile, int index)
{
	int	price;

	if (index > pile->size / 2)
		price = pile->size - index;
	else
		price = -index;
	return (price);
}

int	ft_totalprice(int price_a, int price_b)
{
	int	a;
	int	b;

	a = abs(price_a);
	b = abs(price_b);
	if ((price_a < 0 && price_b < 0) || (price_a > 0 && price_b > 0))
	{
		if (a >= b)
			return (a);
		else
			return (b);
	}
	return (a + b);
}

int	ft_domovement(t_pile *pile_a, t_pile *pile_b, int index[5])
{
	if (!index[0])
		return (pushswap_push(pile_a, pile_b, 'a', pile_b->tab));
	while (index[1] > 0)
	{
		if (index[2] > 0)
			pushswap_rrr(pile_a, pile_b, index[2]--);
		else
			pushswap_rrotate(pile_a, 'a', index[1]);
		index[1]--;
	}
	while (index[2] > 0)
		pushswap_rrotate(pile_b, 'b', index[2]--);
	while (index[1] < 0)
	{
		if (index[2] < 0)
			pushswap_rr(pile_a, pile_b, index[2]++);
		else
			pushswap_rotate(pile_a, 'a', index[1]);
		index[1]++;
	}
	while (index[2] < 0)
		pushswap_rotate(pile_b, 'b', index[2]++);
	return (pushswap_push(pile_a, pile_b, 'a', pile_b->tab));
}

void	ft_pricecalculator(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	*total;
	int	index[6];

	total = malloc(sizeof(int) * pile_b->size);
	while (pile_b->size != 0)
	{
		i = -1;
		index[0] = 2147483647;
		while (++i < pile_b->size)
		{
			index[5] = ft_getsup((*pile_a), (*pile_b), i);
			index[3] = ft_rotateprice(pile_b, i);
			index[4] = ft_rotateprice(pile_a, index[5]);
			total[i] = ft_totalprice(index[3], index[4]);
			if (index[0] > total[i])
			{
				index[0] = total[i];
				index[1] = index[4];
				index[2] = index[3];
			}
		}
		ft_domovement(pile_a, pile_b, index);
	}
	free(total);
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
	if (!pile_b.tab)
	{
		free(pile_a.tab);
		exit(EXIT_FAILURE);
	}
	pile_b.size = 0;
	ft_lis(&pile_a, &pile_b);
	ft_pricecalculator(&pile_a, &pile_b);
	ft_pushmin(&pile_a, 'a');
	ft_checksort(&pile_a, &pile_b, pile_a.total);
	return (0);
}
