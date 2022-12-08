/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:38:54 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/08 18:34:56 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_gettab(t_pile *pile_a, t_pile *pile_b)
{
	int	*tab;
	int	i;
	int	r;

	tab = malloc(sizeof(int) * pile_a->size);
	if (!tab)
		ft_exit(pile_a, pile_b, 2);
	i = -1;
	while (++i < pile_a->size)
		tab[i] = pile_a->tab[i];
	i = 0;
	while (i < pile_a->size)
	{
		r = i;
		while (++r < pile_a->size)
			if (tab[i] > tab[r])
				ft_swap(&tab[i], &tab[r], sizeof(int));
		i++;
	}
	return (tab);
}

void	ft_tabtopileb(t_pile *pile_a, t_pile *pile_b)
{
	int	j;
	int	*tab;
	int	median;

	tab = ft_gettab(pile_a, pile_b);
	median = tab[pile_a->size / 2];
	if (pile_a->size > 100)
		median = tab[(pile_a->size / 7) * 2];
	free(tab);
	while (pile_a->size != 3)
	{
		j = 0;
		if (pile_a->tab[j] >= median)
		{
			pushswap_push(pile_b, pile_a, 'b', pile_a->tab);
			tab = ft_gettab(pile_a, pile_b);
			median = tab[(pile_a->size / 7) * 5];
			free(tab);
		}
		else
			pushswap_rotate(pile_a, 'a', j++);
	}
	algo_three(pile_a);
}

void	algo_all(t_pile *pile_a, t_pile *pile_b)
{
	ft_tabtopileb(pile_a, pile_b);
	ft_pricecalculator(pile_a, pile_b);
	ft_pushmin(pile_a, 'a');
}
