/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:10:33 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/06 19:26:23 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_price(t_pile *pile, int index)
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
	int	*total;
	int	index[6];

	total = malloc(sizeof(int) * pile_b->size);
	if (!total)
		ft_exit(pile_a, pile_b, 2);
	while (pile_b->size != 0)
	{
		index[5] = -1;
		index[0] = 2147483647;
		while (++index[5] < pile_b->size)
		{
			index[3] = ft_price(pile_b, index[5]);
			index[4] = ft_price(pile_a, ft_sup((*pile_a), (*pile_b), index[5]));
			total[index[5]] = ft_totalprice(index[3], index[4]);
			if (index[0] > total[index[5]])
			{
				index[0] = total[index[5]];
				index[1] = index[4];
				index[2] = index[3];
			}
		}
		ft_domovement(pile_a, pile_b, index);
	}
	free(total);
}
