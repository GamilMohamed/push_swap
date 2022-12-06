/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:23:37 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/06 23:39:14 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*parse_args(int ac, char **av, int *size);

int	main(int ac, char **av)
{
	t_pile	pile_a;
	t_pile	pile_b;
	int		size;

	if (ac < 2)
		return (1);
	pile_a.tab = parse_args(ac, av, &size);
	if (!pile_a.tab)
		return (0);
	pile_a.total = size;
	pile_a.size = size;
	pile_b.tab = malloc(sizeof(int) * pile_a.total);
	if (!pile_b.tab)
	{
		free(pile_a.tab);
		exit(EXIT_FAILURE);
	}
	pile_b.size = 0;
	ft_algo(&pile_a, &pile_b);
	ft_lis(&pile_a, &pile_b);
	ft_pricecalculator(&pile_a, &pile_b);
	ft_pushmin(&pile_a, 'a');
	ft_checksort(&pile_a, &pile_b, pile_a.total);
	return (0);
}
