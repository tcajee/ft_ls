/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/29 16:35:32 by tcajee           ###   ########.fr       */
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

int	ft_dir_dinfo(int *flags, t_dirs *dirs, char *path)
{
/* ft_putendl("beg dinfo"); */
	t_dirent	*s_dir;
	t_info		*list;
	DIR			*dir;
	int			size;
	int			total;

	size = 0;
	total = 0;
	if (!(dirs = ft_dir_new(path)))
		return (0);
	list = dirs->list;
	dirs->last = list;
	if (!(dir = opendir(path)))
		return (ft_errors(flags, E_PRINTS, path));
	while ((s_dir = readdir(dir)) != NULL)
	{
		if (!list)
			if (!(list = ft_list_add(dirs->last)))
				return (0);
		if (!(list->root = ft_strdup(path)))
			return (0);
		if (!(list->name = ft_strdup(s_dir->d_name)))
			return (0);
		if (!(list->path = ft_ls_path(path, s_dir->d_name)))
			return (0);
		if ((lstat(list->path, &list->s_stat)) < 0)
			return (0);
		total += list->s_stat.st_blocks;
		dirs->last = list;
		list = list->next;
		size++;
	}
	closedir(dir);
	dirs->total = ft_itoa(total);
	dirs->size = size;

	/* if (dirs->size > 1 && !(*flags & F_REG) && !(*flags & F_f)) */
	/* 	ft_sorts(flags, dirs); */

	/* ft_list_print(dirs); */
	ft_prints(flags, dirs);

/* ft_putendl("end dinfo"); */
	return (1);
}

int ft_dir_finfo(int *flags, t_dirs *dirs, char *path)
{
 /* ft_putendl("beg finfo"); */
	F_SET(*flags, F_0, F_REG);
	if (!(dirs = ft_dir_new(path)))
		return (0);
	if (!(dirs->list->name = ft_strdup(path)))
		return (0);
	lstat(dirs->list->name, &dirs->list->s_stat);
	dirs->size = 1;
	ft_prints(flags, dirs);
	free(dirs->list->name);
	F_SET(*flags, F_REG, F_0);
	return (1);
 /* ft_putendl("end finfo"); */
}

int ft_dirs(int *flags, char *path)
{
 /* ft_putendl("begin dirs"); */
	t_dirs		dirs;
	if (ft_ls_check(path) == 1 && (!(ft_dir_finfo(flags, &dirs, path))))
		return (0);
	else if (ft_ls_check(path) == 2 && (!(ft_dir_dinfo(flags, &dirs, path))))
		return (0);
	if (*flags & F_R)
		ft_ls_rec(flags, path);
	/* ft_putendl("end dirs"); */
	return (1);
}
