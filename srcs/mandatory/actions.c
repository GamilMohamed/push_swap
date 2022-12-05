/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:15:51 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/05 01:00:41 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pushswap_rotate(t_pile *pile, char c, int x)
{
	int	first;

	(void)x;
	if (!pile->size)
		return ;
	first = pile->tab[pile->size - 1];
	first = pile->tab[0];
	ft_rotateup(pile);
	pile->tab[pile->size - 1] = first;
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
	else if (c == '0')
		ft_printf("rr\n");
}

void	pushswap_rrotate(t_pile *pile, char c, int x)
{
	int	last;

	(void)x;
	if (!pile->size)
		return ;
	last = pile->tab[pile->size - 1];
	ft_rotatedown(pile);
	pile->tab[0] = last;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
	else if (c == '0')
		ft_printf("rrr\n");
}

int	pushswap_push(t_pile *dest, t_pile *src, char c, int *tab)
{
	int	temp;
	int	i;

	if (!src->size)
		return (ft_printf("%r\t\tpush %c FAILED%0\n", c));
	temp = src->size--;
	dest->size++;
	ft_rotatedown(dest);
	dest->tab[0] = tab[0];
	i = 0;
	while (++i < temp)
		tab[i - 1] = tab[i];
	return (ft_printf("p%c\n", c));
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
	ft_printf("s%c\n", c);
}
