/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:10:33 by mgamil            #+#    #+#             */
/*   Updated: 2023/04/03 03:33:00 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_domovement(t_pile *pile_a, t_pile *pile_b, int best_price_a, int best_price_b)
{
	while (best_price_b > 0)
	{
		if (best_price_a > 0)
			pushswap_rrr(pile_a, pile_b, best_price_a--);
		else
			pushswap_rrotate(pile_a, 'a', best_price_b);
		best_price_b--;
	}
	while (best_price_a > 0)
		pushswap_rrotate(pile_b, 'b', best_price_a--);
	while (best_price_b < 0)
	{
		if (best_price_a < 0)
			pushswap_rr(pile_a, pile_b, best_price_a++);
		else
			pushswap_rotate(pile_a, 'a', best_price_b);
		best_price_b++;
	}
	while (best_price_a < 0)
		pushswap_rotate(pile_b, 'b', best_price_a++);
	return (pushswap_push(pile_a, pile_b, 'a', pile_b->tab));
}

void	ft_pricecalculator(t_pile *pile_a, t_pile *pile_b)
{
	int	*total;
	int	i;
	int	price_a;
	int	price_b;
	int	best_price_a;
	int	best_price_b;
	int	max;

	total = malloc(sizeof(int) * pile_b->size);
	if (!total)
		ft_exit(pile_a, pile_b, 2);
	while (pile_b->size != 0)
	{
		i = -1;
		max = 2147483647;
		while (++i < pile_b->size)
		{
			price_a = ft_price(pile_b, i);
			price_b = ft_price(pile_a, ft_sup((*pile_a), (*pile_b), i));
			total[i] = ft_totalprice(price_a, price_b);
			if (max > total[i])
			{
				max = total[i];
				best_price_b = price_b;
				best_price_a = price_a;
			}
		}
		ft_domovement(pile_a, pile_b, best_price_a, best_price_b);
	}
	free(total);
}
