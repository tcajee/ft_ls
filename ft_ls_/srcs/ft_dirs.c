/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/27 18:47:43 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_dir_clean(t_info dirs[])
{
	int i;

	i = dirs[0].dirc;
	if (dirs[0].total)
		free(dirs[0].total);
	while (i--)
	{
		if (dirs[i].root)
			free(dirs[i].root);
		if (dirs[i].path)
			free(dirs[i].path);
		if (dirs[i].name)
			free(dirs[i].name);
	}
}

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

int	ft_dir_info(int *flags, char *path, t_info dirs[])
{
	t_dirent	*s_dir;
	DIR			*dir;
	int i;
	int total;

	/* ft_putstr("info"); */
	/* ft_putendl(""); */

	
	i = 1;
	total = 0;
	if (!(dir = opendir(path)))
		return (ft_errors(flags, E_PRINTS, path));
	while ((s_dir = readdir(dir)) != NULL)
	{
		if (!(dirs[i].root = ft_strdup(path)))
			return (0);
		if (!(dirs[i].name = ft_strdup(s_dir->d_name)))
			return (0);
		if (!(dirs[i].path = ft_dir_path(path, s_dir->d_name)))
			return (0);
		if ((lstat(dirs[i].path, &dirs[i].s_stat)) < 0)
			return (0);
		total += dirs[i++].s_stat.st_blocks;
	}
	closedir(dir);
	dirs[0].total = ft_itoa(total);
	dirs[0].dirc = i;
	return (1);
}

int ft_dirs(int *flags, t_info dirs[], char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	char		*fpath;

	if (!ft_dir_info(flags, path, dirs))
		return (-1);
	

	ft_prints(flags, dirs);
	
	if (dirs[0].dirc > 2)
		ft_sorts(flags, dirs);
	ft_prints(flags, dirs);
	
	
	
	ft_dir_clean(dirs);
	if (*flags & F_R)
	{
		if (!(dir = opendir(path)))
			exit(-1);
		while ((s_dir = readdir(dir)) != NULL)
		{
			if ((s_dir->d_name[0] == '.' && s_dir->d_name[1] == '\0') ||
			   ((s_dir->d_name[0] == '.' && s_dir->d_name[2] == '\0') &&
				s_dir->d_name[1] == '.'))
				continue;
			if (ft_dir_check(fpath = ft_dir_path(path, s_dir->d_name)) == 2)
				ft_dirs(flags, dirs, fpath);
			free(fpath);
		}
		closedir(dir);
	}
	return (0);
}
