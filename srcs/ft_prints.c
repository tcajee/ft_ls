/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/06 18:16:46 by tcajee           ###   ########.fr       */
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
		if (ft_dir_path(path, d_name, &fpath))
		{
			ft_putstr(d_name);
			ft_putendl("/");
			free(fpath);
		}
		else
			ft_putendl(d_name);
	}
}

int	ft_print_def(char *path, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*s_dir;

	dir = opendir(path);
	FT_(!dir, E_PRINTS);
	F_(*flags & F_M || *flags & F_R, ft_print_f(F_M, path, NULL));
	while ((s_dir = readdir(dir)))
	{
		F_(*flags & F_a, ft_print_f(F_1, path, s_dir->d_name));
		_F(s_dir->d_name[0] != '.', ft_print_f(F_1, path, s_dir->d_name));
	}
	F_(*flags & F_M || *flags & F_R, ft_putendl(""));
	closedir(dir);
	return (1);
}

int	ft_print_rec(char *path, t_flags *flags)
{
	t_dirent	*s_dir;
	DIR			*dir;
	char		*fpath[1024];
	int 		i;

	i = 0;
	dir = opendir(path);
	FT_(!dir, E_PRINTS);
	F_(*flags & F_1, ft_print_def(path, flags));
	_F(*flags & F_l, ft_print_lst(path, flags));
	while ((s_dir = readdir(dir)) != NULL)
	{
		F_(IS_DOT(s_dir->d_name) || IS_DDOT(s_dir->d_name), continue);
		if (ft_dir_path(path, s_dir->d_name, &fpath[i]))
		{
			/* ft_putchar('\n'); */
			/* ft_print_f(F_M, fpath[i]); */
			ft_print_rec(fpath[i], flags);
			free(fpath[i++]);
		 }
	}
	closedir(dir);
	return (1);
}

int	ft_print_lst(char *path, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*s_dir;

	dir = opendir(path);
	FT_(!dir, E_PRINTS);
	F_(*flags & F_M || *flags & F_R, ft_print_f(F_M, path, NULL));
	while ((s_dir = readdir(dir)))
	{
		F_(*flags & F_a, ft_print_f(F_1, path, s_dir->d_name));
		_F(s_dir->d_name[0] != '.', ft_print_f(F_1, path, s_dir->d_name));
	}
	F_(*flags & F_M || *flags & F_R, ft_putendl(""));
	closedir(dir);
	return (1);
}

int	ft_prints(char *path, t_flags *flags)
{
	FT_(*flags & F_1 && !(*flags & F_R), ft_print_def(path, flags));
	_FT(*flags & F_l && !(*flags & F_R), ft_print_lst(path, flags));
	_FT(*flags & F_R, ft_print_rec(path, flags));
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

