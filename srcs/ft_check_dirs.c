/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:28:07 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/28 17:02:25 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/ft_ls.h"

int		ft_check_dirs(char *path)
{

	/* FT_(lstat(path, s_stat) == -1, -1); */
	/* if (s_stat->st_mode & S_IFDIR) */
	/* 	return (1); */
	/* if (s_stat->st_mode & S_IFREG) */
	/* 	return (0); */
	/* else */
	if (path)
		return (0);
	return (0);
}
