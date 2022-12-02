/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:19:40 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/02 08:57:33 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
