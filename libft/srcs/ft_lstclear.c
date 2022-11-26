/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:28:15 by mohazerr          #+#    #+#             */
/*   Updated: 2022/11/24 04:16:07 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*cplst;

	if (lst == NULL || del == NULL)
		return ;
	cplst = *(lst);
	while (cplst != NULL)
	{
		(*del)(cplst->content);
		temp = cplst->next;
		free(cplst);
		cplst = temp;
	}
	*lst = NULL;
}
