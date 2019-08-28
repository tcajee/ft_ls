/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:16:28 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/28 15:48:41 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_list_clean(t_dirs *dirs)
{

	(void)dirs;
	return ;
	/* int i; */
	/* i = dirs[0].dirc; */
	/* if (dirs[0].total) */
	/* 	free(dirs[0].total); */
	/* while (i--) */
	/* { */
	/* 	if (dirs[i].root) */
	/* 		free(dirs[i].root); */
	/* 	if (dirs[i].path) */
	/* 		free(dirs[i].path); */
	/* 	if (dirs[i].name) */
	/* 		free(dirs[i].name); */
	/* } */

}

int	ft_list_ins(t_info *list)
{
	(void)list;
	return (0);
}

t_info	*ft_list_add(t_info *list)
{
	t_info *new;

	if (!list)
		if (!(list= ft_list_new()))
			return (NULL);
	if (!(new = ft_list_new()))
		return (NULL);
	list->next = new;
	return (new);
}

t_info *ft_list_new(void)
{
	t_info	*new;
	
	if (!(new = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	new->root = NULL;
	new->name = NULL;
	new->path = NULL;
	new->next = NULL;
	return (new);
}

int	ft_lists(int *flags, t_info *list)
{
	(void)list;
	(void)flags;
	return (0);
}
