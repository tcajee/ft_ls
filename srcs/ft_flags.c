/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/30 15:39:26 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_error_flags(char flag)
{
	ft_putstr_fd("./ft_ls: illegal option -- ", 2);
	ft_putchar_fd(flag, 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("usage: ./ft_ls [-lRartufgd1] [file ...]", 2);
	return (E_FLAGS);
}

int	ft_set_flags(char *arg, t_flags *flags)
{
	int i;

	i = 0;
	while (arg[++i])
	{
		if (arg[i] == 'l' || arg[i] == 'g')
		{
			FT(B_IS(*flags, F_1), B_0(*flags, F_1));
			B_1(*flags, F_l);
		}
		else if (arg[i] == '1')
		{
			FT(B_IS(*flags, F_l), B_0(*flags, F_l));
			B_1(*flags, F_1);
		}
		else if (arg[i] == 'R')
			B_1(*flags, F_R);
		else if (arg[i] == 'a')
			B_1(*flags, F_a);
		else if (arg[i] == 'r')
			B_1(*flags, F_r);
		else if (arg[i] == 't')
			B_1(*flags, F_t);
		else if (arg[i] == 'u')
			B_1(*flags, F_u);
		else if (arg[i] == 'f')
			B_1(*flags, F_f);
		else if (arg[i] == 'd')
			B_1(*flags, F_d);
		else if (arg[i] == 'G')
			B_1(*flags, F_G);
		else if (arg[i] == 'g')
			B_1(*flags, F_g);
		else
			return (ft_error_flags(arg[i]));
	}
	ft_print_flags(flags);
	ft_putchar('\n');
	return (1);
}

int	ft_flags(char **argv, t_flags *flags)
{
	int i;

	i = 0;
	FT(!flags, ft_init_flags(flags))
	while (argv[++i])
	{
		FT_((argv[i][0] != '-'), i);
		FT_(!ft_strcmp(argv[i], "--"), i);
		FT_((argv[i][0] == '-' && argv[i][1] == '-') && argv[i][2],
			(*flags = ft_error_flags(argv[i][2])));
		FT(argv[i][0] == '-' && argv[i][1], ft_set_flags(argv[i], flags));
	}
	return (i);
}
