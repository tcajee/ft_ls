/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/14 11:42:03 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_print_f(int format, char *path, char *d_name)
{
	char *fpath;

	if (format == F_M)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	else if (format == F_1)
	{
		if ((fpath = ft_dir_path(path, d_name)))
		{
			ft_putstr(fpath);
			ft_putendl("/");
			free(fpath);
		}
		else
			ft_putendl(path);
	}
}

void	ft_print_perm(t_stat *s_stat)
{
	char	permissions[11];

	F_((s_stat->st_mode & S_IFMT) == S_IFDIR, permissions[0] = 'd');
	F_((s_stat->st_mode & S_IFMT) == S_IFREG, permissions[0] = '-');
	F_((s_stat->st_mode & S_IFMT) == S_IFCHR, permissions[0] = 'c');
	F_((s_stat->st_mode & S_IFMT) == S_IFBLK, permissions[0] = 'b');
	F_(s_stat->st_mode == 16749, permissions[0] = 'l');
	F_(s_stat->st_mode & S_IRUSR, permissions[1] = 'r');
	F_(s_stat->st_mode & S_IWUSR, permissions[2] = 'w');
	F_(s_stat->st_mode & S_IXUSR, permissions[3] = 'x');
	F_(s_stat->st_mode & S_IRGRP, permissions[4] = 'r');
	F_(s_stat->st_mode & S_IWGRP, permissions[5] = 'w');
	F_(s_stat->st_mode & S_IXGRP, permissions[6] = 'x');
	F_(s_stat->st_mode & S_IROTH, permissions[7] = 'r');
	F_(s_stat->st_mode & S_IWOTH, permissions[8] = 'w');
	F_(s_stat->st_mode & S_IXOTH, permissions[9] = 'x');
	ft_ls_print("% ", permissions);
}

int	ft_print_def(t_flags *flags, t_dirs *info)
{
	ft_putendl("def_prints:");
	/* DIR			*dir; */
	/* t_dirent	*s_dir; */
	int i;

	i = 0;
	/* dir = opendir(path); */
	/* FT_(!dir, E_PRINTS); */
	*flags |= F_M;
	F_(*flags & F_M || *flags & F_R, ft_print_f(F_M, dirs->path, NULL));
	/* while ((s_dir = readdir(dir))) */
	/* { */
//	while (i < dirs->dirc)
//	{
//		F_(*flags & F_a, ft_print_f(F_1, dirs->path, dirs->darr[i]->path));
//		_F(dirs->darr[i]->path[0] != '.', ft_print_f(F_1, dirs->path, dirs->darr[i]->path));
//		i++;
//	}
	/* } */
	F_(*flags & F_M || *flags & F_R, ft_putendl(""));
	/* closedir(dir); */
	return (1);
}

/* int	ft_print_def(t_flags *flags, t_dirs *dirs) */
/* { */
/* 	DIR				*dir; */
/* 	struct dirent	*s_dir; */
/* 	dir = opendir(path); */
/* 	FT_(!dir, E_PRINTS); */
/* 	F_(*flags & F_M || *flags & F_R, ft_print_f(F_M, path, NULL)); */
/* 	while ((s_dir = readdir(dir))) */
/* 	{ */
/* 		F_(*flags & F_a, ft_print_f(F_1, , s_dir->d_name)); */
/* 		_F(s_dir->d_name[0] != '.', ft_print_f(F_1, path, s_dir->d_name)); */
/* 	} */
/* 	F_(*flags & F_M || *flags & F_R, ft_putendl("")); */
/* 	closedir(dir); */
/* 	return (1); */
/* } */

int	ft_print_rec(t_flags *flags, t_dirs *dirs)
{
	/* t_dirent	*s_dir; */
	/* DIR			*dir; */
	/* char		*fpath[4096]; */
	int 		i;

	i = 0;
	/* dir = opendir(path); */
	/* FT_(!dir, E_PRINTS); */
	F_(*flags & F_1, ft_print_def(flags, dirs));
	_F(*flags & F_l, ft_print_lst(flags, dirs));
	/* while ((s_dir = readdir(dir)) != NULL) */
	/* { */

	/* while (i < dirs->dirc) */
	/* { */
		/* F_(IS_DOT(dirs->darr[i]->name) || IS_DDOT(dirs->darr[i]->name), continue); */
		/* F_(ft_dir_check(dirs->darr[i]->path), ft_print_rec(flags, ft_dir_info(dirs->darr[i]->path))); */
		/* F_(dirs->darr[i], free((void *)dirs->darr[i++])); */
	/* } */
	/* } */
	/* closedir(dir); */
	return (1);
}

int	ft_print_lst(t_flags *flags, t_dirs *dirs)
{
	/* F_(*flags & F_M || *flags & F_R, ft_print_f(F_M, dirs->path, NULL)); */
	/* while ((s_dir = readdir(dir))) */
	/* { */
	/* while (i < dirs->dirc) */
	/* { */
	/* 	F_(*flags & F_a, ft_print_f(F_1, dirs->path, dirs->darr[i]->path)); */
	/* 	_F(dirs->darr[i]->path[0] != '.', ft_print_f(F_1, dirs->path, dirs->darr[i]->path)); */
	/* 	i++; */
	/* } */
	/* } */
	/* F_(*flags & F_M || *flags & F_R, ft_putendl("")); */
	/* closedir(dir); */
	if (dirs && flags)
		return (1);
	return (1);
}

int	ft_prints(t_flags *flags, t_dirs *dirs)
{
	FT_(*flags & F_1 && !(*flags & F_R), ft_print_def(flags, dirs));
	_FT(*flags & F_l && !(*flags & F_R), ft_print_lst(flags, dirs));
	_FT(*flags & F_R, ft_print_rec(flags, dirs));
	return (1);
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

/* {{{TITLE

 
int	ft_print_rec(char *path, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*s_dirent;
	char			*fpath[PATH_MAX];
	int 			i;
	i = 0;
	dir = opendir(path);
	FT_(!dir, E_PRINTS);
	if (*flags & F_1)
		ft_def_prints(path, flags);
	else if (*flags & F_l)
		ft_lst_prints(path, flags);
	while ((s_dirent = readdir(dir)) != NULL)
	{
		if (s_dirent->d_name[0] == '.' && s_dirent->d_name[1] == '\0')
			continue ;
		if (s_dirent->d_name[0] == '.' && s_dirent->d_name[1] == '.' && s_dirent->d_name[2] == '\0')
			continue ;
		if (ft_dir_path(path, s_dirent->d_name, fpath, i))
		{
			printf("FPATH: %s\n", fpath[i]);
			ft_putchar('\n');
			ft_print_name(fpath[i]);
			ft_print_rec(fpath[i], flags);
			free(fpath[i++]);
		}
		else
			continue ;
	}
	closedir(dir);
	return (1);
}



 }}} */

