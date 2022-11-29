/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:22:19 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/29 04:04:33 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define pb();		pushswap_push(pile_b, pile_a, 'b', pile_a->tab);
# define pa();		pushswap_push(pile_a, pile_b, 'a', pile_b->tab);
# define ra();		pushswap_rotate(pile_a, 'a');
# define rb();		pushswap_rotate(pile_b, 'b');
# define rr();		pushswap_rotate(pile_a, 'a');	pushswap_rotate(pile_b, 'b');
# define rra();		pushswap_rrotate(pile_a, 'a');
# define rrb();		pushswap_rrotate(pile_b, 'b');
# define rrr();		pushswap_rrotate(pile_a, 'a');	pushswap_rrotate(pile_b, 'b');
# define sa();		pushswap_swap(pile_a->size, 'a', pile_a->tab);
# define sb();		pushswap_swap(pile_b->size, 'b', pile_b->tab);
# define ss();		pushswap_swap(pile_a->size, 'a', pile_a->tab);	pushswap_swap(pile_b->size, 'b', pile_b->tab);

# define Ppb();		pushswap_push(pile_b, pile_a, 'b', pile_a->tab);	ft_printab((*pile_a), (*pile_b));
# define Ppa();		pushswap_push(pile_a, pile_b, 'a', pile_b->tab);	ft_printab((*pile_a), (*pile_b));
# define Pra();		pushswap_rotate(pile_a, 'a');	ft_printab((*pile_a), (*pile_b));
# define Prb();		pushswap_rotate(pile_b, 'b');	ft_printab((*pile_a), (*pile_b));
# define Prr();		pushswap_rotate(pile_a, 'a');	pushswap_rotate(pile_b, 'b');	ft_printab((*pile_a), (*pile_b));
# define Prra();	pushswap_rrotate(pile_a, 'a');	ft_printab((*pile_a), (*pile_b));
# define Prrb();	pushswap_rrotate(pile_b, 'b');	ft_printab((*pile_a), (*pile_b));
# define Prrr();	pushswap_rrotate(pile_a, 'a');	pushswap_rrotate(pile_b, 'b');	ft_printab((*pile_a), (*pile_b));
# define Psa();		pushswap_swap(pile_a->size, 'a', pile_a->tab);	ft_printab((*pile_a), (*pile_b));
# define Psb();		pushswap_swap(pile_b->size, 'b', pile_b->tab);	ft_printab((*pile_a), (*pile_b));
# define Pss();		pushswap_swap(pile_a->size, 'a', pile_a->tab);	pushswap_swap(pile_b->size, 'b', pile_b->tab);	ft_printab((*pile_a), (*pile_b));



typedef struct s_pile
{
	int	size;
	int	*tab;
	int total;
}		t_pile;
/*	MISC.C				*/
int		ft_aintnumeric(char *s);
int		ft_checkacav(int ac, char **av);
int		*ft_argtotab(int ac, char **av);
void		ft_checksort(t_pile *pile_a, t_pile *pile_b, int size);
void	ft_exit(t_pile *pile_a, t_pile *pile_b, int boolean);
/*	ACTIONS.C			*/
void	pushswap_rotate(t_pile *pile, char c);
void	pushswap_rrotate(t_pile *pile, char c);
void	pushswap_push(t_pile *dest, t_pile *src, char c, int *tab);
void	pushswap_swap(int size, char c, int *tab);
/*	ACTIONS_UTILS.C		*/
void	ft_rotatedown(t_pile *pile);
void	ft_rotateup(t_pile *pile);
void	ft_pushmin(t_pile *pile_a, t_pile *pile_b);
/*	PRINT.C				*/
void	ft_printab(t_pile pile_a, t_pile pile_b);
/*	ALGO.C				*/
void	algo_three(t_pile *pile);
void	algo_five(t_pile *pile_a, t_pile *pile_b);
/*	MATH.C				*/
int	ft_getmin(t_pile pile);
int	ft_getmax(t_pile pile);
#endif
