/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:08:12 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 18:04:55 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_parses(int argc, char **argv)
{
	t_flags flags;
	int i;

	flags = 0;
	FT(!flags, ft_init_flags(&flags));
	FT_(argc < 2, ft_ls(NULL, &flags));
	FT_(!(i = ft_flags(argv, &flags)), E_FLAGS);
	FT_(i == argc, ft_ls(NULL, &flags));
	FT_(i < argc, ft_dirs(argv + i, &flags));
	return (0);
}













