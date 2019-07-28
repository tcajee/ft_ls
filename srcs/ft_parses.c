/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:08:12 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/28 17:47:49 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_parses(int argc, char **argv)
{
	t_flags	flags;
	t_file	**dirs;
	int i;

	flags = 0;
	dirs = NULL;
	FT(!flags, ft_init_flags(&flags));
	FT_(argc == 1, ft_ls(NULL, &flags));
	FT_((i = ft_flags(argv, &flags)) < 0, E_FLAGS);
	FT_(i < argc, ft_dirs(argv + i, dirs));

	return (0);
}














