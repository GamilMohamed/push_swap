/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/26 11:41:24 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_three(t_pile *pile)
{
	if (pile->tab[0] > pile->tab[1] && pile->tab[1] > pile->tab[2]
		&& pile->tab[0] > pile->tab[2])
		ft_printf("%gDONE%0");
	if (pile->tab[0] > pile->tab[1] && pile->tab[1] < pile->tab[2]
		&& pile->tab[0] < pile->tab[2])
		pushswap_swap(pile, 'a');
	if (pile->tab[0] > pile->tab[1] && pile->tab[1] > pile->tab[2]
		&& pile->tab[0] > pile->tab[2])
	{
		pushswap_rotate(pile, 'a');
		pushswap_swap(pile, 'a');
	}
	if (pile->tab[0] > pile->tab[1] && pile->tab[1] < pile->tab[2]
		&& pile->tab[0] > pile->tab[2])
		pushswap_rotate(pile, 'a');
	if (pile->tab[0] < pile->tab[1] && pile->tab[1] > pile->tab[2]
		&& pile->tab[0] < pile->tab[2])
	{
		pushswap_rrotate(pile, 'a');
		pushswap_swap(pile, 'a');
	}
	if (pile->tab[0] < pile->tab[1] && pile->tab[1] > pile->tab[2]
		&& pile->tab[0] > pile->tab[2])
		pushswap_rrotate(pile, 'a');
}

int	main(int ac, char **av)
{
	t_pile	pile_a;
	t_pile	pile_b;

	if (ft_checkacav(ac, av))
		return (1);
	pile_a.tab = ft_argtotab(ac, av);
	if (!pile_a.tab)
		return (0);
	pile_a.size = ac - 1;
	if (ft_checksort(pile_a))
	{
		free(pile_a.tab);
		return (ft_printf("%gstack already sorted%0\n"));
	}
	if (pile_a.size == 3)
		algo_three(&pile_a);
	pile_b.tab = malloc(sizeof(int) * pile_a.size);
	pile_b.size = 0;
	ft_printab(pile_a, pile_b);
	ft_printab(pile_a, pile_b);
	if (ft_checksort(pile_a))
		ft_printf("%gsorted%0\n");
	free(pile_a.tab);
	free(pile_b.tab);
	return (0);
}

/*

1 2 3 ok

2 1 3 sa  -> 1 2 3

3 2 1 ra  -> 2 1 3 -> sa -> 1 2 3
3 1 2 ra  -> 1 2 3

1 3 2 rra -> 2 1 3 -> 1 2 3 -> sa
2 3 1 rra -> 1 2 3


*/