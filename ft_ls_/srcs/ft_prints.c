/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/29 12:07:16 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_print_f(char *ft, ...)
{
	va_list	v_list;
	int		i;

	i = -1;
	va_start(v_list, ft);
	while (ft[++i])
	{
		if (ft[i] == '%')
			ft_putstr(va_arg(v_list, char *));
		else if (ft[i] == 'n')
			ft_putendl("");
		else if (ft[i] == 't')
			ft_putstr("	");
		else if (ft[i] == '.')
			ft_putendl("");
		else if (ft[i])
			ft_putchar(ft[i]);
	}
	va_end(v_list);
	return (1);
}

void	print_time_str(time_t secs)
{
	/* const char	*str = ctime(&secs); */

	(void)secs;
	ft_print_f("XXX XX  XX:XX ");
	/* ft_print_f("%", str + 8); */
	/* ft_print_f(" %", str + 4); */
	/* if (time(NULL) - (time_t)(60 * 60 * 24 * 30.42 * 6) > secs) */
	/* 	ft_print_f("  %", str + 20); */
	/* else if (time(NULL) < secs) */
	/* { */
	/* 	if (str[20] == ' ') */
	/* 		ft_print_f("  %", str + 24); */
	/* 	else */
	/* 		ft_print_f("  %", str + 20); */
	/* } */
	/* else */
	/* 	ft_print_f(" %", str + 11); */

}

void		ft_print_time(t_stat s_stat, int *flags)
{
	if (*flags & F_l)
	{
		if (*flags & F_u)
			print_time_str(s_stat.st_atime);
		else
			print_time_str(s_stat.st_mtime);
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
	ft_print_f("%  ", permissions);
}

int	ft_print_def(int *flags, t_info *list)
{
 /* ft_putendl("end print def"); */
	ft_print_f("%", list->name);
	if (*flags & F_F)
	{
		if (ft_dir_check(list->path) == 2)
			ft_print_f("/");
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFLNK)
			ft_print_f("@");
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFIFO)
			ft_print_f("|");
		else if ((list->s_stat.st_mode & S_IFMT) == S_IFSOCK)
			ft_print_f("=");
		else if (list->s_stat.st_mode & S_IXUSR)
			ft_print_f("*");
	}
	ft_print_f("n");
 /* ft_putendl("end print def"); */
	return (1);
}

int	ft_print_lst(int *flags, t_info *list)
{
	char		*temp;
	t_passwd	*s_pwd;
	t_group		*s_grp;

 /* ft_putendl("beg print ls"); */
	ft_print_perm(&list->s_stat);
	ft_print_f("%t", temp = ft_itoa(list->s_stat.st_nlink));
	free(temp);
	s_pwd = getpwuid(list->s_stat.st_uid);
	if (s_pwd)
		ft_print_f("%t", s_pwd->pw_name);
	else
	{
		ft_print_f("%t", temp = ft_itoa(list->s_stat.st_uid));
		free(temp);
	}
	s_grp = getgrgid(list->s_stat.st_gid);
	if (!(*flags & F_g))
	{
		if (s_grp)
			ft_print_f("%t", s_grp->gr_name);
		else
		{
			ft_print_f("%t", temp = ft_itoa(list->s_stat.st_gid));
			free(temp);
		}
	}
	ft_print_f("%t", temp = ft_itoa(list->s_stat.st_size));
	free(temp);
	ft_print_time(list->s_stat, flags);
	ft_print_def(flags, list);
 /* ft_putendl("end print ls"); */
	return (1);
}

int	ft_prints(int *flags, t_dirs *dirs)
{
 /* ft_putendl("begin print"); */
	t_info	*list;
	int j;

	list = dirs->list;
	if ((*flags & F_M || *flags & F_R) && *flags & F_P && !(*flags & F_REG))
	{
 		ft_putendl("print name");
		ft_print_f("n");
		ft_print_f("%:n", list->root);
	}
	if (*flags & F_l && !(*flags & F_REG))
	{
 		ft_putendl("print tottal");
		ft_print_f("%%n", "total ", dirs->total);
	}
	*flags |= F_P;
 	ft_putnbr(dirs->size);
 	ft_putendl("");
	j = dirs->size;
 	ft_putendl("set list");
	list = (*flags & F_r && !(*flags & F_REG)) ? dirs->last: dirs->list;
	while (j--)
	{
 		ft_putendl("increment list");
		list = (*flags & F_r && !(*flags & F_REG)) ? list->prev: list->next;
 		ft_putendl("check . print");
 		/* ft_putendl(list->name); */
		if (!(*flags & F_a) && list->name[0] == '.')
			if (!(*flags & F_REG))
				continue;
 		/* ft_putendl("choose print"); */
		if (*flags & F_1)
			ft_print_def(flags, list);
		else if (*flags & F_l)
			ft_print_lst(flags, list);
	}
	ft_list_clean(dirs);
 /* ft_putendl("end print"); */
	return (1);
}
