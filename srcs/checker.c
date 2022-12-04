/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:55:51 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/04 21:28:22 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_actions(t_pile *pile_a, t_pile *pile_b, int count, char *action)
{
	if (ft_strcmp(action, "pb\n") == 0)
		count = pushswap_push(pile_b, pile_a, 'x', pile_a->tab);
	if (ft_strcmp(action, "pa\n") == 0)
		count = pushswap_push(pile_a, pile_b, 'x', pile_b->tab);
	if (ft_strcmp(action, "ra\n") == 0)
		count = pushswap_rotate(pile_a, 'x', 0);
	if (ft_strcmp(action, "rb\n") == 0)
		count = pushswap_rotate(pile_b, 'x', 0);
	if (ft_strcmp(action, "rra\n") == 0)
		count = pushswap_rrotate(pile_a, 'x', 0);
	if (ft_strcmp(action, "rrb\n") == 0)
		count = pushswap_rrotate(pile_a, 'x', 0);
	if (ft_strcmp(action, "rr\n") == 0)
		count = pushswap_rr(pile_a, pile_b, 0);
	if (ft_strcmp(action, "rrr\n") == 0)
		count = pushswap_rrr(pile_a, pile_b, 0);
	if (!count)
		ft_printf("lol\n");
}

int	checking(t_pile *pile_a, t_pile *pile_b, int total)
{
	int	i;
	int	j;

	i = 0;
	while (i < pile_a->size)
	{
		j = i + 1;
		while (j < pile_a->size)
		{
			if (pile_a->tab[i] > pile_a->tab[j])
				ft_exit(pile_a, pile_b, 0);
			j++;
		}
		i++;
	}
	if (i == total)
		return (0);
	return (1);
}

void	checker(t_pile *pile_a, t_pile *pile_b)
{
	char	*action;
	int		firstloop;

	firstloop = 1;
	action = 0;
	while (action || firstloop)
	{
		action = get_next_line(0);
		if (!action)
			break ;
		if (action && firstloop && checking(pile_a, pile_b, pile_a->total))
		{
			ft_printf("KO\n");
			free(action);
			exit(1);
		}
		do_actions(pile_a, pile_b, 0, action);
		free(action);
		firstloop = 0;
	}
}

int	main(int ac, char **av)
{
	t_pile pile_a;
	t_pile pile_b;

	if (ft_checkacav(ac, av))
		return (1);
	pile_a.tab = ft_argtotab(ac, av);
	if (!pile_a.tab)
		return (0);
	pile_a.total = ac - 1;
	pile_a.size = ac - 1;
	pile_b.tab = malloc(sizeof(int) * pile_a.total);
	if (!pile_b.tab)
	{
		free(pile_a.tab);
		exit(EXIT_FAILURE);
	}
	pile_b.size = 0;
	checker(&pile_a, &pile_b);
}