/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/03 08:10:57 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

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

int		ft_ls_isdir(char *name)
{
	struct stat s;

	printf("%s\n", name);
	if (lstat(name, &s) < 0)
		perror("Stat: ");
	if (S_ISREG(s.st_mode))
		return (0);
	else
		return (S_ISDIR(s.st_mode));
}


void	ft_name_prints(char *path)
{
	/* ft_putstr("\n"); */
	ft_putstr(path);
	ft_putstr(":\n");
}

int	ft_lst_prints(char *path, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*s_dirent;
	dir = opendir(path);
	FT_(!dir, E_PRINTS);
	FT(*flags & F_M, ft_name_prints(path));
	while ((s_dirent = readdir(dir)))
	{
		if (*flags & F_a)
			ft_putendl(s_dirent->d_name);
		else
			FT(s_dirent->d_name[0] != '.',ft_putendl(s_dirent->d_name));
	}
	FT(*flags & F_M, ft_putendl(""));
	closedir(dir);
	return (1);
}

int	ft_def_prints(char *path, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*s_dirent;

	dir = opendir(path);
	FT_(!dir, E_PRINTS);
	FT(*flags & F_M, ft_name_prints(path));
	while ((s_dirent = readdir(dir)))
	{
		if (*flags & F_a)
			ft_putendl(s_dirent->d_name);
		else
			FT(s_dirent->d_name[0] != '.',ft_putendl(s_dirent->d_name));
	}
	FT(*flags & F_M, ft_putendl(""));
	closedir(dir);
	return (1);
}

int	ft_prints(char *path, t_flags *flags)
{
	FT_(*flags & F_1 && !(*flags & F_R), ft_def_prints(path, flags));
	_FT(*flags & F_l && !(*flags & F_R), ft_lst_prints(path, flags));
	_FT(*flags & F_R, ft_rec_prints(path, flags));
	return (1);
}

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
		/* printf("path: %s\n", path); */
		/* printf("s_dir: %s\n", s_dirent->d_name); */
		/* printf("fpath: %s\n", fpath[i] =get_path(path, s_dirent->d_name)); */
		if (*flags & F_1)
			ft_def_prints(s_dirent->d_name, flags);
		else if (*flags & F_l)
			ft_lst_prints(s_dirent->d_name, flags);
		if (ft_ls_isdir(fpath[i] = get_path(path, s_dirent->d_name)))
		{
		
			/* if (path[ft_strlen(path) - 1] == '/') */
			/* 	fpath[i] = ft_strjoin(path, s_dirent->d_name); */
			/* else */
			/* 	fpath[i] = ft_strjoin(ft_strjoin(path, "/"), s_dirent->d_name); */

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



