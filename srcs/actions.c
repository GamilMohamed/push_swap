/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:15:51 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/26 11:36:10 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pushswap_rotate(t_pile *pile, char c)
{
	int	first;

	first = pile->tab[0];
	ft_rotateup(pile);
	pile->tab[pile->size - 1] = first;
	ft_printf("%m\t\trotate %c%0\n", c);
}

void	pushswap_rrotate(t_pile *pile, char c)
{
	int	last;
	last = pile->tab[pile->size - 1];
	ft_rotatedown(pile);
	pile->tab[0] = last;
	ft_printf("%m\t\treverse rotate %c%0\n", c);
}

void	pushswap_push(t_pile *src, t_pile *dest, char c)
{
	int	temp;
	int	i;

	if (!src)
		return ;
	ft_rotatedown(dest);
	dest->tab[0] = src->tab[0];
	dest->size++;
	temp = src->size--;
	i = 0;
	while (++i < temp)
		src->tab[i - 1] = src->tab[i];
	ft_printf("%m\t\tpush %c%0\n", c);
}

int	pushswap_swap(t_pile *pile, char c)
{
	int	temp;

	if (pile->size < 2)
		return (ft_printf("%r\t\tswap %c failed%0\n", c));
	temp = pile->tab[0];
	pile->tab[0] = pile->tab[1];
	pile->tab[1] = temp;
	ft_printf("%m\t\tswap %c%0\n", c);
	return (0);
}
