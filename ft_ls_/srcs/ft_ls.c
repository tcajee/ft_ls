/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/05 15:27:17 by sminnaar         ###   ########.fr       */
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
	/* char		*fpath; */
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
		if (ft_ls_check(list->path) == 2)
			ft_dirs(flags, dirs, list->path);
		list = (*flags & F_R) ? list->prev : list->next;
	}
	return (1);
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

int		main(int argc, char **argv)
{
	int			flags;
	t_dirs		*dirs;
	int			i;

	i = 0;
	if ((argc - (i = ft_flags(&flags, argv))) > 1)
		flags |= F_M;
	ft_errors(&flags, argv + i - 1);
	ft_ls_file(&flags, argv + i - 1);
	while (argv[i - 1])
	{
		if (ft_ls_check(argv[i]) == 2)
		{
			if (!(dirs = ft_dir_new(argv[i])))
				return (0);
			if (!(ft_dirs(&flags, dirs, argv[i])))
				return (0);
			if (flags & F_RR)
				ft_ls_rec(&flags, dirs);
			ft_sort_clean(dirs);
		}
		i++;
	}
	return (1);
}
