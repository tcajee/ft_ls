/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:36:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 17:01:54 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_error_flags(char flag)
{
	ft_putstr_fd("./ft_ls: illegal option -- ", 2);
	ft_putchar_fd(flag, 2);
	ft_putendl_fd("usage: ./ft_ls [-lRartufgd] [file ...]", 2);
	perror("");
	return (0);
}
