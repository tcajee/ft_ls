/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/28 15:47:42 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_dir_check(char *path)
{
	t_stat	s_stat;
	if (lstat(path, &s_stat) < 0)
		return (0);
	if ((s_stat.st_mode & S_IFMT) == S_IFREG)
		return (1);
	if ((s_stat.st_mode & S_IFMT) == S_IFDIR)
		return (2);
	return (0);
}

char	*ft_dir_path(char *path, char *d_name)
{
	int		i;
	int		len;
	char	*temp;
	i = 0;

	len = ft_strlen(path) + ft_strlen(d_name);
	if (!(temp = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (*path)
		temp[i++] = *path++;
	if (temp[i - 1] == '/')
		temp[i] = '/';
	else
		temp[i++] = '/';
	while (*d_name)
		temp[i++] = *d_name++;
	temp[i] = '\0';
	return (temp);
}

int ft_dir_finfo(int *flags, t_dirs *dirs, char *path)
{
	F_SET(*flags, F_0, F_REG);
	if (!(dirs->name = ft_strdup(path)))
		return (0);
	lstat(dirs->name, &dirs->s_stat);
	dirs->size = 2;
	ft_prints(flags, dirs);
	free(dirs->name);
	F_SET(*flags, F_REG, F_0);
	return (1);
}

int	ft_dir_dinfo(int *flags, t_dirs *dirs, char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	int			size;
	int			total;
	t_info		*list;

	size = 0;
	total = 0;
	if (!dirs->list)
		if (!(dirs->list = ft_list_new()))
			return (0);
	list = dirs->list;
	if (!(dir = opendir(path)))
		return (ft_errors(flags, E_PRINTS, path));
	while ((s_dir = readdir(dir)) != NULL)
	{
		if (list != dirs->list && !(list = list->next))
			if (!(list = ft_list_add(list)))
				return (0);
		if (!(list->root = ft_strdup(path)))
			return (0);
		if (!(list->name = ft_strdup(s_dir->d_name)))
			return (0);
		if (!(list->path = ft_dir_path(path, s_dir->d_name)))
			return (0);
		if ((lstat(list->path, &list->s_stat)) < 0)
			return (0);
		total += list->s_stat.st_blocks;
		size ++;
	}
	closedir(dir);
	dirs->total = ft_itoa(total);
	dirs->size = size;
	dirs->last = list;
	return (1);
}

int ft_dirs(int *flags, char *path)
{
	t_dirs		*dirs;

	dirs = (t_dirs *)malloc(sizeof(t_dirs));
	if (ft_dir_check(path) == 1 && (!dirs || !(ft_dir_finfo(flags, dirs, path))))
		return (0);
	else if (ft_dir_check(path) == 2 && (!dirs || !(ft_dir_dinfo(flags, dirs, path))))
		return (0);
	
	/* if (dirs->size > 1 && !(*flags & F_REG) && !(*flags & F_f)) */
	/* 	ft_sorts(flags, dirs); */
	
	
	ft_prints(flags, dirs);
	if (*flags & F_R)
		ft_ls_rec(flags, path);
	return (1);
}
