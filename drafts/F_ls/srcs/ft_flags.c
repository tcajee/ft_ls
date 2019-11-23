/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/23 14:18:20 by tcajee           ###   ########.fr       */
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
		F(i % 8 == 0 && i != 16, ft_putchar(' '));
	}
}

/* int		ft_flag_set(int *flags, int flagc, ...) */
/* { */
/* 	va_list	v_list; */
/* 	char	*mode; */
/* 	int		i; */

	/* va_start(v_list, flagc); */
	/* mode = va_arg(v_list, char *); */
	/* i = -1; */
	/* ___(mode[++i] == '1', B_1(*flags, va_arg(v_list, int))); */
	/* ___(i++ < flagc - 1, B_0(*flags, va_arg(v_list, int))); */
	/* va_end(v_list); */
	/* return (1); */
/* } */

int		ft_flag_check(int *flags, char flag)
{

	/*
	 * &= ~ OFF =| ON
	 */
	

	/* x = x & ~y ; y == off*/ 
	/* x = x | z ; z == on */
	/* x & ~y | z; */
	/* flags |= (off & ~off); */
	/* *flags = *flags & ~F_1 | F_l; */
	
	/* *flags = *flags | (F_1 & ~F_l); */
	/* 00000000 00000001 */
	/* 00000000 00000000 */
	/* ( 00010010 01001011 */
	/* = 00010010 01001011 | */
	/*   00000000 00000001) */
	/* | (00000000 00000001 */
	/* & 11111111 11111101) */
	/* 00000000 00000010 */
	/* 00010010 01001001 */
	/* 00000000 00000000 */

	/* 00000000 00000001	= F_1	= 1, */
	/* 00000000 00000010	= F_l	= 2, */
	/* 00000000 00000100	= F_g	= 4, */
	/* 00000000 00001000	= F_t	= 8, */
	/* 00000000 00010000	= F_u	= 16, */
	/* 00000000 00100000	= F_r	= 32, */
	/* 00000000 01000000	= F_f	= 64, */
	/* 00000000 10000000	= F_a	= 128, */
	/* 00000001 00000000	= F_G	= 2048, */
	/* 00000010 00000000	= F_d	= 4096, */
	/* 00000100 00000000	= F_R	= 8192, */
	/* 00001000 00000000	= F_P	= 16384, */
	/* 00010000 00000000	= F_M	= 32768, */
	/* 00100000 00000000	= F_0	= 32768, */
	/* 01000000 00000000	= F_0	= 32768, */
	/* 10000000 00000000	= F_0	= 0, */

	/* _F_(flag == '1', ft_flag_set(flags, 1, "10", F_1, F_l, F_t, F_g)); */
	/* F_(flag == 'l', ft_flag_set(flags,  F_l, F_1)); */
	/* _F_(flag == 'g', ft_flag_set(flags, 5, "1110", F_g, F_l, F_t, F_1)); */
	/* _F_(flag == 'G', ft_flag_set(flags, 2, "1", F_G)); */
	/* _F_(flag == 'a', ft_flag_set(flags, 2, "1", F_a)); */
	/* _F_(flag == 'f', ft_flag_set(flags, 3, "11", F_f, F_a)); */
	/* _F_(flag == 't', ft_flag_set(flags, 2, "1", *flags)); */
	/* _F_(flag == 'u', ft_flag_set(flags, 3, "10", F_u, F_t)); */
	/* _F_(flag == 'r', ft_flag_set(flags, 2, "1", F_r)); */
	/* _F_(flag == 'd', ft_flag_set(flags, 3, "10", F_d, F_R)); */
	/* _F_(flag == 'R', ft_flag_set(flags, 3, "10", F_R, F_d)); */
	/* return (ft_errors(E_FLAGS, &flag)); */

	F(flag == '1', *flags = (*flags & ~(F_l + F_g)) | F_1);
	_F(flag == 'l', *flags = (*flags & ~F_1) | F_l);
	_F(flag == 'g', *flags = (*flags & ~F_1) | (F_g + F_l));
	_F(flag == 't', *flags = (*flags & ~F_0) | F_t);

	/* _F_(flag == 'u', ft_flag_set(flags, 3, "10", F_u, F_t)); */
	/* _F_(flag == 'r', ft_flag_set(flags, 2, "1", F_r)); */
	/* _F_(flag == 'f', ft_flag_set(flags, 3, "11", F_f, F_a)); */
	/* _F_(flag == 'a', ft_flag_set(flags, 2, "1", F_a)); */
	/* _F_(flag == 'G', ft_flag_set(flags, 2, "1", F_G)); */
	/* _F_(flag == 'd', ft_flag_set(flags, 3, "10", F_d, F_R)); */
	/* _F_(flag == 'R', ft_flag_set(flags, 3, "10", F_R, F_d)); */

	return (ft_errors(-1, &flag));
}

/* int		ft_lflag_check(int *flags, char *opt) */
/* { */
/* 	F_(!ft_strcmp(opt, "long"), ft_flag_set(flags, 4, "110", F_l, F_t, F_1)); */
/* 	_F_(!ft_strcmp(opt, "list"), ft_flag_set(flags, 5, "10", F_1, F_l, F_t, F_g)); */
/* 	_F_(!ft_strcmp(opt, "no-owner"), ft_flag_set(flags, 5, "1110", F_g, F_l, F_t, F_1)); */
/* 	_F_(!ft_strcmp(opt, "colour"), ft_flag_set(flags, 2, "1", F_G)); */
/* 	_F_(!ft_strcmp(opt, "all"), ft_flag_set(flags, 2, "1", F_a)); */
/* 	_F_(!ft_strcmp(opt, "no-sort"), ft_flag_set(flags, 3, "11", F_f, F_a)); */
/* 	_F_(!ft_strcmp(opt, "mod-time"), ft_flag_set(flags, 2, "1", *flags)); */
/* 	_F_(!ft_strcmp(opt, "acc-time"), ft_flag_set(flags, 3, "10", F_u, F_t)); */
/* 	_F_(!ft_strcmp(opt, "reverse"), ft_flag_set(flags, 2, "1", F_r)); */
/* 	_F_(!ft_strcmp(opt, "directory"), ft_flag_set(flags, 3, "10", F_d, F_R)); */
/* 	_F_(!ft_strcmp(opt, "recursive"), ft_flag_set(flags, 3, "10", F_R, F_d)); */
/* 	return (ft_errors(E_PRINTS, opt)); */
/* } */

int		ft_flags(int  *flags, char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		F_((!argv[i][0] || argv[i][0] != '-'), i);
		_F_(!ft_strcmp(argv[i], "--"), i + 1);
		F((argv[i][0] == '-' && argv[i][1] == '-') && argv[i][2], continue);
				/* ft_lflag_check(flags, &argv[i][2])); */
		_F(argv[i][0] == '-' && argv[i][1], ___(argv[i][++j],
				ft_flag_check(flags, argv[i][j])));
		__(i);
	}
	return (i);
}
