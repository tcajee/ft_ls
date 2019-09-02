/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/02 12:44:14 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

t_dirs	*ft_dir_new(char *path)
{
	t_dirs	*new;

	if (!(new = (t_dirs *)malloc(sizeof(t_dirs))))
		return (NULL);


	new->root = ft_strdup(path);


	new->list = NULL;
	new->last = NULL;
	new->total = 0;
	new->size = 0;
	new->s_form.grp_len = 0;
	new->s_form.usr_len = 0;
	new->s_form.size_len = 0;
	new->s_form.link_len = 0;
	return (new);
}


int	ft_dir_form(int *flags, t_dirs *dirs)
{
	t_info		*last;
	t_passwd	*s_pwd;
	t_group		*s_grp;
	size_t		len;

	last = dirs->last;
	if (*flags & F_l)
	{
		if ((len = ft_intlen(last->s_stat.st_nlink)) > dirs->s_form.link_len)
			dirs->s_form.link_len = len;
		s_pwd = getpwuid(last->s_stat.st_uid);
		if (s_pwd && (len = ft_strlen(s_pwd->pw_name)) > dirs->s_form.usr_len)
			dirs->s_form.usr_len = len;
		else if ((len = ft_intlen((int)s_pwd->pw_name)) > dirs->s_form.usr_len)
			dirs->s_form.usr_len = len;
		s_grp = getgrgid(last->s_stat.st_gid);
		if (s_grp && (len = ft_strlen(s_grp->gr_name)) > dirs->s_form.grp_len)
			dirs->s_form.grp_len = len;
		else if ((len = ft_intlen((int)s_grp->gr_name)) > dirs->s_form.grp_len)
			dirs->s_form.grp_len = len;
		if ((len = ft_intlen(last->s_stat.st_size)) > dirs->s_form.size_len)
			dirs->s_form.size_len = len;
	}
	return (1);
}


int ft_dir_fill(int *flags, t_dirs *dirs, char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	t_info		*list;

	dirs->list = ft_list_new();
	list = dirs->list;
	dirs->last = list;
	if (!(dir = opendir(path)))
		return (ft_errors(flags, E_PRINTS, path));
	while ((s_dir = readdir(dir)) != NULL)
	{
		if (!list)
			list = ft_list_add(dirs->last);
		list->root = ft_strdup(path);
		list->name = ft_strdup(s_dir->d_name);
		list->path = ft_ls_path(path, s_dir->d_name);
		list->i = dirs->size;
		lstat(list->path, &list->s_stat);
		dirs->total += list->s_stat.st_blocks;
		ft_dir_form(flags, dirs);
		dirs->last = list;
		list = list->next;
		dirs->size++;
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
	if (!(dirs->list->root = ft_strdup(path)))
		return (0);
	lstat(dirs->list->root, &dirs->list->s_stat);
	dirs->size = 1;
	ft_prints(flags, dirs);
	free(dirs->list->root);
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
		dirs = ft_dir_new(path);
		if (!(ft_dir_fill(flags, dirs, path)))
			return (0);


		/* if (dirs->size > 1 && !(*flags & F_REG) && !(*flags & F_f)) */
		/* 	ft_sorts(flags, dirs); */

		ft_list_print(dirs);

		ft_sort(flags, &dirs->list);
		ft_prints(flags, dirs);

		/* ft_prints(flags, dirs); */
		/* dirs->s_form.grp_len = 0; */
		/* dirs->s_form.usr_len = 0; */
		/* dirs->s_form.size_len = 0; */
		/* dirs->s_form.link_len = 0; */
		/* ft_ls_clean(dirs); */
	}
	if (*flags & F_R)
		ft_ls_rec(flags, path);
	return (1);
}
