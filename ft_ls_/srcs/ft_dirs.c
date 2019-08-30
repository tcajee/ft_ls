/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/30 17:38:38 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

t_dirs	*ft_dir_new(char *path)
{
	t_dirs	*new;

	new = NULL;
	if (!(new = (t_dirs *)malloc(sizeof(t_dirs))))
		return (NULL);
	if (!(new->name = ft_strdup(path)))
		return (NULL);
	if (!(new->list = ft_list_new()))
		return (NULL);
	new->last = NULL;
	new->total = 0;
	new->size = 0;
	new->s_form.grp_len = 0;
	new->s_form.usr_len = 0;
	new->s_form.size_len = 0;
	new->s_form.link_len = 0;
	return (new);
}


int ft_dir_fill(int *flags, t_dirs *dirs, char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	t_info		*list;

	list = dirs->list;
	dirs->last = list;
	if (!(dir = opendir(path)))
		return (ft_errors(flags, E_PRINTS, path));
	while ((s_dir = readdir(dir)) != NULL && ++dirs->size)
	{
		if (!list)
			list = ft_list_add(dirs->last);
		list->root = ft_strdup(path);
		list->name = ft_strdup(s_dir->d_name);
		list->path = ft_ls_path(path, s_dir->d_name);
		lstat(list->path, &list->s_stat);
		dirs->total += list->s_stat.st_blocks;
		dirs->last = list;
		list = list->next;
	}
	closedir(dir);
	return (1);
}


int ft_dir_file(int *flags, char *path)
{
	t_dirs	*dirs;

	F_SET(*flags, F_0, F_REG);
	if (!(dirs = ft_dir_new(path)))
		return (0);
	if (!(dirs->list->name = ft_strdup(path)))
		return (0);
	lstat(dirs->list->name, &dirs->list->s_stat);
	dirs->size = 1;
	ft_prints(flags, dirs);
	free(dirs->list->name);
	free(dirs);
	F_SET(*flags, F_REG, F_0);
	return (1);
}

int ft_dirs(int *flags, char *path)
{
	t_dirs		*dirs;

	if (ft_ls_check(path) == 1 && (!(ft_dir_file(flags, path))))
		return (0);
	else if (ft_ls_check(path) == 2)
	{
		if (!(dirs = ft_dir_new(path)))
			return (0);
		if (!(ft_dir_fill(flags, dirs, path)))
			return (0);
		/* if (dirs->size > 1 && !(*flags & F_REG) && !(*flags & F_f)) */
		/* 	ft_sorts(flags, dirs); */
		/* ft_list_print(dirs); */
		ft_prints(flags, dirs);
		/* ft_ls_clean(dirs); */
	}
	if (*flags & F_R)
		ft_ls_rec(flags, path);
	return (1);
}
