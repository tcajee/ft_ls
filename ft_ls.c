/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/06 13:21:47 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_ls(char **argv, t_flags *flags)
{
	t_stat s_stat;
	int i;
	int k;

	i = -1;
	k = -1;
	FT_(!argv[0], ft_prints(".", flags));
	while (argv[++i])
		FT(lstat(argv[i], &s_stat) < 0, ft_errors(E_PRINTS, argv[i]));
	while (argv[++k])
		FT(ft_dir_check(argv[k]), ft_prints(argv[k], flags));
	return (i);
}
