/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:38:54 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/04 21:47:39 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

int	*ft_tabindex(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	j;
	int	*index;
	int	max;

	max = 0;
	i = 0;
	index = malloc(sizeof(int) * pile_a->size);
	if (!index)
		ft_exit(pile_a, pile_b, 2);
	while (i < pile_a->size)
		index[i++] = 1;
	i = 0;
	while (++i < pile_a->size)
	{
		j = -1;
		while (++j < i)
			if (pile_a->tab[i] > pile_a->tab[j] && index[i] < index[j] + 1)
				index[i] = index[j] + 1;
	}
	return (index);
}

int	*ft_sequence(t_pile *pile_a, t_pile *pile_b, int *tabindex, int *max)
{
	int	i;
	int	r;
	int	*temptab;

	(*max) = 0;
	r = 0;
	i = -1;
	while (++i < pile_a->size)
		if ((*max) < tabindex[i])
			(*max) = tabindex[i];
	i = pile_a->size;
	r = (*max);
	temptab = malloc(sizeof(int) * r);
	if (!temptab)
		ft_exit(pile_a, pile_b, 2);
	while (r > 0 && i--)
		if (r == tabindex[i])
			temptab[--r] = pile_a->tab[i];
	free(tabindex);
	return (temptab);
}

int	ft_intab(int j, int *tabindex, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (tabindex[i] == j)
			return (1);
		i++;
	}
	return (0);
}

void	ft_tabtopileb(t_pile *pile_a, t_pile *pile_b, int *tabindex, int max)
{
	int	j;

	while (pile_a->size != max)
	{
		j = 0;
		if (!ft_intab(pile_a->tab[j], tabindex, max))
			pushswap_push(pile_b, pile_a, 'b', pile_a->tab);
		else
		{
			pushswap_rotate(pile_a, 'a', j);
			j++;
		}
	}
}

int	ft_lis(t_pile *pile_a, t_pile *pile_b)
{
	int	*tabindex;
	int	max;

	tabindex = ft_tabindex(pile_a, pile_b);
	tabindex = ft_sequence(pile_a, pile_b, tabindex, &max);
	ft_tabtopileb(pile_a, pile_b, tabindex, max);
	free(tabindex);
	return (0);
}
