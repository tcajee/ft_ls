/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/28 17:58:39 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

/* int ft_path(char path[PATH_MAX], char *name, char full_path[PATH_MAX]) */
/* { */
/* 	int	i; */

	/* i = -1; */
	/* while (path[++i]) */
	/* 	full_path[i] = path[i]; */
	/* if (i && i < PATH_MAX) */
	/* 	if (!(path[0] == '/' && path[1] == '\0')) */
	/* 		full_path[i++] = '/'; */
	/* while (*name && i < PATH_MAX) */
	/* 	full_path[i++] = *name++; */
	/* if (i < PATH_MAX) */
	/* 	full_path[i] = '\0'; */
	/* else */
	/* 	errno = ENAMETOOLONG; */
	/* return ((i < PATH_MAX) ? 1 : 0); */
/* } */

/* static t_file	*ft_new_dir(char path[PATH_MAX], char *name, t_stat *stat) */
/* { */
/* 	if (!(new = (t_file*)ft_memalloc(sizeof(t_file))) */
/* 	|| (!(new->name = ft_strdup(name)))) */
/* 		ls_error(NULL, 2); */
/* 	new->mode = stat->st_mode; */
/* 	new->st_nlink = stat->st_nlink; */
/* 	new->st_uid = stat->st_uid; */
/* 	new->st_gid = stat->st_gid; */
/* 	new->size = stat->st_size; */
/* 	new->st_rdev = stat->st_rdev; */
/* 	new->time = stat->st_mtimespec.tv_sec; */
/* 	new->ntime = stat->st_mtimespec.tv_nsec; */
/* 	new->st_blocks = stat->st_blocks; */
/* 	get_full_path(path, name, new->full_path); */
/* 	return (new); */
/* } */

/* int				ft_add_dir(char path[PATH_MAX], char *name, t_file **lst) */
/* { */
/* 	char		fpath[PATH_MAX]; */
/* 	t_stat		stat; */
/* 	if (!(ft_path(path, name, fpath))) */
/* 	{ */
/* 		ft_error_dirs(*name, 1); */
/* 		return (-1); */
/* 	} */
/* 	if (lstat(fpath, &stat) == -1) */
/* 		return (-1); */
/* 	if (!*lst) */
/* 		*lst = ft_new_dir(path, name, &stat); */
/* 	else */
/* 	{ */
/* 		while ((*lst)) */
/* 			lst = &((*lst)); */
/* 		(*lst) = ft_new_dir(path, name, &stat); */
/* 	} */
/* 	return (1); */
/* } */

int	ft_count_dirs(char **argv)
{
	t_stat stat;
	int i;

	i = -1;
	while (argv[++i])
	{
		FT_(lstat(argv[i], &stat) < 0, ft_error_dirs(argv[i]));
	}
	return (i);
}

int	ft_dirs(char **argv, t_file **dirs)
{
	int i;
	dirs = NULL;
	i = ft_count_dirs(argv);
	printf("dirs: %d\n", i);
	return (1);
}

