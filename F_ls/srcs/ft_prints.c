/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/23 14:26:15 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_print_f(char *ft, ...)
{
	va_list	v_list;
	int		i;

	i = -1;
	va_start (v_list, ft);
	while (ft[++i])
	{
		F(ft[i] == '%', ft_putstr(va_arg(v_list, char *)));
		_F(ft[i] == 'n', ft_putendl(""));
		_F(ft[i] == 't', ft_putstr("	"));
		_F(ft[i] == '.', ft_putendl(""));
		_F(ft[i], ft_putchar(ft[i]));
	}
	va_end (v_list);
	return (1);
}

void	print_time_str(time_t secs)
{
	const char	*str = ctime(&secs);

	printf("%.2s", str + 8);
	printf(" %.3s", str + 4);
	if (time(NULL) - (time_t)(60 * 60 * 24 * 30.42 * 6) > secs)
		printf("  %.4s", str + 20);
	else if (time(NULL) < secs)
	{
		if (str[20] == ' ')
			printf("  %.5s", str + 24);
		else
			printf("  %.4s", str + 20);
	}
	else
		printf(" %.5s", str + 11);
}

void		ft_print_time(t_stat s_stat, int *flags)
{
	F(*flags & F_u, print_time_str(s_stat.st_atime));
	_F(*flags & F_t, print_time_str(s_stat.st_mtime));
}

void	ft_print_perm(t_stat *s_stat)
{
	char	permissions[12];

	ft_memset(permissions, '-', 11);
	F((s_stat->st_mode & S_IFMT) == S_IFDIR, permissions[0] = 'd');
	_F((s_stat->st_mode & S_IFMT) == S_IFREG, permissions[0] = '-');
	_F((s_stat->st_mode & S_IFMT) == S_IFCHR, permissions[0] = 'c');
	_F((s_stat->st_mode & S_IFMT) == S_IFBLK, permissions[0] = 'b');
	_F((s_stat->st_mode & S_IFMT) == S_IFLNK, permissions[0] = 'l');
	_F((s_stat->st_mode & S_IFMT) == S_IFSOCK, permissions[0] = 's');
	_F((s_stat->st_mode & S_IFMT) == S_IFIFO, permissions[0] = 'p');
	F(s_stat->st_mode & S_IRUSR, permissions[1] = 'r');
	F(s_stat->st_mode & S_IWUSR, permissions[2] = 'w');
	F(s_stat->st_mode & S_IXUSR, permissions[3] = 'x');
	F(s_stat->st_mode & S_IRGRP, permissions[4] = 'r');
	F(s_stat->st_mode & S_IWGRP, permissions[5] = 'w');
	F(s_stat->st_mode & S_IXGRP, permissions[6] = 'x');
	F(s_stat->st_mode & S_IROTH, permissions[7] = 'r');
	F(s_stat->st_mode & S_IWOTH, permissions[8] = 'w');
	F(s_stat->st_mode & S_IXOTH, permissions[9] = 'x');
	permissions[10] = ' ';
	permissions[11] = '\0';
	ft_print_f("%t", permissions);
}

int	ft_print_def(t_info dir)
{
	ft_print_f("%", dir.name);
	F(ft_dir_check(dir.path), ft_print_f("/n"));
	_F(dir.s_stat.st_mode & S_IXUSR, ft_print_f("*n"));
	_(ft_print_f("n"));
	return (1);
}

int	ft_print_lst(int *flags, t_info dir)
{
	t_passwd	*s_pwd;
	t_group		*s_grp;

	ft_print_perm(&dir.s_stat);
	ft_print_f("%t", "XX");
	/*
	 * dir.s_stat.st_nlink);
	 */
	s_pwd = getpwuid(dir.s_stat.st_uid);
	ft_print_f("%t", s_pwd->pw_name);
	s_grp = getgrgid(dir.s_stat.st_gid);
	F(!(*flags & F_g), ft_print_f("%t", s_grp->gr_name));
	ft_print_f("%t", "XX");
	/*
	 * dir.s_stat.st_size);
	 */
	ft_print_f("%t", "XXX XX XX:XX");
	/*
	 * ft_print_time(dir.s_stat, flags);
	 */
	ft_print_f(" ");
	ft_print_def(dir);
	return (1);
}

int	ft_prints(int *flags, t_info dirs[])
{
	int i;

	F__(*flags & F_r, i = dirs[0].dirc, i = -1);
	while (*flags & F_r ? i-- : ++i)
	{
		F(!(*flags & F_a) && dirs[i].name[0] == '.', continue);
		F(*flags & F_1, ft_print_def(dirs[i]));
		_F(*flags & F_l, ft_print_lst(flags, dirs[i]));
	}
	return (1);
}
