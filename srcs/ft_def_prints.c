/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def_prints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:50:08 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/29 16:13:56 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_def_prints(char *path)
{
	DIR				*dir;
	struct dirent	*s_dirent;

	dir = opendir(path);
	FT_(!(dir), (void)printf("BAD DIR\n"));

	while ((s_dirent = readdir(dir)))
	{
		if ((s_dirent->d_name) != NULL && s_dirent->d_name[0] != '.')
			ft_putendl(s_dirent->d_name);
	}
	closedir(dir);
}
