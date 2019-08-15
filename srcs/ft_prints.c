/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/15 08:55:50 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

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

void		ft_print_time(t_stat s_stat, t_flags *flags)
{
	F_(*flags & F_u, print_time_str(s_stat.st_atime));
	_F(*flags & F_t, print_time_str(s_stat.st_mtime));
}

void	ft_print_perm(t_stat *s_stat)
{
	char	*permissions;

	
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');


	permissions = (char *)malloc(sizeof(char) * 11 + 1);
	ft_memset(permissions, '-', 11);
	F_((s_stat->st_mode & S_IFMT) == S_IFDIR, permissions[0] = 'd');
	_F((s_stat->st_mode & S_IFMT) == S_IFREG, permissions[0] = '-');
	_F((s_stat->st_mode & S_IFMT) == S_IFCHR, permissions[0] = 'c');
	_F((s_stat->st_mode & S_IFMT) == S_IFBLK, permissions[0] = 'b');
	_F(s_stat->st_mode & S_IFMT) == S_IFLNK, permissions[0] = 'l'); // 16749
	F_(s_stat->st_mode & S_IRUSR, permissions[1] = 'r');
	F_(s_stat->st_mode & S_IWUSR, permissions[2] = 'w');
	F_(s_stat->st_mode & S_IXUSR, permissions[3] = 'x');
	F_(s_stat->st_mode & S_IRGRP, permissions[4] = 'r');
	F_(s_stat->st_mode & S_IWGRP, permissions[5] = 'w');
	F_(s_stat->st_mode & S_IXGRP, permissions[6] = 'x');
	F_(s_stat->st_mode & S_IROTH, permissions[7] = 'r');
	F_(s_stat->st_mode & S_IWOTH, permissions[8] = 'w');
	F_(s_stat->st_mode & S_IXOTH, permissions[9] = 'x');
	permissions[10] = ' ';
	permissions[11] = '\0';
	ft_print_f("%t", permissions);
}

int	ft_print_def(t_flags *flags, t_info dir)
{
	F_(*flags & F_a, ft_print_f("%", dir.name));
	_F(dir.name[0] != '.', ft_print_f("%", dir.name));
	F_(ft_dir_check(dir.path), ft_print_f("/n"));
	_(ft_print_f("n"));
	return (1);
}

int	ft_print_lst(t_flags *flags, t_info dir)
{
	t_passwd	*s_pwd;
	t_group		*s_grp;

	ft_print_perm(&dir.s_stat);

	ft_print_f("%t", "XX"); // dir.s_stat.st_nlink);

	s_pwd = getpwuid(dir.s_stat.st_uid);
	ft_print_f("%t", s_pwd->pw_name);
	s_grp = getgrgid(dir.s_stat.st_gid);
	ft_print_f("%t", s_grp->gr_name);

	ft_print_f("%t", "XX"); // dir.s_stat.st_size);

	ft_print_f("%t", "XXX XX XX:XX"); // ft_print_time(dir.s_stat, flags);

	ft_print_f(" ");
	F_(*flags & F_a, ft_print_f("%", dir.name));
	_F(dir.name[0] != '.', ft_print_f("%", dir.name));
	F_(ft_dir_check(dir.path), ft_print_f("/n"));
	_(ft_print_f("n"));
	return (1);
}

int	ft_prints(t_flags *flags, t_info dirs[])
{
	int i;

	i = -1;
	F_(*flags & F_M || *flags & F_R, ft_print_f("%:n", dirs[0].root));
	F_(*flags & F_l, ft_print_f("%n", ft_itoa(dirs[0].total)));
	while (dirs[++i].name)
	{
		F_(*flags & F_1, ft_print_def(flags, dirs[i]));
		_F(*flags & F_l, ft_print_lst(flags, dirs[i]));
	}
	F_(*flags & F_M || *flags & F_R, ft_print_f("n"));
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

/* {{{TITLE
 
 	
int	ft_print_def(t_flags *flags, t_dirs *dirs)
{
	DIR				*dir;
	struct dirent	*s_dir;
	dir = opendir(path);
	FT_(!dir, E_PRINTS);
	F_(*flags & F_M || *flags & F_R, ft_print_f(F_M, path, NULL));
	while ((s_dir = readdir(dir)))
	{
		F_(*flags & F_a, ft_print_f(F_1, , s_dir->d_name));
		_F(s_dir->d_name[0] != '.', ft_print_f(F_1, path, s_dir->d_name));
	}
	F_(*flags & F_M || *flags & F_R, ft_putendl(""));
	closedir(dir);
	return (1);
}

 
 * }}} */
