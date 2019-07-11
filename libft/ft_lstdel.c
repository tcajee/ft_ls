/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:03:13 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/13 13:55:31 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *delete;
	t_list *next;

	delete = *alst;
	while (alst && delete && del)
	{
		next = delete->next;
		del(delete->content, delete->content_size);
		ft_memdel((void **)&delete);
		delete = next;
	}
	*alst = NULL;
}
