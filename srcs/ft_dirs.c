/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/06 18:01:36 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_dir_check(char *path)
{
	struct stat	s_stat;

	FT_(lstat(path, &s_stat) < 0, 0);
	FT_((s_stat.st_mode & S_IFMT) == S_IFDIR, 1);
	return (0);
}

int	ft_dir_path(char *path, char *d_name, char **fpath)
{
	int		i;
	int		len;
	char	*temp;

	i = -1;
	len = ft_strlen(path) + ft_strlen(d_name) + 1;
	FT_(!(temp = (char *)malloc(sizeof(char) * (len + 2))), 0);
	while (*path)
		temp[++i] = *path++;
	temp[++i] = '/';
	while (*d_name)
		temp[++i] = *d_name++;
	temp[++i] = '\0';
	FT_(ft_dir_check(temp), !!(*fpath = temp));
	return (0);
}

int	ft_dirs(char **argv, t_flags *flags)
{
	int i;
	int k;

	i = -1;
	k = -1;
	FT_(!argv[0], ft_prints(".", flags));
	while (argv[++i])
		F_(!(ft_dir_check(argv[i])), ft_errors(E_PRINTS, argv[i]));
	while (argv[++k])
		F_(ft_dir_check(argv[k]), ft_prints(argv[k], flags));
	return (i);
}

/* {{{TITLE
 
  	
char	*dirname(char *fname, char *s_stat)
{
	 char *ptr;
	 strcpy (s_stat, fname);
	 if ((ptr = strrchr (s_stat, '/')) == NULL)
	 {
		 s_stat[0] = '.';
		 s_stat[1] = '\0';
	 }
	 else if (s_stat != ptr)
	 {
		 *ptr++ = '\0';
		 if(*ptr == '\0')
		 {
			 ptr = strrchr (s_stat, '/');
			 if (ptr != NULL && s_stat != ptr)
				 *ptr = '\0';
		 }
	 }
	 printf("s_stat: %s\n", s_stat);
	 return s_stat;
 }
char *get_path(char *path, char *name)
{
	char	*ret;
	const size_t	size = ft_strlen(path) + ft_strlen(name) + 2;
	ret = ft_strnew(size);
	ret = ft_strcpy(ret, name);
	ft_strlcat(ret, "/", size);
	ft_strlcat(ret, name, size);
	return (ret);
 }
int ft_path(char path[PATH_MAX], char *name, char full_path[PATH_MAX])
{
	int i;
	i = -1;
	while (path[++i])
		full_path[i] = path[i];
	if (i && i < PATH_MAX)
		if (!(path[0] == '/' && path[1] == '\0'))
			full_path[i++] = '/';
	while (*name && i < PATH_MAX)
		full_path[i++] = *name++;
	if (i < PATH_MAX)
		full_path[i] = '\0';
	else
		errno = ENAMETOOLONG;
	return ((i < PATH_MAX) ? 1 : 0);
}

 
}}} */

/* {{{TITLE
 
 	

int	ft_rec_prints(char *path, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*s_dirent;
	char			*fpath[1024];
	int 			i;
	int 			j;
	i = 0;
	dir = opendir(path);
	FT_(!dir, E_PRINTS);
	while ((s_dirent = readdir(dir)))
	{

		printf("path: %s\n", path);
		printf("s_dir: %s\n", s_dirent->d_name);
		printf("fpath: %s\n", fpath[i] =get_path(path, s_dirent->d_name));

		if (ft_ls_isdir(fpath[i] = get_path(path, s_dirent->d_name)))
		{
			if (path[ft_strlen(path) - 1] == '/')
				fpath[i] = ft_strjoin(path, s_dirent->d_name);
			else
				fpath[i] = ft_strjoin(ft_strjoin(path, "/"), s_dirent->d_name);
			printf("fpath: %s\n", fpath[i]);
			++i;
			closedir(dir);
			j = -1;
			while (++j < i)
				ft_rec_prints(fpath[j], flags);
		}
	}
	return (1);
}

}}} */

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











