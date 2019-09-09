/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/09 11:22:00 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

t_info	*ft_dir_add(t_info *last)
{
	t_info	*new;

	if (!(new = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	new->name = NULL;
	new->path = NULL;
	new->next = NULL;
	last->next = new;
	new->prev = last;
	return (new);
}

t_dirs	*ft_dir_new(char *path)
{
	t_dirs	*new;

	if (!(new = (t_dirs *)malloc(sizeof(t_dirs))))
		return (NULL);
	new->root = ft_strdup(path);
	if (!(new->list = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	new->list->name = NULL;
	new->list->path = NULL;
	new->list->next = NULL;
	new->list->prev = NULL;
	new->s_form.grp_len = 0;
	new->s_form.usr_len = 0;
	new->s_form.size_len = 0;
	new->s_form.link_len = 0;
	new->total = 0;
	new->size = 0;
	new->last = NULL;
	return (new);
}

void	ft_dir_form(int *flags, t_dirs *dirs)
{
	t_info		*last;
	t_passwd	*s_pwd;
	t_group		*s_grp;
	size_t		len;

	if(dirs)
		last = dirs->last;
	if (*flags & F_L && dirs)
	{
		if ((len = ft_intlen(last->s_stat.st_nlink)) > dirs->s_form.link_len)
			dirs->s_form.link_len = len;
		if ((s_pwd = getpwuid(last->s_stat.st_uid)))
		{
			if (s_pwd && (ft_strlen(s_pwd->pw_name)) > dirs->s_form.usr_len)
			{
				dirs->s_form.usr_len = ft_strlen(s_pwd->pw_name);
			}
			else if ((ft_intlen(last->s_stat.st_uid)) > dirs->s_form.usr_len)
			{
				dirs->s_form.usr_len = ft_intlen(last->s_stat.st_uid);
			}
		}
		if((s_grp = getgrgid(last->s_stat.st_gid)))
		{
			if (s_grp && (len = ft_strlen(s_grp->gr_name)) > dirs->s_form.grp_len)
				dirs->s_form.grp_len = len;
			else if ((len = ft_intlen((int)*s_grp->gr_name)) > dirs->s_form.grp_len)
				dirs->s_form.grp_len = len;
		}
		if ((len = ft_intlen(last->s_stat.st_size)) > dirs->s_form.size_len)
			dirs->s_form.size_len = len;
	}
}

int		ft_dir_fill(int *flags, t_dirs *dirs, char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	t_info		*list;

	list = dirs->list;
	if (!(dir = opendir(path)))
		return (ft_error_perm(flags, path));
	while ((s_dir = readdir(dir)) != NULL && ++dirs->size)
	{
		if (!list)
			list = ft_dir_add(dirs->last);
		dirs->last = list;
		list->name = ft_strdup(s_dir->d_name);
		list->path = ft_ls_path(path, s_dir->d_name);
		lstat(list->path, &list->s_stat);
		dirs->total += list->s_stat.st_blocks;
		ft_dir_form(flags, dirs);
		list = list->next;
	}
	closedir(dir);
	/* ft_list_print(dirs); */
	if (!(*flags & F_F))
		ft_sorts(flags, dirs);
	return (ft_prints(flags, dirs));
}

int		ft_dirs(int *flags, char *path)
{
	t_dirs *dirs;

	if (!(dirs = ft_dir_new(path)))
		return (0);
	if (!(ft_dir_fill(flags, dirs, path)))
		return (0);
	if (*flags & F_RR)
		ft_ls_rec(flags, dirs);
	ft_sort_clean(dirs);
	return (1);
}
