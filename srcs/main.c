/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/02 07:58:05 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	ft_pricecalculator(t_pile *pile_a, t_pile *pile_b)
// {
// 	int	i;
// 	(void)pile_a;
// 	i = 0;
// 	/*cost of b to top*/
// 	while (i < pile_b->size)
// 	{
// 		i++;
// 	}
// }

int	main(int ac, char **av)
{
	t_pile	pile_a;
	t_pile	pile_b;

	if (ft_checkacav(ac, av))
		return (1);
	pile_a.tab = ft_argtotab(ac, av);
	if (!pile_a.tab)
		return (0);
	pile_a.total = ac - 1;
	pile_a.size = ac - 1;
	pile_b.tab = malloc(sizeof(int) * pile_a.total);
	pile_b.size = 0;
	ft_printab(pile_a, pile_b);
	ft_algo(&pile_a, &pile_b);
	ft_lis(&pile_a, &pile_b);
	ft_printab(pile_a, pile_b);
	// ft_pricecalculator(&pile_a, &pile_b);
	ft_checksort(&pile_a, &pile_b, pile_a.total);
	return (0);
}
