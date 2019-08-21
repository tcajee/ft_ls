/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 10:59:52 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_flag_print(t_flags *flags)
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

int		ft_flag_set(t_flags *flags, int flagc, ...)
{
	va_list	v_list;
	char	*mode;
	int		i;

	va_start(v_list, flagc);
	mode = va_arg(v_list, char *);
	i = -1;
	while (mode[++i] == '1')
		*flags |= va_arg(v_list, int);
	while (i++ < flagc - 1)
		*flags &= ~(va_arg(v_list, int));
	va_end(v_list);
	return (1);
}

int		ft_flag_check(t_flags *flags, char flag)
{
	if (flag == 'l')
		return (ft_flag_set(flags, 4, "110", F_l, F_t, F_1));
	else if (flag == '1')
		return (ft_flag_set(flags, 5, "10", F_1, F_l, F_t, F_g));
	else if (flag == 'g')
		return (ft_flag_set(flags, 5, "1110", F_g, F_l, F_t, F_1));
	else if (flag == 'G')
		return (ft_flag_set(flags, 2, "1", F_G));
	else if (flag == 'a')
		return (ft_flag_set(flags, 2, "1", F_a));
	else if (flag == 'f')
		return (ft_flag_set(flags, 3, "11", F_f, F_a));
	else if (flag == 't')
		return (ft_flag_set(flags, 2, "1", *flags));
	else if (flag == 'u')
		return (ft_flag_set(flags, 3, "10", F_u, F_t));
	else if (flag == 'r')
		return (ft_flag_set(flags, 2, "1", F_r));
	else if (flag == 'd')
		return (ft_flag_set(flags, 3, "10", F_d, F_R));
	else if (flag == 'R')
		return (ft_flag_set(flags, 3, "10", F_R, F_d));
	return (ft_errors(E_FLAGS, &flag));
}

int		ft_lflag_check(t_flags *flags, char *opt)
{
	if (!ft_strcmp(opt, "long"))
		return (ft_flag_set(flags, 4, "110", F_l, F_t, F_1));
	else if (!ft_strcmp(opt, "list"))
		return (ft_flag_set(flags, 5, "10", F_1, F_l, F_t, F_g));
	else if (!ft_strcmp(opt, "no-owner"))
		return (ft_flag_set(flags, 5, "1110", F_g, F_l, F_t, F_1));
	else if (!ft_strcmp(opt, "colour"))
		return (ft_flag_set(flags, 2, "1", F_G));
	else if (!ft_strcmp(opt, "all"))
		return (ft_flag_set(flags, 2, "1", F_a));
	else if (!ft_strcmp(opt, "no-sort"))
		return (ft_flag_set(flags, 3, "11", F_f, F_a));
	else if (!ft_strcmp(opt, "mod-time"))
		return (ft_flag_set(flags, 2, "1", *flags));
	else if (!ft_strcmp(opt, "acc-time"))
		return (ft_flag_set(flags, 3, "10", F_u, F_t));
	else if (!ft_strcmp(opt, "reverse"))
		return (ft_flag_set(flags, 2, "1", F_r));
	else if (!ft_strcmp(opt, "directory"))
		return (ft_flag_set(flags, 3, "10", F_d, F_R));
	else if (!ft_strcmp(opt, "recursive"))
		return (ft_flag_set(flags, 3, "10", F_R, F_d));
	return (ft_errors(E_PRINTS, opt));
}

int		ft_flags(t_flags *flags, char **argv)
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
				ft_flag_check(flags, argv[i][j]);
		}
		else
			return (i);
	}
	return (i);
}
