/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:22:19 by mgamil            #+#    #+#             */
/*   Updated: 2023/04/03 03:32:49 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_pile
{
	int	size;
	int	*tab;
	int	total;
}		t_pile;

/*	PARSE.C				*/
int		ft_double(int *tab, int size);
int		ft_freetab(char **tab, int boolean);
int		*ft_duptab(int *tab, int size);
void	ft_whileresij(char **res, int i);
int		*parse_args(int ac, char **av, int *size);
/*	MISC.C				*/
void	ft_checksortav(t_pile *pile_a, int size);
int		ft_checkacav(int ac, char **av);
void	ft_checksort(t_pile *pile_a, t_pile *pile_b, int size);
void	ft_exit(t_pile *pile_a, t_pile *pile_b, int boolean);
/*	ACTIONS.C			*/
void	pushswap_rotate(t_pile *pile, char c, int x);
void	pushswap_rrotate(t_pile *pile, char c, int x);
int		pushswap_push(t_pile *dest, t_pile *src, char c, int *tab);
void	pushswap_swap(int size, char c, int *tab);
/*	ACTIONS_UTILS.C		*/
void	ft_rotatedown(t_pile *pile);
void	ft_rotateup(t_pile *pile);
void	ft_pushmin(t_pile *pile, char c);
void	pushswap_rr(t_pile *pile_a, t_pile *pile_b, int x);
void	pushswap_rrr(t_pile *pile_a, t_pile *pile_b, int x);
/*	ALGO.C				*/
void	ft_algo(t_pile *pile_a, t_pile *pile_b);
void	algo_two(t_pile *pile_a);
void	algo_three(t_pile *pile);
void	algo_five(t_pile *pile_a, t_pile *pile_b);
/*	PRINT.C				*/
void	ft_printab(t_pile pile_a, t_pile pile_b);
/*	MATH.C				*/
int		ft_getmin(t_pile pile);
int		ft_getmax(t_pile pile);
int		ft_sup(t_pile pile_a, t_pile pile_b, int index);
/*	LIS.C				*/
void	algo_all(t_pile *pile_a, t_pile *pile_b);
/*	PRICE.C				*/
void	ft_pricecalculator(t_pile *pile_a, t_pile *pile_b);
int		ft_totalprice(int price_a, int price_b);
int	ft_domovement(t_pile *pile_a, t_pile *pile_b, int best_price_a, int best_price_b);

int		ft_price(t_pile *pile, int index);

#endif
