/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:10:46 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/02 07:40:33 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_algo(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->size == 3)
		algo_three(pile_a);
	else if (pile_a->size == 5)
		algo_five(pile_a, pile_b);
	else if (pile_a->size == 100)
		algo_hundred(pile_a, pile_b);
}

void	algo_three(t_pile *pile)
{
	if (pile->tab[0] > pile->tab[1] && pile->tab[1] < pile->tab[2]
		&& pile->tab[0] < pile->tab[2])
		pushswap_swap(pile->size, 'a', pile->tab);
	else if (pile->tab[0] > pile->tab[1] && pile->tab[1] > pile->tab[2]
		&& pile->tab[0] > pile->tab[2])
	{
		pushswap_rotate(pile, 'a');
		pushswap_swap(pile->size, 'a', pile->tab);
	}
	else if (pile->tab[0] > pile->tab[1] && pile->tab[1] < pile->tab[2]
		&& pile->tab[0] > pile->tab[2])
		pushswap_rotate(pile, 'a');
	else if (pile->tab[0] < pile->tab[1] && pile->tab[1] > pile->tab[2]
		&& pile->tab[0] < pile->tab[2])
	{
		pushswap_rrotate(pile, 'a');
		pushswap_swap(pile->size, 'a', pile->tab);
	}
	else if (pile->tab[0] < pile->tab[1] && pile->tab[1] > pile->tab[2]
		&& pile->tab[0] > pile->tab[2])
		pushswap_rrotate(pile, 'a');
}

void	algo_five(t_pile *pile_a, t_pile *pile_b)
{
	ft_pushmin(pile_a, pile_b);
	pb();
	ft_pushmin(pile_a, pile_b);
	pb();
	algo_three(pile_a);
	pa();
	pa();
}

void	algo_hundred(t_pile *pile_a, t_pile *pile_b)
{
	while (pile_a->size != 0)
	{
		ft_pushmin(pile_a, pile_b);
		pb();
	}
	while (pile_a->size != 100)
		pushswap_push(pile_a, pile_b, 'a', pile_b->tab);
}
