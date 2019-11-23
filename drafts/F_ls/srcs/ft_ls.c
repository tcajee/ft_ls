/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/23 14:17:17 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	main(int argc, char **argv)
{
	int		*flags;
	t_info		dirs[1024];
	int			i;
	int			j;

	i = 0;
	F(!(flags = 0), F_SET(*flags, F_0, F_1));
	F_((i = ft_flags(flags, argv)) == -1, errno);
	F(argc - i > 1, F_SET(*flags, F_0, F_M));
	
	ft_flag_print(flags);
	ft_putendl("");
	ft_putendl("v");
	
	j = i - 1;
	F_(!argv[i], ft_dirs(flags, dirs, "."));
	___(argv[++j], F(!(ft_dir_check(argv[j])), ft_errors(-1, argv[j])));
	j = i - 1;
	___(argv[++j], F(ft_dir_check(argv[j]), ft_dirs(flags, dirs, argv[j])));

	return (0);
}
