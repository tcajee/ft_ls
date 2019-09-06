/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/06 20:29:35 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

t_info	*ft_dir_add(t_info *last)
{
	t_info	*new;

/* ft_putendl("			DIR_ADD"); */
/* ft_putendl("-----------------------------------"); */
	if (!(new = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	new->name = NULL;
	new->path = NULL;
	new->next = NULL;
	new->t = NULL;
	last->next = new;
	new->prev = last;
/* ft_putendl("			DIR_ADD END"); */
/* ft_putendl("-----------------------------------"); */
	return (new);
}

t_dirs	*ft_dir_new(char *path)
{
	t_dirs	*new;

/* ft_putendl("			DIR_NEW"); */
/* ft_putendl("-----------------------------------"); */
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
/* ft_putendl("			DIR_NEW END"); */
/* ft_putendl("-----------------------------------"); */
	return (new);
}

void	ft_dir_form(int *flags, t_dirs *dirs)
{
	t_info		*last;
	t_passwd	*s_pwd;
	t_group		*s_grp;
	size_t		len;

/* ft_putendl("			DIR_FORM"); */
/* ft_putendl("-----------------------------------"); */
	last = dirs->last;
	if (*flags & F_L)
	{
		if ((len = ft_intlen(last->s_stat.st_nlink)) > dirs->s_form.link_len)
			dirs->s_form.link_len = len;

		if (!(*flags & F_O))
		{
			if ((s_pwd = getpwuid(last->s_stat.st_uid)))
			{
				if (s_pwd && s_pwd->pw_name && (len = ft_strlen(s_pwd->pw_name)) > dirs->s_form.usr_len)
					dirs->s_form.usr_len = len;
				else if ((len = ft_intlen((int)*s_pwd->pw_name)) > dirs->s_form.usr_len)
					dirs->s_form.usr_len = len;
			}
		}
			
		if (!(*flags & F_G)) 
		{
			if (( s_grp = getgrgid(last->s_stat.st_gid)))
			{
				if (s_grp && s_grp->gr_name && (len = ft_strlen(s_grp->gr_name)) > dirs->s_form.grp_len)
					dirs->s_form.grp_len = len;
				else if ((len = ft_intlen((int)*s_grp->gr_name)) > dirs->s_form.grp_len)
					dirs->s_form.grp_len = len;
			}
		}

		if ((len = ft_intlen(last->s_stat.st_size)) > dirs->s_form.size_len)
			dirs->s_form.size_len = len;
	}
/* ft_putendl("			DIR_FORM END"); */
/* ft_putendl("-----------------------------------"); */
}

int		ft_dir_fill(int *flags, t_dirs *dirs, char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	t_info		*list;

ft_putendl("			DIR_FILL");
ft_putendl("-----------------------------------");
	if (!(dir = opendir(path)))
		return (ft_error_perm(flags, path));
	list = dirs->list;
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
		/* if (!(*flags & F_F)) */
		/* 	ft_sorts(flags, dirs); */
		/* list = !(*flags & F_F) ? dirs->last->next : list->next; */
		list = list->next;
	}
	closedir(dir);
	if (!(*flags & F_F))
		ft_sorts(flags, dirs);
	ft_prints(flags, dirs);
/* ft_putendl("			DIR_FILL END"); */
/* ft_putendl("-----------------------------------"); */
	return (1);
}

void	ft_dirs(int *flags, char *path)
{
	t_dirs	*dirs;
	t_info	*list;

	if (!(dirs = ft_dir_new(path)))
		return ;
ft_putendl("			DIRS");
ft_putendl("-----------------------------------");
	if (!(ft_dir_fill(flags, dirs, path)))
		return ;
	/* ft_list_print(dirs); */
	if (*flags & F_RR)
	{
		list = (*flags & F_R) ? dirs->last : dirs->list;
		while (list)
		{
			if ((list->name[0] == '.' && list->name[1] == '\0') ||
				((list->name[0] == '.' && list->name[2] == '\0') &&
				list->name[1] == '.'))
			{
				list = (*flags & F_R) ? list->prev : list->next;
				continue;
			}
			else if (ft_ls_check(list->path) == 2)
				ft_dirs(flags, list->path);
			list = (*flags & F_R) ? list->prev : list->next;
		}
	}
	ft_sort_clean(dirs);
/* ft_putendl("			DIRS END"); */
/* ft_putendl("-----------------------------------"); */
}
