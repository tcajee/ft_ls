/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:08:12 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 16:20:18 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_parses(int argc, char **argv)
{
	t_flags flags;
//	char *next;
	int i;

	flags = 0;
	i = 0;
	FT_(argc == 1, ft_ls(".", &flags));
	if (argc > 1)
	{
		while(argv[++i])
		{
			FT_(!ft_flags(argv[i], &flags), E_FLAGS);

		}
//		while (argv[++i] && next)
//			next = ft_dirs(i, argv + i);
//		ft_ls(next, &flags);
	}
	return (0);
}













