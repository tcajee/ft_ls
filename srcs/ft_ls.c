/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/29 15:58:37 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_ls(char *path, t_flags flags)
{
	int i;

	i = 0;
//	FT(path == "." && flags == F_1, ft_def_prints("."))
//	FT(path && flags == F_1, 
	printf("%d", flags);
	ft_def_prints(path);
	// handle memory
	// handle sorting
	// handle printing
	// handle errors
	return (0);
}
