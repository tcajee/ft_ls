/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_dirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:28:33 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 17:54:04 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_open_dirs(char *path)
{
	DIR				*dir;
	struct dirent	*s_dirent;

	dir = opendir(path);
	while ((s_dirent = readdir(dir)))
		if ((s_dirent->d_name) != NULL && s_dirent->d_name[0] != '.')
			ft_putendl(s_dirent->d_name);

	closedir(dir);
}

/* if (ft_check_dirs(s_dirent->d_name)) */
/* { */
/* 	if (!(file = malloc(sizeof(t_files)))) */
/* 		perror("Malloc error: "); */
/* 	file->dir = s_dirent->d_name; */
/* 	ft_putendl(file->dir); */
/* } */

