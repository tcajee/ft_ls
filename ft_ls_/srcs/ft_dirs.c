/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/06 15:46:10 by tcajee           ###   ########.fr       */
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
	new->t = NULL;
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

/* ft_putendl("			FORM"); */
/* ft_putendl("-----------------------------------"); */
	if (*flags & F_L)
	{
		last = dirs->last;
		if ((len = ft_intlen(last->s_stat.st_nlink)) > dirs->s_form.link_len)
			dirs->s_form.link_len = len;

		
		
/* ft_putendl(""); */
/* ft_putendl("S_PWD"); */
/* ft_putendl("-----------------------------------"); */
/* ft_putendl(last->name); */
/* ft_putendl("-----------------------------------"); */
/* ft_putendl(last->path); */
/* ft_putendl("-----------------------------------"); */

		/* if ((s_pwd = getpwuid(last->s_stat.st_uid)) != NULL) */
		/* { */
		/* 	if (s_pwd->pw_name) */
		/* 		ft_putendl(s_pwd->pw_name); */
		/* else */
		/* 	ft_putnbr(*s_pwd->pw_name); */
		/* } */


		if ((s_pwd = getpwuid(last->s_stat.st_uid)) != NULL)
		{
		
			if ((len = ft_intlen((int)*s_pwd->pw_name)) > dirs->s_form.usr_len)
			{
				dirs->s_form.usr_len = len;
			}
			else if (s_pwd && (len = ft_strlen(s_pwd->pw_name)) > dirs->s_form.usr_len)
			{
				dirs->s_form.usr_len = len;
			}

		}
	
		
/* ft_putendl("-----------------------------------"); */
		
/* ft_putendl(""); */
/* ft_putendl("S_GRP"); */
		s_grp = getgrgid(last->s_stat.st_gid);
/* ft_putnbr((int)*s_grp->gr_name); */
		if (s_grp && (len = ft_strlen(s_grp->gr_name)) > dirs->s_form.grp_len)
			dirs->s_form.grp_len = len;
		else if ((len = ft_intlen((int)*s_grp->gr_name)) > dirs->s_form.grp_len)
			dirs->s_form.grp_len = len;

		
		
		
		
		if ((len = ft_intlen(last->s_stat.st_size)) > dirs->s_form.size_len)
			dirs->s_form.size_len = len;
	}
/* ft_putendl("			FORM END"); */
/* ft_putendl("-----------------------------------"); */
}

int		ft_dir_fill(int *flags, t_dirs *dirs, char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	t_info		*list;

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
		if (!(*flags & F_F))
			ft_sorts(flags, dirs);
		list = !(*flags & F_F) ? dirs->last->next : list->next;
		/* list = list->next; */
	}
	closedir(dir);
	/* if (!(*flags & F_F)) */
	/* 	ft_sorts(flags, dirs); */
	ft_prints(flags, dirs);
	return (1);
}

void	ft_dirs(int *flags, t_dirs *dirs, char *path)
{
	t_dirs	*rdirs;
	t_info	*list;

/* ft_putendl("			DIRS"); */
/* ft_putendl("-----------------------------------"); */
	if (!(ft_dir_fill(flags, dirs, path)))
		return ;
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
			{
				if (!(rdirs = ft_dir_new(list->path)))
					return ;
				/* if (!(ft_dir_fill(flags, rdirs, list->path))) */
				/* 	return ; */
				ft_dirs(flags, rdirs, list->path);
				ft_sort_clean(rdirs);
			}
			list = (*flags & F_R) ? list->prev : list->next;
		}
	}
/* ft_putendl("			DIRS END"); */
/* ft_putendl("-----------------------------------"); */
}
