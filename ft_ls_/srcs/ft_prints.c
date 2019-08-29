/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/29 17:11:29 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void		ft_print_time(t_stat s_stat, int *flags)
{
	if (*flags & F_l)
	{
		if (*flags & F_u)
			ft_printf_("%s ", ft_strsub(ctime(&s_stat.st_atime), 3, 13));
		else
			ft_printf_("%s ", ft_strsub(ctime(&s_stat.st_mtime), 3, 13));
	}
}

void	ft_print_perm(t_stat *s_stat)
{
	char	permissions[12];

	ft_memset(permissions, '-', 11);
	if ((s_stat->st_mode & S_IFMT) == S_IFDIR)
		permissions[0] = 'd';
	else if ((s_stat->st_mode & S_IFMT) == S_IFREG)
		permissions[0] = '-';
	else if ((s_stat->st_mode & S_IFMT) == S_IFCHR)
		permissions[0] = 'c';
	else if ((s_stat->st_mode & S_IFMT) == S_IFBLK)
		permissions[0] = 'b';
	else if ((s_stat->st_mode & S_IFMT) == S_IFLNK)
		permissions[0] = 'l';
	else if ((s_stat->st_mode & S_IFMT) == S_IFSOCK)
		permissions[0] = 's';
	else if ((s_stat->st_mode & S_IFMT) == S_IFIFO)
		permissions[0] = 'p';
	/* else if ((s_stat->st_mode & S_IFMT) == S_IFWHT) */
	/* 	permissions[0] = 'w'; */
	if (s_stat->st_mode & S_IRUSR)
		permissions[1] = 'r';
	if (s_stat->st_mode & S_IWUSR)
		permissions[2] = 'w';
	if (s_stat->st_mode & S_IXUSR)
		permissions[3] = 'x';
	if (s_stat->st_mode & S_IRGRP)
		permissions[4] = 'r';
	if (s_stat->st_mode & S_IWGRP)
		permissions[5] = 'w';
	if (s_stat->st_mode & S_IXGRP)
		permissions[6] = 'x';
	if (s_stat->st_mode & S_IROTH)
		permissions[7] = 'r';
	if (s_stat->st_mode & S_IWOTH)
		permissions[8] = 'w';
	if (s_stat->st_mode & S_IXOTH)
		permissions[9] = 'x';
	permissions[10] = ' ';
	permissions[11] = '\0';
	ft_printf_("%s ", permissions);
}

int	ft_print_def(int *flags, t_info *list)
{
	ft_printf_("%s", list->name);
	if (*flags & F_F)
	{
		if (ft_ls_check(list->path) == 2)
			ft_printf_("/");
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFLNK)
			ft_printf_("@");
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFIFO)
			ft_printf_("|");
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFSOCK)
			ft_printf_("=");
		else if (list->s_stat.st_mode & S_IXUSR)
			ft_printf_("*");
	}
	ft_printf_("\n");
	return (1);
}

int	ft_print_lst(int *flags, t_info *list)
{
	t_passwd	*s_pwd;
	t_group		*s_grp;

 /* ft_putendl("beg print ls"); */
	ft_print_perm(&list->s_stat);
	ft_printf_("%5x ", list->s_stat.st_nlink);
	s_pwd = getpwuid(list->s_stat.st_uid);
	if (s_pwd)
		ft_printf_("%10s", s_pwd->pw_name);
	else
		ft_printf_("%10d", list->s_stat.st_uid);
	s_grp = getgrgid(list->s_stat.st_gid);
	if (!(*flags & F_g))
	{
		if (s_grp)
			ft_printf_("%10s", s_grp->gr_name);
		else
			ft_printf_("%10d", list->s_stat.st_gid);
	}
	ft_printf_("%10d", list->s_stat.st_size);
	ft_print_time(list->s_stat, flags);
	ft_print_def(flags, list);
	return (1);
}

int	ft_prints(int *flags, t_dirs *dirs)
{
/* ft_putendl("begin print"); */
	t_info	*list;
	int j;

 /* ft_putendl("begin print"); */
	if ((*flags & F_M || *flags & F_R) && *flags & F_P && !(*flags & F_REG))
	{
		ft_printf_("\n");
		ft_printf_("%s:\n", dirs->list->root);
	}
 /* ft_putendl("begin print"); */
	list = dirs->list;
	if (*flags & F_l && !(*flags & F_REG))
	{
		ft_printf_("%d%d\n", "total ", dirs->total);
	}
 /* ft_putendl("begin print"); */
	*flags |= F_P;
 	/* ft_putnbr(dirs->size); */
 	/* ft_putendl(""); */
	j = dirs->size;
 	/* ft_putendl("set list"); */
	list = (*flags & F_r && !(*flags & F_REG)) ? dirs->last: dirs->list;
 /* ft_putendl("begin print"); */
	while (j--)
	{
 		/* ft_putendl("increment list"); */
 		/* ft_putendl("check . print"); */
 		/* ft_putendl(list->name); */
		if (!(*flags & F_a) && list->name[0] == '.')
			if (!(*flags & F_REG))
				continue;
 		/* ft_putendl("choose print"); */
		if (*flags & F_1)
			ft_print_def(flags, list);
		else if (*flags & F_l)
			ft_print_lst(flags, list);
		list = (*flags & F_r && !(*flags & F_REG)) ? list->prev: list->next;
	}
//	ft_list_clean(dirs);
 /* ft_putendl("end print"); */
	return (1);
}
