/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:20:18 by bnespoli          #+#    #+#             */
/*   Updated: 2024/09/02 20:42:21 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listg	*ft_lstnewgnl(char content)
{
	t_listg	*new;

	new = (t_listg *)malloc(sizeof(t_listg));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

void	*ft_lstcleargnl(t_listg **lst)
{
	t_listg	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp = tmp -> next;
		free(*lst);
		*lst = tmp;
	}
	tmp = NULL;
	return (NULL);
}

void	ft_lstadd_backgnl(t_listg **lst, t_listg *new)
{
	t_listg	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last -> next)
		last = last -> next;
	last -> next = new;
}
