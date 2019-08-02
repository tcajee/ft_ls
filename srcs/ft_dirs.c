/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/02 14:52:07 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_error_dirs(char *arg)
{
	ft_putstr_fd("./ft_ls: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(":", 2);
	ft_putendl_fd("No such file or directory", 2);
	return (E_DIRS);
}

int		ft_check_dirs(char *path)
{
	struct stat s_stat;

	FT_((lstat(path, &s_stat)) < 0, ft_error_dirs(path));
	return ((s_stat.st_mode & S_IFMT) == S_IFDIR);
}

int	ft_dirs(char **argv, t_flags *flags)
{
	int i;

	i = 0;
	while (argv[i] && ft_check_dirs(argv[i]))
		ft_ls(argv[i++], flags);
	return (errno);
}


void	ft_recur_prints(char *path, t_flags* flags)
{
	DIR				*dp;
	struct dirent	*dir;
	t_files			*files; // Put in struct
	int 			i;
	int 			j;
	i = 0;


	while ((dir = readdir(dp)) != NULL)
	{

		//		ft_check_flags() check flags to set type of print
		

				// No -a flag. Need flag check before print call
		if (dir->d_name[0] != '.' && *flags == F_1); 
		ft_def_print(name, dir->d_name); // call print function. What do we feed it?
		
		
		if ((-R))
		{
			if (ft_ls_isdir(ft_strjoin(ft_strjoin(name, "/"), dir->d_name)) && dir->d_name[0] != '.')
			{
				if (name[ft_strlen(name) -1] == '/')
					files->rec[i] = ft_strjoin(name, dir->d_name); // newname struct
				else
					files->rec[i] = ft_strjoin(ft_strjoin(name, "/"), dir->d_name); // struct
				++i;
	{ 		}
			closedir(dp);
			j = 0;
			while (j < i)
			{
				printf("\n%s:\n", files->rec[j]); // struct
				list(files->rec[j]);              // struct
				++j;
			}
		}
	}
}}



/*
 * LeRoux dir check function
int		ft_is_dir(char *path)
{
	struct stat s;
	
	if (lstat(name, &s) < 0)
		perror("Stat: ");
	if (S_ISREG(s.st_mode))
	{
		return (0);
	}
	else
	{
		return (S_ISDIR(s.st_mode));
	}
}*/



/* int	ft_count_dirs(char **argv) */
/* { */
/* 	t_stat stat; */
/* 	int i; */
/* 	i = -1; */
/* 	while (argv[++i]) */
/* 		FT_(lstat(argv[i], &stat) < 0, ft_error_dirs(argv[i])); */
/* 	return (i); */
/* } */


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











