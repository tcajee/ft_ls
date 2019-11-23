/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:17:37 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:34 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*copy;
	t_list	*next;

	head = NULL;
	if (lst && f)
	{
		copy = f(lst);
		F_(!(next = ft_lstnew(copy->content, copy->content_size)), NULL);
		head = next;
		T_(lst);
		while (lst)
		{
			copy = f(lst);
			F_(!(next->next = ft_lstnew(copy->content, copy->content_size)),
				NULL);
			T_(next);
			T_(lst);
		}
	}
	return (head);
}
