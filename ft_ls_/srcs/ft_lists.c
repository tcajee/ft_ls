/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:16:28 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/02 10:53:43 by tcajee           ###   ########.fr       */
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

void	ft_list_print(t_dirs *dirs)
{
	int		i;
	t_info	*list;

	i = 0;
	list = dirs->list;
	printf("------------------------------------------\n");
	printf("dirs			[%p]\n", dirs);
	printf("&dirs->list		[%p]\n", &dirs->list);
	printf("dirs->list		[%p]\n", dirs->list);
	printf("dirs->size		[%d]\n", dirs->size);
	printf("dirs->total		[%d]\n", dirs->total);
	printf("dirs->root		[%s]\n", dirs->root);
	printf("dirs->s_form.grp_len	[%zu]\n", dirs->s_form.grp_len);
	printf("dirs->s_form.usr_len	[%zu]\n", dirs->s_form.usr_len);
	printf("dirs->s_form-.link_len	[%zu]\n", dirs->s_form.link_len);
	printf("dirs->s_form.size_len	[%zu]\n", dirs->s_form.size_len);
	printf("&dirs->last		[%p]\n", &dirs->last);
	printf("dirs->last		[%p]\n", dirs->last);
	printf("------------------------------------------\n");
	while (list)
	{
		printf("-------------------------------------------\n");
		printf("dirs->array[%d]		[%p]\n", i, dirs->array[i]);
		printf("[%d]			[%p]\n", i, list);
		printf("list->root		[%s]\n", list->root);
		printf("list->name		[%s]\n", list->name);
		printf("list->path		[%s]\n", list->path);
		printf("list->next		[%p]\n", list->next);
		printf("list->prev		[%p]\n", list->prev);
		printf("list->i			[%d]\n", list->i);
		i++;
		list = list->next;
	}
	printf("------------------------------------------\n");
	/* printf("&dirs->list	[%p]\n", &dirs->list); */
	/* printf("dirs->list	[%p]\n", dirs->list); */
	/* printf("------------------------------------------\n"); */
}

int	ft_list_ins(t_info *list)
{
	(void)list;
	return (0);
}

t_info	*ft_list_add(t_info *last)
{
/* ft_putendl("begin list add"); */
	t_info	*new;

	if (!(new = ft_list_new()))
		return (NULL);
	last->next = new;
	new->prev = last;
/* ft_putendl("end list add"); */
	return (new);
}

t_info *ft_list_new(void)
{
/* ft_putendl("begin list new"); */
	t_info	*new;
	
	if (!(new = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	new->root = NULL;
	new->name = NULL;
	new->path = NULL;
	new->next = NULL;
	new->prev = NULL;
/* ft_putendl("end list new"); */
	return (new);
}

int	ft_lists(int *flags, t_info *list)
{
	(void)list;
	(void)flags;
	return (0);
}
