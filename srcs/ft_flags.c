/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/13 10:58:24 by tcajee           ###   ########.fr       */
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
		F_(i % 8 == 0 && i != 16, ft_putchar(' '));
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
		B_1(*flags, va_arg(v_list, int));
	while (i++ < flagc - 1)
		B_0(*flags, va_arg(v_list, int));
	va_end(v_list);
	return (1);
}

int		ft_flag_check(char flag, t_flags *flags)
{
	FT_(flag == 'l', ft_flag_set(flags, 4, "110", F_l, F_t, F_1));
	_FT(flag == '1', ft_flag_set(flags, 5, "10", F_1, F_l, F_t, F_g));
	_FT(flag == 'g', ft_flag_set(flags, 5, "1110", F_g, F_l, F_t, F_1));
	_FT(flag == 'G', ft_flag_set(flags, 2, "1", F_G));
	_FT(flag == 'a', ft_flag_set(flags, 2, "1", F_a));
	_FT(flag == 'f', ft_flag_set(flags, 3, "11", F_f, F_a));
	_FT(flag == 't', ft_flag_set(flags, 2, "1", *flags));
	_FT(flag == 'u', ft_flag_set(flags, 3, "10", F_u, F_t));
	_FT(flag == 'r', ft_flag_set(flags, 2, "1", F_r));
	_FT(flag == 'd', ft_flag_set(flags, 3, "10", F_d, F_R));
	_FT(flag == 'R', ft_flag_set(flags, 3, "110", F_R, F_d));
	return (ft_errors(E_FLAGS, &flag));
}

int		ft_flag_long(char *opt, t_flags *flags)
{
	FT_(!ft_strcmp(opt, "long"), ft_flag_set(flags, 4, "110", F_l, F_t, F_1));
	_FT(!ft_strcmp(opt, "list"), ft_flag_set(flags, 5, "10", F_1, F_l, F_t, F_g));
	_FT(!ft_strcmp(opt, "no-owner"), ft_flag_set(flags, 5, "1110", F_g, F_l, F_t, F_1));
	_FT(!ft_strcmp(opt, "colour"), ft_flag_set(flags, 2, "1", F_G));
	_FT(!ft_strcmp(opt, "all"), ft_flag_set(flags, 2, "1", F_a));
	_FT(!ft_strcmp(opt, "no-sort"), ft_flag_set(flags, 3, "11", F_f, F_a));
	_FT(!ft_strcmp(opt, "mod-time"), ft_flag_set(flags, 2, "1", *flags));
	_FT(!ft_strcmp(opt, "acc-time"), ft_flag_set(flags, 3, "10", F_u, F_t));
	_FT(!ft_strcmp(opt, "reverse"), ft_flag_set(flags, 2, "1", F_r));
	_FT(!ft_strcmp(opt, "directory"), ft_flag_set(flags, 3, "10", F_d, F_R));
	_FT(!ft_strcmp(opt, "recursive"), ft_flag_set(flags, 3, "110", F_R, F_d));
	return (ft_errors(E_PRINTS, opt));
}

int		ft_flags(char **argv, t_flags *flags)
{
	int i;
	int j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		FT_((!argv[i][0] || argv[i][0] != '-'), i);
		_FT(!ft_strcmp(argv[i], "--"), i + 1);
		if ((argv[i][0] == '-' && argv[i][1] == '-') && argv[i][2]) 
			ft_flag_long(&argv[i][2], flags);
		else if (argv[i][0] == '-' && argv[i][1])
			while (argv[i][++j])
				ft_flag_check(argv[i][j], flags);
		else
			return (i);
	}
	/* printf("%s\n", &argv[i][2]); */
	/* (*flags = ft_errors(E_FLAGS, &argv[i][2]))); */
	ft_flag_print(flags);
	ft_putchar('\n');
	return (i);
}
