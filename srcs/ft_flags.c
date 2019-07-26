/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 16:14:09 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_flags(char *arg, t_flags *flags)
{
	FT_((arg[0] != '-'), 0);
	FT_(!ft_strcmp(arg, "--"), 0);
	FT_((arg[0] == '-' && arg[1] == '-') && arg[2], 0);
	FT__(!flags, flags, ft_init_flags(flags));
	FT__((arg[0] == '-' && arg[1]), flags, ft_set_flags(arg, flags));
	return (1);
}
