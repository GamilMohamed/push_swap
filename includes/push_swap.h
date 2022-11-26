/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:22:19 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/26 12:13:42 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pile
{
	int	size;
	int	*tab;
}		t_pile;
/*	MISC.C		*/
int		ft_aintnumeric(char *s);
int		ft_checkacav(int ac, char **av);
int		*ft_argtotab(int ac, char **av);
int		ft_checksort(t_pile pile);
/*	ACTIONS.C	*/
void	pushswap_rotate(t_pile *pile, char c);
void	pushswap_rrotate(t_pile *pile, char c);
void	pushswap_push(t_pile *src, t_pile *dest, char c);
int		pushswap_swap(t_pile *pile, char c);
/*	ROTATE.C	*/
void	ft_rotatedown(t_pile *pile);
void	ft_rotateup(t_pile *pile);
/*	PRINT.C		*/
void	ft_printab(t_pile pile_a, t_pile pile_b);
#endif
