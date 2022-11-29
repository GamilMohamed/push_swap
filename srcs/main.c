/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/29 04:12:35 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (pile_a.size == 3)
		algo_three(&pile_a);
	pile_b.tab = malloc(sizeof(int) * pile_a.total);
	pile_b.size = 0;
	if (pile_a.size == 5)
		algo_five(&pile_a, &pile_b);
	ft_printab(pile_a, pile_b);
	ft_checksort(&pile_a, &pile_b, pile_a.total);
	return (0);
}
