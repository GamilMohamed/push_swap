/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:19:40 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/08 02:23:15 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getmin(t_pile pile)
{
	int	i;
	int	temp;
	int	ret;

	i = 0;
	ret = 0;
	temp = pile.tab[i];
	while (i < pile.size)
	{
		if (temp > pile.tab[i])
		{
			temp = pile.tab[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

int	ft_getmax(t_pile pile)
{
	int	i;
	int	temp;
	int	ret;

	i = 0;
	ret = 0;
	temp = pile.tab[i];
	while (i < pile.size)
	{
		if (temp < pile.tab[i])
		{
			temp = pile.tab[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

int	ft_sup(t_pile pile_a, t_pile pile_b, int index)
{
	int	i;
	int	sup;
	int	max;

	i = -1;
	sup = 0;
	max = ft_getmax(pile_a);
	if (pile_b.tab[index] > pile_a.tab[ft_getmax(pile_a)])
		return (sup = ft_getmin(pile_a));
	while (++i < pile_a.size)
		if (pile_a.tab[i] > pile_b.tab[index]
			&& pile_a.tab[max] > pile_a.tab[i])
			max = i;
	return (max);
}

int	abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}
