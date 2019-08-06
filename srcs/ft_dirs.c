/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/06 13:29:32 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_dir_check(char *path)
{
	struct stat	s_stat;

	FT(lstat(path, &s_stat) < 0, ft_errors(E_DIRS, path));
	FT_((s_stat.st_mode & S_IFMT) == S_IFDIR, 1);
	return (0);
}

char *ft_dir_path(char *path, char *d_name)
{
	int		i;
	int		j;
	char	temp[ft_strlen(path) + ft_strlen(d_name) + 1];
	int	len;

	i = -1;
	j = 0;
	len = ft_strlen(path) + ft_strlen(d_name) + 1;
	while (j < len)
	{
		while (path[++i])
			temp[i] = path[i];
		temp[i] = '/';
		j += i;
		i = -1;
		while (d_name[++i])
			temp[j++] = d_name[i];
	}
	if (temp[j])
		temp[j] = '\0';
	if (ft_dir_check(temp))
		return (ft_strdup(temp));
	else
		return (NULL);
}

int	ft_dirs(char **argv, t_flags *flags)
{
	t_stat s_stat;
	int i;
	int k;

	i = -1;
	k = -1;
	FT_(!argv[0], ft_prints(".", flags));
	while (argv[++i])
		FT(lstat(argv[i], &s_stat) < 0, ft_errors(E_PRINTS, argv[i]));
	while (argv[++k])
		FT(ft_dir_check(argv[k]), ft_prints(argv[k], flags));
	return (i);
}

 /* {{{TITLE */
/* nt ft_path(char path[PATH_MAX], char *name, char full_path[PATH_MAX]) */ 
 /* { g */
 /* 	int	i; g */
 /*   i = -1; g */
 /*   while (path[++i]) g */
 /*   	full_path[i] = path[i]; g */
 /*   if (i && i < PATH_MAX) g */
 /*   	if (!(path[0] == '/' && path[1] == '\0')) g */
 /*   		full_path[i++] = '/'; g */
 /*   while (*name && i < PATH_MAX) g */
 /*   	full_path[i++] = *name++; g */
 /*   if (i < PATH_MAX) g */
 /*   	full_path[i] = '\0'; g */
 /*   else g */
 /*   	errno = ENAMETOOLONG; g */
 /*   return ((i < PATH_MAX) ? 1 : 0); g */
 /* } g */
 /* static t_file	*ft_new_dir(char path[PATH_MAX], char *name, t_stat *stat) g */
 /* { g */
 /* 	if (!(new = (t_file*)ft_memalloc(sizeof(t_file))) g */
 /* 	|| (!(new->name = ft_strdup(name)))) g */
 /* 		ls_error(NULL, 2); g */
 /* 	new->mode = stat->st_mode; g */
 /* 	new->st_nlink = stat->st_nlink; g */
 /* 	new->st_uid = stat->st_uid; g */
 /* 	new->st_gid = stat->st_gid; g */
 /* 	new->size = stat->st_size; g */
 /* 	new->st_rdev = stat->st_rdev; g */
 /* 	new->time = stat->st_mtimespec.tv_sec; g */
 /* 	new->ntime = stat->st_mtimespec.tv_nsec; g */
 /* 	new->st_blocks = stat->st_blocks; g */
 /* 	get_full_path(path, name, new->full_path); g */
 /* 	return (new); g */
 /* } g */
 /* int				ft_add_dir(char path[PATH_MAX], char *name, t_file **lst) g */
 /* { g */
 /* 	char		fpath[PATH_MAX]; g */
 /* 	t_stat		stat; g */
 /* 	if (!(ft_path(path, name, fpath))) g */
 /* 	{ g */
 /* 		ft_error_dirs(*name, 1); g */
 /* 		return (-1); g */
 /* 	} g */
 /* 	if (lstat(fpath, &stat) == -1) g */
 /* 		return (-1); g */
 /* 	if (!*lst) g */
 /* 		*lst = ft_new_dir(path, name, &stat); g */
 /* 	else g */
 /* 	{ g */
 /* 		while ((*lst)) g */
 /* 			lst = &((*lst)); g */
 /* 		(*lst) = ft_new_dir(path, name, &stat); g */
 /* 	} g */
 /* 	return (1); g */
 /* } g */
/* g */
/* }}} */ 











