/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/02 14:50:05 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

/* void ft_error_print() */ 

void	ft_def_prints(char *path)
{
	DIR				*dir;
	struct dirent	*s_dirent;

	dir = opendir(path);
	FT(!(dir), ft_error_dirs(path));

	while ((s_dirent = readdir(dir)))
	{
		if ((s_dirent->d_name) != NULL && s_dirent->d_name[0] != '.')
			ft_putendl(s_dirent->d_name);
	}
	closedir(dir);
}


/* void	ft_prints(char *path, t_flags *flags) */
/* { */
/* } */
