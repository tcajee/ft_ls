/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/02 14:50:01 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_sort_lex(t_info **sorted, t_info *unsorted)
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
		while (list->next && ft_strcmp(list->next->name, unsorted->name) < 0)
			list = list->next;
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
		if(*flags & F_t)
			ft_sort_lex(&sorted, list);
		else if (*flags & F_u)
			ft_sort_lex(&sorted, list);
		else
			ft_sort_lex(&sorted, list);
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

/* void	ft_sorts(int *flags, t_dirs *dirs) */
/* { */
/* 	t_info *sorted; */
/* 	t_info *list; */
/* 	t_info *next; */
/* 	sorted = NULL; */
/* 	list = dirs->list; */
/* 	while (list) */
/* 	{ */
/* 		next = list->next; */

/* 	} */
/* 	dirs->list = sorted; */
/*  } */
