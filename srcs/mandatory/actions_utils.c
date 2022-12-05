/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:26:22 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/05 01:00:46 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_pushmin(t_pile *pile, char c)
{
	if (ft_getmin((*pile)) > pile->size / 2)
		while (ft_getmin((*pile)) != 0)
			pushswap_rrotate(pile, c, c);
	else
		while (ft_getmin((*pile)) != 0)
			pushswap_rotate(pile, c, c);
}

void	pushswap_rrr(t_pile *pile_a, t_pile *pile_b, int x)
{
	int	r;

	r = 0;
	pushswap_rrotate(pile_a, '0', r);
	pushswap_rrotate(pile_b, 'x', x--);
}

void	pushswap_rr(t_pile *pile_a, t_pile *pile_b, int x)
{
	int	r;

	r = 0;
	pushswap_rotate(pile_a, '0', r);
	pushswap_rotate(pile_b, 'x', x--);
}
