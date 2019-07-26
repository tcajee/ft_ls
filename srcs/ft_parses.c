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
	char **dirs;
	int i;

	i = 0;
	flags = 0;
	FT(!flags, ft_init_flags(&flags));
	FT_(argc < 2, ft_ls(".", &flags));
	while(argv[i] && ft_flags(argv[i], &flags))
		i++;
	FT_(!flags, E_FLAGS);
	dirs = ft_dirs(argv + i);
	while (dirs[i++])
		ft_ls(dirs[i], &flags);
	return (0);
}













