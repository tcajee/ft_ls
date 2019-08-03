/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/03 03:55:11 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_def_prints(char *path, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*s_dirent;

	dir = opendir(path);
	FT_(!dir, ft_error_prints(path));
	while ((s_dirent = readdir(dir)))
	{
		FT(*flags & F_M, printf("F_M\n"));
		/* FT((s_dirent->d_name) != NULL && s_dirent->d_name[0] != '.', */
			ft_putendl(s_dirent->d_name);
	}
	closedir(dir);
	return (1);
}

int	ft_prints(char *path, t_flags *flags)
{

	FT_(*flags & F_1, ft_def_prints(path, flags));
	/* _FT(*flags & F_l, ft_lst_prints(path, flags)); */
	_FT(*flags & F_R, ft_rec_prints(path, flags));
	return (1);
}

int	ft_rec_prints(char *path, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*s_dirent;
	char			*fpath;
	int 			i;
	int 			j;

	i = 0;
	s_dirent = NULL;
	dir = NULL;
	while ((s_dirent = readdir(dir)))
	{
		FT(*flags & F_M, ft_putendl(path));
		FT_(*flags & F_1, ft_def_prints(s_dirent->d_name, flags));
		if (*flags & F_R)
		{
			if ((ft_strjoin(ft_strjoin(path, "/"), s_dirent->d_name)))
			{
				if (path[s_dirent->d_namlen - 1] == '/')
					fpath = ft_strjoin(path, s_dirent->d_name); // newname struct
				else
					fpath = ft_strjoin(ft_strjoin(path, "/"), s_dirent->d_name); // struct
				++i;
 			}
			closedir(dir);
			j = 0;
	 	}
	}

	if (!s_dirent)
	{
		perror("S_DIRENT");
		printf("%d\n", errno);
	}
	while (j < i)
 	{
 		ft_putstr(fpath); // struct
 		ft_rec_prints(fpath, flags);              // struct
 		++j;
 	}
	return (1);
 }



