/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/21 12:24:21 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	main(int argc, char **argv)
{

	t_flags		flags;
	t_info		dirs[1024];
	int			i;
	int			j;

	i = 0;
	F(!(flags = 0), B_1(flags, F_1));
	F_((i = ft_flags(&flags, argv)) == E_FLAGS, errno);
	F(argc - i > 1, flags |= F_M);
	
	/* ft_flag_print(&flags); */
	/* ft_putendl(""); */
	/* ft_putendl("v"); */
	
	j = i - 1;
	F_(!argv[i], ft_dirs(&flags, dirs, "."));
	___(argv[++j], F(!(ft_dir_check(argv[j])), ft_errors(E_PRINTS, argv[j])));
	j = i - 1;
	___(argv[++j], F(ft_dir_check(argv[j]), ft_dirs(&flags, dirs, argv[j])));

	return (0);
}
