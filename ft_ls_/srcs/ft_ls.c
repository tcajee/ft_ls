/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/28 16:15:32 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_ls_rec(int *flags, char *path)
{
	t_dirent	*s_dir;
	DIR			*dir;
	char		*fpath;

ft_putendl("begin ls rec");
	if (!(dir = opendir(path)))
		return (0);
	while ((s_dir = readdir(dir)) != NULL)
	{
		if ((s_dir->d_name[0] == '.' && s_dir->d_name[1] == '\0') ||
		   ((s_dir->d_name[0] == '.' && s_dir->d_name[2] == '\0') &&
			s_dir->d_name[1] == '.'))
			continue;
		if (ft_dir_check(fpath = ft_dir_path(path, s_dir->d_name)) == 2)
			ft_dirs(flags, fpath);
		free(fpath);
	}
	closedir(dir);
ft_putendl("end ls rec");
	return (1);
}

int	main(int argc, char **argv)
{
	int			flags;
	int			i;
	int			j;

	if ((i = ft_flags(&flags, argv)) < 0)
		return (0);

ft_putendl("begin ls");
	if ((argc - i) > 1)
		flags |= F_M;
	if (!argv[i])
		return (ft_dirs(&flags,  "."));
	j = i - 1;
	while (argv[++j])
		if (ft_dir_check(argv[j]) == 0)
			ft_errors(&flags, E_DIRS, argv[j]);
			j = i - 1;
			while (argv[++j])
				if (ft_dir_check(argv[j]) == 1)
					ft_dirs(&flags, argv[j]);
			j = i - 1;
			while (argv[++j])
				if (ft_dir_check(argv[j]) == 2)
					ft_dirs(&flags, argv[j]);
ft_putendl("end ls");
	return (1);
}


	/* while (argv[++j]) */
	/* 	if (ft_dir_check(argv[j]) == 0) */
	/* 		ft_errors(&flags, E_DIRS, argv[j]); */
	/* j = i - 1; */
	/* while (argv[++j]) */
	/* 	if (ft_dir_check(argv[j]) == 1) */
	/* 		ft_dirs(&flags,  argv[j]); */
	/* j = i - 1; */
	/* while (argv[++j]) */
	/* 	if (ft_dir_check(argv[j]) == 2) */
	/* 		ft_dirs(&flags, argv[j]); */


