/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:10:46 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/29 04:14:05 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	ft_pushmin(pile_a, pile_b);
	algo_three(pile_a);
	pa();
	pa();
}
