/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:42:26 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:18 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = NULL;
	FT_(!(new = (t_list *)malloc(sizeof(t_list))), NULL);
	if (new)
	{
		new->next = NULL;
		if (!content)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			FT_(!(new->content = ft_memcpy(ft_memalloc(content_size),\
							content, content_size)), NULL);
			new->content_size = content_size;
		}
	}
	return (new);
}
