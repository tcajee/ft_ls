/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/26 16:30:11 by tcajee           ###   ########.fr       */
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
		return (*flags = (*flags & ~F_l) | F_1);
	else if (flag == 'l')
		return (*flags = (*flags & ~F_1) | F_l);
	else if (flag == 'g')
		return (*flags = (*flags & ~F_1) | (F_l + F_g));
	else if (flag == 't')
		return ((*flags & F_u) ? *flags : (*flags = (*flags & ~F_0) | F_t));
	else if (flag == 'u')
		return (*flags = (*flags & ~(F_t)) | F_u);
	else if (flag == 'r')
		return (*flags = (*flags & ~F_0) | F_r);
	else if (flag == 'f')
		return (*flags = (*flags & ~(F_u + F_t)) | (F_f + F_a));
	else if (flag == 'a')
		return (*flags = (*flags & ~F_0) | F_a);
	else if (flag == 'R')
		return (*flags = (*flags & ~F_d) | F_R);
	else if (flag == 'd')
		return (*flags = (*flags & ~F_R) | F_d);
	else if (flag == 'G')
		return (*flags = (*flags & ~F_0) | F_G);
	else if (flag == 'F')
		return (*flags = (*flags & ~F_0) | F_F);
	exit (ft_errors(E_FLAGS, &flag));
}

int		ft_lflag_check(int *flags, char *opt)
{
	if (!ft_strcmp(opt, "long"))
		return (*flags = (*flags & ~F_l) | F_1);
	else if (!ft_strcmp(opt, "list"))
		return (*flags = (*flags & ~F_1) | F_l);
	else if (!ft_strcmp(opt, "no-owner"))
		return (*flags = (*flags & ~F_1) | (F_l + F_g));
	else if (!ft_strcmp(opt, "colour"))
		return (*flags = (*flags & ~F_0) | F_G);
	else if (!ft_strcmp(opt, "all"))
		return (*flags = (*flags & ~F_0) | F_a);
	else if (!ft_strcmp(opt, "no-sort"))
		return (*flags = (*flags & ~(F_u + F_t)) | (F_f + F_a));
	else if (!ft_strcmp(opt, "mod-time"))
		return ((*flags & F_u) ? *flags : (*flags = (*flags & ~F_0) | F_t));
	else if (!ft_strcmp(opt, "acc-time"))
		return (*flags = (*flags & ~(F_t)) | F_u);
	else if (!ft_strcmp(opt, "reverse"))
		return (*flags = (*flags & ~F_0) | F_r);
	else if (!ft_strcmp(opt, "directory"))
		return (*flags = (*flags & ~F_R) | F_d);
	else if (!ft_strcmp(opt, "recursive"))
		return (*flags = (*flags & ~F_d) | F_R);
	else if (!ft_strcmp(opt, "verbose"))
		return (*flags = (*flags & ~F_0) | F_F);
	exit (ft_errors(E_FLAGS, opt));
}

int		ft_flags(int *flags, char **argv)
{
	int i;
	int j;

	i = 0;
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
	return (i);
}
