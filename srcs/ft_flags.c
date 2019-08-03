/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/03 03:52:49 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_print_flags(t_flags *flags)
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

int	ft_set_flags(int mode, int off, int on, t_flags *flags)
{
	FT_(mode == 0, B_0(*flags, off));
	FT_(mode == 1, B_1(*flags, on));
	if (mode == 10)
	{
		if (B_IS(*flags, off))
			B_0(*flags, off);
		return (B_1(*flags, on));
	}
	if (mode == 11)
	{
		B_1(*flags, off);
		return (B_1(*flags, on));
	}
	return (1);
}

int	ft_check_flags(char flag, t_flags *flags)
{
	FT_(flag == 'l', ft_set_flags(10, F_1, F_l, flags));
	_FT(flag == '1', ft_set_flags(10, F_l, F_1, flags));
	_FT(flag == 'R', ft_set_flags(10, F_1, F_R, flags)); // check for 1 and l
	_FT(flag == 'a', ft_set_flags(1, F_0, F_a, flags));
	_FT(flag == 'r', ft_set_flags(1, F_0, F_r, flags));
	_FT(flag == 't', ft_set_flags(1, F_0, F_t, flags));
	_FT(flag == 'u', ft_set_flags(1, F_0, F_u, flags));
	_FT(flag == 'f', ft_set_flags(1, F_0, F_f, flags));
	_FT(flag == 'd', ft_set_flags(1, F_0, F_d, flags));
	_FT(flag == 'G', ft_set_flags(1, F_0, F_G, flags));
	_FT(flag == 'g', ft_set_flags(11, F_g, F_l, flags));
	return (ft_errors(E_FLAGS, &flag));
}

int			ft_flags(char **argv, t_flags *flags)
{
	int i;
	int j;
	int out;

	out = 0;
	i = 0;
	while (argv[++i])
	{
		FT_((argv[i][0] != '-'), i);
		FT_(!ft_strcmp(argv[i], "--"), i + 1);
		FT_((argv[i][0] == '-' && argv[i][1] == '-') && argv[i][2],
			(*flags = ft_error_flags(&argv[i][2])));
		if (argv[i][0] == '-' && argv[i][1])
		{
			j = 0;
			while (argv[i][++j])
				out = ft_check_flags(argv[i][j], flags);
			printf("out = %d", out);
		}
	}
	FT(i > 1, *flags |= F_M);
	ft_print_flags(flags);
	ft_putchar('\n');
	return (i);
}
