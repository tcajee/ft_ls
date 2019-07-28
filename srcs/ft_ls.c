/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/28 17:03:05 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_ls(char **dirs, t_flags *flags)
{
	int i;

	i = 0;
	/* printf("PATH_MAX: %d\n", PATH_MAX); */
	if(!dirs && *flags == F_1)
		ft_def_prints(".");
	else if (dirs)
	{
		while (dirs[i])
			ft_def_prints(dirs[i++]);
	}
	// handle memory
	// handle sorting
	// handle printing
	// handle errors
	return (0);
}
