/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/06 13:33:58 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_ls_file(int *flags, char **argv)
{
	t_dirs	*dirs;
	t_info	*list;

	F_SET(*flags, F_0, F_REG);
	dirs = ft_dir_new(*(argv + 1));
	list = dirs->list;
	while (*++argv)
	{
		if (ft_ls_check(*argv) == 1 && ++dirs->size)
		{
			if (!list)
				list = ft_dir_add(dirs->last);
			dirs->last = list;
			list->name = ft_strdup(*argv);
			lstat(list->name, &list->s_stat);
			ft_dir_form(flags, dirs);
			if (!(*flags & F_F))
				ft_sorts(flags, dirs);
			list = !(*flags & F_F) ? dirs->last->next : list->next;
		}
	}
	ft_prints(flags, dirs);
	ft_sort_clean(dirs);
	F_SET(*flags, F_REG, F_0);
}

int		ft_ls_check(char *path)
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

char	*ft_ls_path(char *path, char *d_name)
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


int		ft_ls_rec(int *flags, t_dirs *dirs)
{
	t_info		*list;

	list = (*flags & F_R) ? dirs->last : dirs->list;
	while (list)
	{
		if ((list->name[0] == '.' && list->name[1] == '\0') ||
			((list->name[0] == '.' && list->name[2] == '\0') &&
			list->name[1] == '.'))
		{
			list = (*flags & F_R) ? list->prev : list->next;
			continue;
		}
		else if (ft_ls_check(list->path) == 2)
			ft_dirs(flags, list->path);
		list = (*flags & F_R) ? list->prev : list->next;
	}
	return (1);
}


/* int		ft_ls_rec(int *flags, char *path) */
/* { */
/* 	t_dirent	*s_dir; */
/* 	DIR			*dir; */
/* 	char		*fpath; */
/* 	if (!(dir = opendir(path))) */
/* 		return (0); */
/* 	while ((s_dir = readdir(dir)) != NULL) */
/* 	{ */
/* 		if ((s_dir->d_name[0] == '.' && s_dir->d_name[1] == '\0') || */
/* 			((s_dir->d_name[0] == '.' && s_dir->d_name[2] == '\0') && */
/* 			s_dir->d_name[1] == '.')) */
/* 			continue; */
/* 		if (ft_ls_check(fpath = ft_ls_path(path, s_dir->d_name)) == 2) */
/* 			ft_dirs(flags, fpath); */
/* 		free(fpath); */
/* 	} */
/* 	closedir(dir); */
/* 	return (1); */
/* } */

int		main(int argc, char **argv)
{
	int			flags;
	int			i;
	int			j;

	i = 0;
	i = ft_flags(&flags, argv);
	if ((argc - i) > 1)
		flags |= F_M;
	if (!argv[i])
		return (ft_dirs(&flags, "."));
	j = i - 1;
	ft_errors(&flags, argv + j);
	ft_ls_file(&flags, argv + j);
	while (argv[++j])
		if (ft_ls_check(argv[j]) == 2)
			ft_dirs(&flags, argv[j]);
	return (1);
}
