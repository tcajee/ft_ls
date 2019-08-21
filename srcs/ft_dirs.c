/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/21 16:16:10 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_dir_clean(t_info dirs[])
{
	int i;

	i = dirs[0].dirc;
	F(dirs[0].total, free(dirs[0].total));
	while (i--)
	{
		F(dirs[i].root, free(dirs[i].root));
		F(dirs[i].path, free(dirs[i].path));
		F(dirs[i].name, free(dirs[i].name));
	}
}

int	ft_dir_check(char *path)
{
	t_stat	s_stat;

	F_(lstat(path, &s_stat) < 0, 0);
	F_((s_stat.st_mode & S_IFMT) == S_IFDIR, 1);
	return (0);
}

char	*ft_dir_path(char *path, char *d_name)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(path) + ft_strlen(d_name);
	F_(!(temp = (char *)malloc(sizeof(char) * (len + 2))), NULL);
	___(*path, temp[i++] = *path++);
	F(temp[i - 1] == '/', i = i);
	_(temp[i++] = '/');
	___(*d_name, temp[i++] = *d_name++);
	temp[i] = '\0';
	return (temp);
}

int	ft_dir_info(char *path, t_info dirs[])
{
	t_dirent	*s_dir;
	DIR			*dir;
	int i;
	int total;

	i = 0;
	total = 0;
	F_(!(dir = opendir(path)), 0);
	while ((s_dir = readdir(dir)) != NULL && i < 1024)
	{
		F_(!(dirs[i].root = ft_strdup(path)), 0);
		F_(!(dirs[i].name = ft_strdup(s_dir->d_name)), 0);
		F_(!(dirs[i].path = ft_dir_path(path, s_dir->d_name)), 0);
		F_((lstat(dirs[i].path, &dirs[i].s_stat)) < 0, 0);
		total += dirs[i++].s_stat.st_blocks;
	}
	closedir(dir);
	dirs[0].total = ft_itoa(total);
	dirs[0].dirc = i;
	return (1);
}

int ft_dirs(t_flags *flags, t_info dirs[], char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	char		*fpath;


	F(!path, ft_dir_info(".", dirs));
	_F_(!ft_dir_info(path, dirs), ft_errors(E_DIRS, path));
	F((*flags & F_M || *flags & F_R) && *flags & F_P,
	F(!!(ft_print_f("n")), ft_print_f("%:n", dirs[0].root)));
	F(*flags & F_l, ft_print_f("%%n", "total: ", dirs[0].total));

	ft_prints(flags, dirs);
	ft_sorts(dirs);
	ft_prints(flags, dirs);
	ft_dir_clean(dirs);
	B_1(*flags, F_P);
	if (*flags & F_R)
	{
		F_(!(dir = opendir(path)), E_DIRS);
		while ((s_dir = readdir(dir)) != NULL)
		{
			F(IS_DOT(s_dir->d_name) || IS_DDOT(s_dir->d_name), continue);
			F(ft_dir_check(fpath = ft_dir_path(path, s_dir->d_name)),
			ft_dirs(flags, dirs, fpath));
			free(fpath);
		}
		closedir(dir);
	}
	return (0);
}
