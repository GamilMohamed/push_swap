/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:10:46 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/08 02:22:57 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->size == 1)
		;
	else if (pile_a->size == 2)
		algo_two(pile_a);
	else if (pile_a->size == 3)
		algo_three(pile_a);
	else if (pile_a->size == 5)
		algo_five(pile_a, pile_b);
	else
		algo_all(pile_a, pile_b);
	ft_checksort(pile_a, pile_b, pile_a->total);
}

void	algo_three(t_pile *pile)
{
	if (pile->tab[0] > pile->tab[1] && pile->tab[1] < pile->tab[2]
		&& pile->tab[0] < pile->tab[2])
		pushswap_swap(pile->size, 'a', pile->tab);
	else if (pile->tab[0] > pile->tab[1] && pile->tab[1] > pile->tab[2]
		&& pile->tab[0] > pile->tab[2])
	{
		pushswap_rotate(pile, 'a', 0);
		pushswap_swap(pile->size, 'a', pile->tab);
	}
	else if (pile->tab[0] > pile->tab[1] && pile->tab[1] < pile->tab[2]
		&& pile->tab[0] > pile->tab[2])
		pushswap_rotate(pile, 'a', 0);
	else if (pile->tab[0] < pile->tab[1] && pile->tab[1] > pile->tab[2]
		&& pile->tab[0] < pile->tab[2])
	{
		pushswap_rrotate(pile, 'a', 0);
		pushswap_swap(pile->size, 'a', pile->tab);
	}
	else if (pile->tab[0] < pile->tab[1] && pile->tab[1] > pile->tab[2]
		&& pile->tab[0] > pile->tab[2])
		pushswap_rrotate(pile, 'a', 0);
}

void	algo_five(t_pile *pile_a, t_pile *pile_b)
{
	ft_pushmin(pile_a, 'a');
	pushswap_push(pile_b, pile_a, 'b', pile_a->tab);
	ft_pushmin(pile_a, 'a');
	pushswap_push(pile_b, pile_a, 'b', pile_a->tab);
	algo_three(pile_a);
	pushswap_push(pile_a, pile_b, 'a', pile_b->tab);
	pushswap_push(pile_a, pile_b, 'a', pile_b->tab);
}

void	algo_two(t_pile *pile_a)
{
	if (pile_a->tab[0] > pile_a->tab[1])
		pushswap_swap(pile_a->size, 'a', pile_a->tab);
}
