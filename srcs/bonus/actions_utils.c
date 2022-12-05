/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:26:22 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/04 23:53:10 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	ft_rotatedown(t_pile *pile)
{
	int	temp;

	temp = pile->size;
	while (--temp > 0)
		pile->tab[temp] = pile->tab[temp - 1];
}

void	ft_rotateup(t_pile *pile)
{
	int	temp;

	temp = -1;
	while (++temp < pile->size - 1)
		pile->tab[temp] = pile->tab[temp + 1];
}

void	ft_pushmin(t_pile *pile)
{
	if (ft_getmin((*pile)) > pile->size / 2)
		while (ft_getmin((*pile)) != 0)
			pushswap_rrotate(pile);
	else
		while (ft_getmin((*pile)) != 0)
			pushswap_rotate(pile);
}

int	pushswap_rrr(t_pile *pile_a, t_pile *pile_b)
{
	if (!pile_b->size || !pile_a->size)
		return (1);
	pushswap_rrotate(pile_a);
	pushswap_rrotate(pile_b);
	return (1);
}

int	pushswap_rr(t_pile *pile_a, t_pile *pile_b)
{
	if (!pile_b->size || !pile_a->size)
		return (1);
	pushswap_rotate(pile_a);
	pushswap_rotate(pile_b);
	return (1);
}
