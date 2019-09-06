/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/09/06 18:54:05 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_flag_print(int *flags)
{
	size_t	i;

	i = 16;
	while (i--)
	{
		ft_putnbr(*flags >> i & 1);
		if (i % 8 == 0 && i != 16)
			ft_putchar(' ');
	}
}

int		ft_flag_check(int *flags, char flag)
{
	if (flag == '1')
		return (*flags = (*flags & ~F_L) | F_1);
	else if (flag == 'l')
		return (*flags = (*flags & ~F_1) | F_L);
	else if (flag == 'g')
		return (*flags = (*flags & ~F_1) | (F_L + F_G));
	else if (flag == 't')
		return ((*flags & F_U) ? *flags : (*flags = (*flags & ~F_0) | F_T));
	else if (flag == 'u')
		return (*flags = (*flags & ~(F_T)) | F_U);
	else if (flag == 'r')
		return (*flags = (*flags & ~F_0) | F_R);
	else if (flag == 'f')
		return (*flags = (*flags & ~(F_U + F_T)) | (F_F + F_A));
	else if (flag == 'a')
		return (*flags = (*flags & ~F_0) | F_A);
	else if (flag == 'R')
		return (*flags = (*flags & ~F_D) | F_RR);
	else if (flag == 'd')
		return (*flags = (*flags & ~F_RR) | F_D);
	else if (flag == 'G')
		return (*flags = (*flags & ~F_0) | F_GG);
	else if (flag == 'F')
		return (*flags = (*flags & ~F_0) | F_FF);
	exit(ft_error_flag(&flag));
}

int		ft_lflag_check(int *flags, char *opt)
{
	if (!ft_strcmp(opt, "long"))
		return (*flags = (*flags & ~F_L) | F_1);
	else if (!ft_strcmp(opt, "list"))
		return (*flags = (*flags & ~F_1) | F_L);
	else if (!ft_strcmp(opt, "no-owner"))
		return (*flags = (*flags & ~F_1) | (F_L + F_G));
	else if (!ft_strcmp(opt, "colour"))
		return (*flags = (*flags & ~F_0) | F_GG);
	else if (!ft_strcmp(opt, "all"))
		return (*flags = (*flags & ~F_0) | F_A);
	else if (!ft_strcmp(opt, "no-sort"))
		return (*flags = (*flags & ~(F_U + F_T)) | (F_F + F_A));
	else if (!ft_strcmp(opt, "mod-time"))
		return ((*flags & F_U) ? *flags : (*flags = (*flags & ~F_0) | F_T));
	else if (!ft_strcmp(opt, "acc-time"))
		return (*flags = (*flags & ~(F_T)) | F_U);
	else if (!ft_strcmp(opt, "reverse"))
		return (*flags = (*flags & ~F_0) | F_R);
	else if (!ft_strcmp(opt, "directory"))
		return (*flags = (*flags & ~F_RR) | F_D);
	else if (!ft_strcmp(opt, "recursive"))
		return (*flags = (*flags & ~F_D) | F_RR);
	else if (!ft_strcmp(opt, "verbose"))
		return (*flags = (*flags & ~F_0) | F_FF);
	exit(ft_error_flag(opt));
}

int		ft_flags(int *flags, char **argv)
{
	int i;
	int j;
ft_putendl("			FLAGS");
ft_putendl("-----------------------------------");
	i = 0;
	*flags = 0;
	F_SET(*flags, F_0, F_1);
	while (argv[++i])
	{
		j = 0;
		if (!argv[i][0] || argv[i][0] != '-')
			return (i);
		else if (!ft_strcmp(argv[i], "--"))
			return (i + 1);
		if ((argv[i][0] == '-' && argv[i][1] == '-') && argv[i][2])
			ft_lflag_check(flags, &argv[i][2]);
		else if (argv[i][0] == '-' && argv[i][1])
		{
			while (argv[i][++j])
				if (ft_flag_check(flags, argv[i][j]) < 0)
					return (-1);
		}
		else
			return (i);
	}

ft_putstr("[");
ft_putstr("]");
ft_putendl("			FLAGS END");
ft_putendl("			FLAGS END");
ft_flag_print(flags);
ft_putendl("			FLAGS END");
ft_putendl("-----------------------------------");
	return (i);
}
