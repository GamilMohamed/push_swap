/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:38:54 by mgamil            #+#    #+#             */
/*   Updated: 2023/04/03 03:25:57 by mgamil           ###   ########.fr       */
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

	while (pile_a->size != 3)
	{
		pushswap_push(pile_b, pile_a, 'b', pile_a->tab);
	}
	algo_three(pile_a);
}

void	algo_all(t_pile *pile_a, t_pile *pile_b)
{
	// ft_printab(*pile_a, *pile_b);
	ft_tabtopileb(pile_a, pile_b);
	// ft_printab(*pile_a, *pile_b);
	ft_pricecalculator(pile_a, pile_b);
	ft_pushmin(pile_a, 'a');
}
