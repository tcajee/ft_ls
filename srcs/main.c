/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/06 18:10:53 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	main(int argc, char **argv)
{
	t_flags	flags;
	int		i;

	i = 0;
	F_(!(flags = 0), B_1(flags, F_1));
	ft_flag_print(&flags);
	ft_putchar('\n');
	FT_((i = ft_flags(argv, &flags)) == E_FLAGS, errno);
	F_(argc - i > 1, flags |= F_M);
	return (ft_dirs(argv + i, &flags));
}
