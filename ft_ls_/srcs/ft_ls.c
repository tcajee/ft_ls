/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/23 13:52:26 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	main(int argc, char **argv)
{
	t_flags		flags;
	t_info		dirs[32768];
	int			i;
	int			j;

	i = 0;
	if (!(flags = 0))
		flags |= F_1;
	i = ft_flags(&flags, argv);
	if ((argc - i) > 1)
		flags |= F_M;
	
	/* ft_flag_print(&flags); */
	/* ft_putendl(""); */
	/* ft_putendl(""); */
	/* printf("%s\n", argv[i]); */

	j = i - 1;
	if (!argv[i])
		return (ft_dirs(&flags, dirs, "."));
	while (argv[++j])
	{
		if (!(ft_dir_check(argv[j])))
			ft_errors(E_PRINTS, argv[j]);
	}
	j = i - 1;
	while (argv[++j])
	{
		if (ft_dir_check(argv[j]))
			ft_dirs(&flags, dirs, argv[j]);
	}
	return (0);
}
