/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:56:40 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/26 17:10:41 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/ft_ls.h"

int		ft_isdir(char *path)
{
	struct stat s_stat;

	if (lstat(path, &s_stat) != -1)
	{
		perror("lstat: ");
		return (0);
	}
	if (s_stat.st_mode & S_IFDIR)
		return (1);
	if (s_stat.st_mode & S_IFREG)
		return (0);
	else
		return (0);
}
