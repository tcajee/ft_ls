/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/03 14:03:45 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_ls_file(int *flags, char **argv)
{
	int		i;
	t_dirs	*dirs;
	t_info	*list;

	i = 0;
	if (!(dirs = ft_dir_new(argv[i])))
		return ;
	list = dirs->list;
	while (argv[++i])
	{
		if (ft_ls_check(argv[i]) == 1)
		{
			F_SET(*flags, F_0, F_REG);
			if (!list)
				list = ft_dir_add(dirs->last);
			dirs->last = list;
			dirs->size = i;
			list->name = ft_strdup(argv[i]);
			lstat(list->name, &list->s_stat);
			ft_dir_form(flags, dirs);
			if (!(*flags & F_f))
				ft_sorts(flags, dirs);
			list = !(*flags & F_f) ? dirs->last->next : list->next;
		}
		ft_prints(flags, dirs);
	}
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

int		ft_ls_rec(int *flags, char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	char		*fpath;

	if (!(dir = opendir(path)))
		return (0);
	while ((s_dir = readdir(dir)) != NULL)
	{
		if ((s_dir->d_name[0] == '.' && s_dir->d_name[1] == '\0') ||
		   ((s_dir->d_name[0] == '.' && s_dir->d_name[2] == '\0') &&
			s_dir->d_name[1] == '.'))
			continue;
		if (ft_ls_check(fpath = ft_ls_path(path, s_dir->d_name)) == 2)
			ft_dirs(flags, fpath);
		free(fpath);
	}
	closedir(dir);
	return (1);
}

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
	while (argv[++j])
		if (ft_ls_check(argv[j]) == 0)
			ft_errors(&flags, E_DIRS, argv[j]);
	j = i - 1;
	ft_ls_file(&flags, argv + j);



	j = i - 1;
	while (argv[++j])
		if (ft_ls_check(argv[j]) == 2)
			ft_dirs(&flags, argv[j]);
	sleep(20);
	return (1);
}
