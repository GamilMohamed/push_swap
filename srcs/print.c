/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:18:08 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/26 12:57:58 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	ft_printab(t_pile pile_a, t_pile pile_b)
// {
// 	int	i;
// 	int	max;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (pile_a.size > pile_b.size)
// 	{
// 		max = pile_a.size - pile_b.size;
// 		while (i < max)
// 		{
// 			ft_printf("%r%i%0\t", i);
// 			ft_printf("%g%i%0\t", pile_a.tab[i]);
// 			ft_printf("\n");
// 			i++;
// 		}
// 	}
// 	else if (pile_a.size < pile_b.size)
// 	{
// 		max = pile_b.size - pile_a.size;
// 		while (i < max)
// 		{
// 			ft_printf("%r%i%0\t", i);
// 			ft_printf("%g%i%0\t", pile_b.tab[i]);
// 			ft_printf("\n");
// 			i++;
// 		}
// 	}
// 	if (pile_a.size == pile_b.size)
// 	{
// 		while (i < pile_a.size)
// 		{
// 			ft_printf("%r%i%0\t", i);
// 			ft_printf("%g%i%0\t", pile_b.tab[i]);
// 			ft_printf("%b%i%0\t", pile_a.tab[j]);
// 			ft_printf("%m%i%0\t", j++);
// 			i++;
// 			ft_printf("\n");
// 		}
// 	}
// 	while (i < pile_a.size)
// 	{
// 		ft_printf("%r%i%0\t", i);
// 		ft_printf("%g%i%0\t", pile_a.tab[i]);
// 		ft_printf("%b%i%0\t", pile_b.tab[j]);
// 		ft_printf("%m%i%0\t", j++);
// 		i++;
// 		ft_printf("\n");
// 	}
// 	ft_printf("%i\tPILE A\tPILE B\t%i\n", pile_a.size, pile_b.size);
// }

void	ft_printab(t_pile pile_a, t_pile pile_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < pile_a.size - pile_b.size)
	{
		ft_printf("%r%i%0\t%g%i%0\t\n", i, pile_a.tab[i]);
		i++;
	}
	while (j < pile_b.size - pile_a.size)
	{
		ft_printf("\t\t%0%b%i%\t%r%i%0\t\n", pile_b.tab[j], j);
		j++;
	}
	while (i < pile_a.size && j < pile_b.size)
	{
		ft_printf("%r%i%0\t%g%i%0\t%b%i%0\t%r%i%0\t\n", i, pile_a.tab[i],
				pile_b.tab[j], j);
		i++;
		j++;
	}
	ft_printf("%i\tPILE A\tPILE B\t%i\n", pile_a.size, pile_b.size);
	ft_printf("test\aavion\n");
}

/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
2 1 3 4
2 1 4 3
2 3 1 4
2 4 1 3
2 








*/