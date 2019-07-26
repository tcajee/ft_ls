/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:28:07 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 17:41:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/ft_ls.h"

int		ft_check_dirs(char *path, struct stat *s_stat)
{
	if (lstat(path, s_stat) != -1)
	{
		perror("lstat: ");
		return (0);
	}
	if (s_stat->st_mode & S_IFDIR)
		return (1);
	if (s_stat->st_mode & S_IFREG)
		return (0);
	else
		return (0);
}
