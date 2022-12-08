/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:15:51 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/08 02:22:57 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	pushswap_rotate(t_pile *pile)
{
	int	first;

	if (!pile->size)
		return (1);
	first = pile->tab[pile->size - 1];
	first = pile->tab[0];
	ft_rotateup(pile);
	pile->tab[pile->size - 1] = first;
	return (1);
}

int	pushswap_rrotate(t_pile *pile)
{
	int	last;

	if (!pile->size)
		return (1);
	last = pile->tab[pile->size - 1];
	ft_rotatedown(pile);
	pile->tab[0] = last;
	return (1);
}

int	pushswap_push(t_pile *dest, t_pile *src, int *tab)
{
	int	temp;
	int	i;

	if (!src->size)
		return (1);
	temp = src->size--;
	dest->size++;
	ft_rotatedown(dest);
	dest->tab[0] = tab[0];
	i = 0;
	while (++i < temp)
		tab[i - 1] = tab[i];
	return (1);
}

int	pushswap_swap(int size, int *tab)
{
	int	temp;

	if (!size || size < 2)
		return (1);
	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
	return (1);
}

int	pushswap_ss(t_pile *pile_a, t_pile *pile_b)
{
	if (!pile_a->size || pile_a->size < 2 || !pile_b->size || pile_b->size < 2)
		return (1);
	pushswap_swap(pile_a->size, pile_a->tab);
	pushswap_swap(pile_b->size, pile_b->tab);
	return (1);
}
