/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/24 15:54:05 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_set_flags(char *arg, t_flags *flags)
{
	size_t i = 0;
	size_t len = ft_strlen(arg);

	if (len > 1)
		FT_((arg[0] == '-' && arg[1] == '-') && arg[2],);
	while (arg[++i] && i < len)
	{
		if (arg[i] == 'l')
			ft_check_flags(F_L, flags);
		else if (arg[i] == 'R')
			ft_check_flags(F_R, flags);
		else if (arg[i] == 'a')
			ft_check_flags(F_A, flags);
		else if (arg[i] == 'r')
			ft_check_flags(F_r, flags);
		else if (arg[i] == 't')
			ft_check_flags(F_T, flags);
		else if (arg[i] == 'u')
			ft_check_flags(F_U, flags);
		else if (arg[i] == 'f')
			ft_check_flags(F_F, flags);
		else if (arg[i] == 'g')
			ft_check_flags(F_G, flags);
		else if (arg[i] == 'd')
			ft_check_flags(F_D, flags);
		else
			return (ft_error_flags(arg[i], -1));
	}
}
