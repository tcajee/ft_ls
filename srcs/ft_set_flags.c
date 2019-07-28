/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/28 16:23:41 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_set_flags(char *arg, t_flags *flags)
{
	int i;

	i = 0;
	while (arg[++i])
	{
		FT(arg[i] == 'l' || arg[i] == 'g', B_01(*flags, F_1, F_l))
		else FT(arg[i] == '1', B_01(*flags, F_l, F_1))
		else FT(arg[i] == 'R', B_1(*flags, F_R))
		else FT(arg[i] == 'a', B_1(*flags, F_a))
		else FT(arg[i] == 'r', B_1(*flags, F_r))
		else FT(arg[i] == 't', B_1(*flags, F_t))
		else FT(arg[i] == 'u', B_1(*flags, F_u))
		else FT(arg[i] == 'f', B_1(*flags, F_f))
		else FT(arg[i] == 'd', B_1(*flags, F_d))
		else FT(arg[i] == 'G', B_1(*flags, F_G))
		else FT(arg[i] == 'g', B_1(*flags, F_g))
		else
			return (*flags = ft_error_flags(arg[i]));
	}
	ft_print_flags(flags);
	ft_putchar('\n');
	return (1);
}
		
/* if (arg[i] == 'l') */
		/* { */
		/* 	if (*flags & F_1) */
		/* 	{ */
		/* 		if ((*flags |= F_l)) */
		/* 		{ */
		/* 			B_0(*flags, F_1); */
		/* 		} */
		/* 	} */
		/* } */
