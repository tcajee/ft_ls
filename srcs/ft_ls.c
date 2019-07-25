/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/24 16:22:11 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int ft_ls(int argc, char **argv)
{
	t_flags flags;
	int		i;

	ft_parses(int argc, char **argv, t_list *flags);
	// handle flags
	i = ft_flags(argv, &flags);
	// handle dirs
	i = ft_dirs(argc, argv);
	// handle memory
	// handle printing
	// handle errors
	// handle flags
	i = ft_flags(argv, &flags);
	// handle dirs
	if (i < argc)
		i = ft_dirs(argc, argv + i);
	// handle memory
	// handle printing
	// handle errors
	return (i);
}
