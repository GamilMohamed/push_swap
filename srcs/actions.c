/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:15:51 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/29 04:11:32 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pushswap_rotate(t_pile *pile, char c)
{
	int	first;

	if (!pile->size)
		return ;
	first = pile->tab[pile->size - 1];
	first = pile->tab[0];
	ft_rotateup(pile);
	pile->tab[pile->size - 1] = first;
	ft_printf("%m\t\trotate %c%0\n", c);
}

void	pushswap_rrotate(t_pile *pile, char c)
{
	int	last;

	if (!pile->size)
		return ;
	last = pile->tab[pile->size - 1];
	ft_rotatedown(pile);
	pile->tab[0] = last;
	ft_printf("%m\t\treverse rotate %c%0\n", c);
}

void	pushswap_push(t_pile *dest, t_pile *src, char c, int *tab)
{
	int	temp;
	int	i;

	if (!src->size)
	{
		ft_printf("%r\t\tpush %c FAILED%0\n", c);
		return ;
	}
	temp = src->size--;
	dest->size++;
	ft_rotatedown(dest);
	dest->tab[0] = tab[0];
	i = 0;
	while (++i < temp)
		tab[i - 1] = tab[i];
	ft_printf("%m\t\tpush %c%0\n", c);
}

void	pushswap_swap(int size, char c, int *tab)
{
	int	temp;

	if (!size)
		return ;
	if (size < 2)
	{
		ft_printf("%r\t\tswap %c failed%0\n", c);
		return ;
	}
	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
	ft_printf("%m\t\tswap %c%0\n", c);
}
