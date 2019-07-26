/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 18:00:59 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_flags(char *arg, t_flags *flags)
{
	FT_((arg[0] != '-'), 0);
	FT_(!ft_strcmp(arg, "--"), 0);
	FT_((arg[0] == '-' && arg[1] == '-') && arg[2], (*flags = ft_error_flags(arg[2])));
	FT_((arg[0] == '-' && arg[1]), ft_set_flags(arg, flags));
	return (12);
}
