/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:23:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 17:53:23 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_dirs(char *arg)
{
	struct stat	s_stat;

	if (ft_check_dirs(arg, &s_stat))
		ft_def_prints(arg);
	else
	{
		return(ft_errors(99));
		perror("ft_dirs");
	}
	return (0);
}
