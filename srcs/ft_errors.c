/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:36:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 17:02:33 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_errors(int error)
{
	ft_putendl_fd("./ft_ls: illegal option -- ", 2);
	ft_putendl_fd("usage: ./ft_ls [-lRartufgd] [file ...]", 2);
	perror("");
	return (error);
}
