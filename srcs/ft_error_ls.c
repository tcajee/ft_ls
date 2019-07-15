/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:36:46 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 14:11:26 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_error_ls(int ERROR)
{
	if (ERROR == 99)
	{
		/* perror("./ft_ls: illegal option -- -"); */
		/* perror("usage: ./ft_ls [-lRartufgd] [file ...]"); */
		
		ft_putendl("./ft_ls: illegal option -- -");
		ft_putendl("usage: ./ft_ls [-lRartufgd] [file ...]");
	}
	return (ERROR);
}
