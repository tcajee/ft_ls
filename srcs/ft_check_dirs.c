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

#include "../libft/incs/libft.h"

int		ft_check_dirs(char *path)
{
	struct stat *s_stat;

	s_stat = NULL;
	FT_(stat(path, s_stat) != -1, 0);
	FT_(s_stat->st_mode & S_IFDIR, 1);
	return (1);
}
