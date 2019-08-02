/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/02 15:01:47 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_ls(char *path, t_flags *flags, void (*ft_type_print)(char *path)
{
	int i;

	i = 0;
	FT(*flags == F_1, ft_def_prints("."));
	printf("%d", *flags);
		ft_type_print(path);
	// handle memory
	// handle sorting
	// handle printing
	// handle errors
	return (0);
}
