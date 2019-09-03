/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/03 17:28:05 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_sort_clean(t_dirs *dirs)
{
	t_info	*list;
	t_info	*next;

	if (dirs)
	{
		list = dirs->list;
		while (list)
		{
			next = list->next;
			if (list->name)
				free(list->name);
			if (list->path)
				free(list->path);
			free(list);
			list = next;
		}
		free(dirs->root);
		free(dirs);
	}
}

t_info	*ft_sort_comp(int *flags, t_info *list, t_info *unsorted)
{
	if (*flags & F_T)
	{
		while (list->next && ft_strcmp(list->next->name, unsorted->name) < 0)
			list = list->next;
		return (list);
	}
	else if (*flags & F_U)
	{
		while (list->next && ft_strcmp(list->next->name, unsorted->name) < 0)
			list = list->next;
		return (list);
	}
	else
	{
		while (list->next && ft_strcmp(list->next->name, unsorted->name) < 0)
			list = list->next;
		return (list);
	}
}

void	ft_sort_time(int *flags, t_info **sorted, t_info *unsorted)
{
	t_info *list;

	if (!*sorted)
		*sorted = unsorted;
	else if (ft_strcmp((*sorted)->name, unsorted->name) >= 0)
	{
		unsorted->next = *sorted;
		unsorted->next->prev = unsorted;
		*sorted = unsorted;
	}
	else
	{
		list = *sorted;
		list = ft_sort_comp(flags, list, unsorted);
		unsorted->next = list->next;
		if (list->next)
			unsorted->next->prev = unsorted;
		list->next = unsorted;
		unsorted->prev = list;
	}
}

void	ft_sort_lex(int *flags, t_info **sorted, t_info *unsorted)
{
	t_info *list;

	if (!*sorted)
		*sorted = unsorted;
	else if (ft_strcmp((*sorted)->name, unsorted->name) >= 0)
	{
		unsorted->next = *sorted;
		unsorted->next->prev = unsorted;
		*sorted = unsorted;
	}
	else
	{
		list = *sorted;
		list = ft_sort_comp(flags, list, unsorted);
		unsorted->next = list->next;
		if (list->next)
			unsorted->next->prev = unsorted;
		list->next = unsorted;
		unsorted->prev = list;
	}
}

void	ft_sorts(int *flags, t_dirs *dirs)
{
	t_info *next;
	t_info *list;
	t_info *sorted;

	sorted = NULL;
	list = dirs->list;
	while (list)
	{
		next = list->next;
		list->prev = NULL;
		list->next = NULL;
		if (*flags & F_T || *flags & F_U)
			ft_sort_time(flags, &sorted, list);
		else
			ft_sort_lex(flags, &sorted, list);
		list = next;
	}
	dirs->list = sorted;
	while (sorted)
	{
		if (!sorted->next)
			dirs->last = sorted;
		sorted = sorted->next;
	}
}
